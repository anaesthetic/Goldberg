#include "Topologic.h"
#include "assert.h"


TopologicSSSP::TopologicSSSP(Graph& G): 
							 m_distanceArray(G.getNodesNumber()),
							 m_visited(G.getNodesNumber()), 
							 m_predForest(G.getNodesNumber()),
							 m_G(G),
							 m_componentDistanceArray(G.getNodesNumber()),
							 m_componentPredsArray(G.getNodesNumber()),
							 m_componentBestArray(G.getNodesNumber()) {
}

void TopologicSSSP::computeSSSP( const std::vector<node> &topSortArray,
								 NodeArray<int> &sccArray) {
	resetArrays();
	assert(m_G.getNodesNumber() == topSortArray.size());
	assert(m_G.getNodesNumber() == sccArray.getSize());
	assert(checkIfTopologicOrder(topSortArray, sccArray));
	//m_componentDistanceArray[5] = 0;
    m_componentDistanceArray[m_G.getNodesNumber()] = 0;
	for(int i = 0; i < topSortArray.size(); i++) {
		node v = topSortArray[i];
		for(edge e = v->getFirstEdge(); e !=0; e = e->getNext()) {
			node u = e->getTarget();
			if(e->getWeight() <= WEIGHT_BOUND && sccArray[u] != sccArray[v] ) {
					relaxEdge(sccArray[v], sccArray[u], e);
			}
		}
	}
	for(node v = m_G.getFirstNode(); v!= 0; v = v->getNext()) {
		m_distanceArray[v] = m_componentDistanceArray[ sccArray[v] ];
	}
}

void TopologicSSSP::relaxEdge(int sourceComponent, int targetComponent, edge e) {
	if( m_componentDistanceArray[sourceComponent] + e->getWeight() < 
		m_componentDistanceArray[targetComponent]) {
			
			m_componentDistanceArray[targetComponent] = m_componentDistanceArray[sourceComponent] + e->getWeight();
			m_componentPredsArray[targetComponent] = e->getSource();
			m_componentBestArray[targetComponent] = e->getTarget();
	}
}

void TopologicSSSP::computePredForest(NodeArray<int> &sccArray) {
	//PRECONDITION: m_componentBestArray computed 
	for(node v = m_G.getFirstNode(); v!=0; v = v->getNext()) {
		int sccNumber = sccArray[v];
		if(m_visited[v] == 0 && m_componentBestArray[sccNumber] == v){
			//if v is the best(source) node in its component
			m_visited[v] = 0;
			m_stack.push(v);
			//dfs init
			while(!m_stack.empty()) {
				node w = m_stack.top();
				if(m_visited[w] == 1) {
					m_stack.pop();
				}
				else {
					m_visited[w] = 1;
					for(edge e = w->getFirstEdge(); e!=0; e = e->getNext()) {
						node z = e->getTarget();
						if(m_visited[z] == 0 && sccArray[w] == sccArray[z]) {
							m_visited[z] = 0;
							m_stack.push(z);
							m_predForest[z] = w;
						}
					}
				}
			}
		}
	}
}

bool TopologicSSSP::checkIfTopologicOrder(const std::vector<node> &topSortArray, 
										  NodeArray<int> &sccArray) {

	int size = m_G.getNodesNumber();
	NodeArray<bool> visited(size);
    visited.reset(false);
    for(int i = 0; i < size; i++)
	{
		node v = topSortArray[i];
        visited[v] = true;
        for(edge e = v->getFirstEdge(); e != 0; e = e->getNext())
		{
			node u = e->getTarget();
            if(e->getWeight() <= WEIGHT_BOUND && //jezeli to aktywna krawedz oraz
			   visited[u] == true &&  //target byl wczesniej w porzadku top oraz
 			   sccArray[u] != sccArray[v] ) // krawedz jest miedzy dwoma roznymi skladowymi
 			{
                m_negative_vertices++;
                return false;
            }
		}
	}
	return true;
}
