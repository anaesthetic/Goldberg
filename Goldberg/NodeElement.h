#ifndef GOLDBERG_NODE_ELEMENT_
#define GOLDBERG_NODE_ELEMENT_

#include <iostream>

#include "GraphTypedefs.h"
#include "EdgeElement.h"

class NodeElement{

public:

	friend class EdgeElement;
	friend class Graph;

	NodeElement(int id = 0): m_id(id), m_isHidden(false), m_pred(0), 
							 m_succ(0), m_firstEdge(0), m_firstInEdge(0){
	}
	
	~NodeElement();
	
	int getId(){
		return m_id;
	}
	
	void setId(int id){
		m_id = id;
	}
	
	//zwraca wskaznik do pierwszej krawedzi na liscie "wychodzacych"
	//z wierzcholka
	edge getFirstEdge(){
		return m_firstEdge;
	}
	
	// zwraca wskaznik do pierwszej krawedzi na liscie "wchodzacych"
	// do wierzcholka.
	edge getFirstInEdge(){
		return m_firstInEdge;
	}
	
	// nastepny wierzcholek w Grafie
	node getNext(){
		return m_succ;
	}
	
	// poprzedni wierzcholek w Grafie
	node getPrev(){
		return m_pred;
	}
	
	// czy wierzcholek jest niewidoczny
	bool isHidden(){
		return m_isHidden;
	}
	
	// ustaw czy niewidoczny
	bool setIsHidden(bool isHidden){
		m_isHidden = isHidden;
	}
	
	// drukuje id wierzcholka na standard. wyjscie v.id
	// przyklad: cout << v
	friend std::ostream& operator << ( std::ostream& stream, NodeElement &v);

private:

	bool m_isHidden;
	int m_id; 
	node m_succ;
	node m_pred;
	edge m_firstEdge;
	edge m_firstInEdge;
};
#endif
