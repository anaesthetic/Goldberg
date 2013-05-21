#ifndef GOLDBERG_GRAPH_
#define GOLDBERG_GRAPH_

#include <map>
#include <iostream>

#include "NodeElement.h"
#include "EdgeElement.h"

class Graph{

public:

	//tworzy pusty graf
	Graph(): m_nodesNumber(0), m_edgesNumber(0), m_edgeIdMax(0), m_nodeIdMax(0),
			 m_firstNode(0), m_firstEdge(0){
	}
	
	//tworzy graf z wierzcholkami ponumerowanymi od 0 do nodesNumber - 1
	Graph(int nodesNumber, int randomChance = 0);
	

	//konstruktor kopiujacy: na razie brak implementacji
	Graph(const Graph &G);
	
	//niszczy wszystkie wierzcholki i krawedzie razem z grafem
	~Graph();
	
	//czy pusty
	bool isEmpty(){
		return (m_nodesNumber == 0);
	}
	
	// zwraca liczbe wierzcholkow
	int getNodesNumber(){
		return m_nodesNumber;
	}
	
	// zwraca pierwszy  wierzcholek na liscie grafu
	node getFirstNode(){
		return m_firstNode;
	}
	
	// zwraca pierwsza krawedz na liscie grafu
	edge& getFirstEdge(){
		return m_firstEdge;
	}
	
	// zwraca liczbe krawedzi
	int getEdgesNumber(){
		return m_edgesNumber;
	}
	
	// zwraca nastepna ID ktore mozna bezpiecznie (w unikalny sposob) 
	// przydzielic nastepnemu stworoznemu wierzcholkowi
	int getNodeIdMax(){
		return m_nodeIdMax;
	}
	
	// podobnie co wyzej, dla krawedzi
	int getEdgeIdMax(){
		return m_edgeIdMax;
	}
	
	// tworzy nowy wierzcholek i zwraca wskaznik do niego
	// przy braku parametru ID przydzielany jest on automatycznie
	// wg pola getNodeIdMax()
	node newNode(int id = -1);
	
	// podobnie jak wyzej
	edge newEdge(node source, node target, int weight = 0, int id = -1);
	
	// podobnie, jak wyzej, zamiast wskaznikow na wierzchoolki incydentne
	// podajemy ich ID
	edge newEdge(int sourceId, int targetId, int weight = 0, int id = -1);
	
	// niszczy wierzcholek razem z incydentnymi krawedziami
	void removeNode(node v);
	
	// jak wyzej, tylko po ID
	void removeNode(int id);
	
	// niszczy krawedz
	void removeEdge(edge e);
	
	
	// jak wyzej, po ID
	void removeEdge(int id);
	
	
	// zwraca wskaznik do wierzcholka wg podanego ID
	node getNodeById(int id);
	
	// jak wyzej
	edge getEdgeById(int id);

	// drukuje Graf na standardowym wyjsciu
	// przyklad: cout << G
	friend std::ostream& operator << ( std::ostream& stream, Graph &G);
	
private:

	int m_nodesNumber;
	int m_edgesNumber;
	int m_nodeIdMax;
	int m_edgeIdMax;
	node m_firstNode;
	edge m_firstEdge;
	std::map<int,node> m_getNodeById;
	std::map<int,edge> m_getEdgeById;
	
};


#endif
