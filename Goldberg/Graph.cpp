#include "Graph.h"
#include <map>
#include <stdlib.h>  
#include <time.h>

Graph::Graph(int nodesNumber, int randomChance): m_nodesNumber(0), m_edgesNumber(0), 
							   m_edgeIdMax(0), m_nodeIdMax(0), 
							   m_firstEdge(0), m_firstNode(0)
{
	for(int i = 0; i < nodesNumber; i++) newNode(nodesNumber - i - 1);
	srand(time(0));
	
	if(randomChance > 0 ) {
		for(int i = 0; i < nodesNumber; i++) {
			for(int j = 0; j < nodesNumber; j++){
				int k = rand()%101;
				int weight = 0;//rand()%401 - 200;
				if ( k <= randomChance && i!=j) {
					newEdge(i,j,weight);
				}
			}
		}
	}
}

Graph::Graph(const Graph &G)
{
		
}

Graph::~Graph()
{
	for(node v = m_firstNode; v != 0; v = v->getNext() ){
		if( v->getPrev() != 0 ) delete v->getPrev();
		if( v->getNext() == 0 ){
			delete v;
			break;
		}
	}
}

node Graph::newNode(int id)
{

	if(id == -1) id = m_nodeIdMax;
	if(m_nodeIdMax <= id) m_nodeIdMax = id + 1;
	
	node v = new NodeElement(id);
	if(m_firstNode == 0) 
		m_firstNode = v;
	else
	{
		v->m_succ = m_firstNode;
		m_firstNode->m_pred = v;
		m_firstNode = v;
	}

	m_getNodeById[id] = v;
	m_nodesNumber++;
	return v;
}


edge Graph::newEdge(node source, node target, int weight, int id)
{
	if(id == -1) id = m_edgeIdMax;
	if(m_edgeIdMax <= id) m_edgeIdMax = id+1;
	
	edge e = new EdgeElement(source, target, weight, id);
	edge sourceFirstEdge = source->m_firstEdge;
	if(sourceFirstEdge == 0)
		source->m_firstEdge = e;
	else
	{
		e->m_succ = sourceFirstEdge;
		sourceFirstEdge->m_pred = e;
		source->m_firstEdge = e;
	}
	edge targetFirstInEdge = target->m_firstInEdge;
	if(targetFirstInEdge == 0)
		target->m_firstInEdge = e;
	else
	{
		e->m_inSucc = targetFirstInEdge;
		targetFirstInEdge->m_inPred = e;
		target->m_firstInEdge = e;
	}	
	
	m_getEdgeById[id] = e;
	edge globalFirstEdge = m_firstEdge;
	if(globalFirstEdge == 0) 
		m_firstEdge = e;
	else
	{
		e->m_globalSucc = globalFirstEdge;
		globalFirstEdge->m_globalPred = e;
		e->m_globalSucc = e;
	}
	m_edgesNumber++;
	return e;
}

edge Graph::newEdge(int sourceId, int targetId, int weight, int id){
	node source = m_getNodeById[sourceId];
	node target = m_getNodeById[targetId];
	return newEdge(source,target,weight, id);
}

node Graph::getNodeById(int id){
	return m_getNodeById[id];
}

edge Graph::getEdgeById(int id){
	return m_getEdgeById[id];
}

void Graph::removeNode(node v)
{
	if(m_firstNode == v) m_firstNode = v->m_succ;
	delete v;
	m_nodesNumber--;
}

void Graph::removeNode(int id){
	removeNode(m_getNodeById[id]);
}

void Graph::removeEdge(edge e)
{
	if(m_firstEdge == e) m_firstEdge = e->m_globalSucc;
	delete e;
	m_edgesNumber--;
}

void Graph::removeEdge(int id){
	removeEdge(m_getEdgeById[id]);
}

std::ostream& operator << ( std::ostream& stream, Graph &G)
{
	stream << "\n-------\n";
	for(node v = G.m_firstNode; v != 0; v = v->getNext()){
		stream << *v << ":";
		for(edge e = v->getFirstEdge(); e != 0; e = e->getNext() ){
			if(e != v->getFirstEdge() ) stream << ", ";
			stream << *e;
		}
		stream << "\n";
	}
	stream << "-------\n";
}
