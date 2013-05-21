#ifndef GOLDBERG_EDGE_ELEMENT_
#define GOLDBERG_EDGE_ELEMENT_


#include <iostream>

#include "GraphTypedefs.h"
#include "NodeElement.h"
#include "Graph.h"

class EdgeElement{
	
public:
	
	friend class NodeElement;
	friend class Graph;
	
	EdgeElement(node source, node target, int weight, int id = 0): 
		m_source(source), m_target(target), m_id(id), m_isHidden(false),
		m_succ(0), m_pred(0), m_globalSucc(0), m_globalPred(0), m_inPred(0),
		m_inSucc(0), m_weight(weight){
	}
	
	~EdgeElement();
	
	//wierzcholek z ktorego wychodzi krawedz
	node getSource(){
		return m_source;
	}
	
	//wierzcholek do ktorego wchodzi krawedz
	node getTarget(){
		return m_target;
	}
	
	//waga krawedzi
	int getWeight(){
		return m_weight;
	}
	
	//ustaw wage krawedzi 
	void setWeight(int weight){
		m_weight = weight;
	}

	//ustaw ID(lepiej robic to tylko w konstruktorze)
	int setId(int id){
		m_id = id;
	}
	
	//pobierz ID krawedzi
	int getId(){
		return m_id;
	}
	
	//czy niewidoczna
	bool isHidden(){
		return m_isHidden;
	}
	
	//ustaw czy niewidoczna
	void setIsHidden(bool isHidden){
		m_isHidden = isHidden;
	}
	
	//nastepna krawedz na liscie wychodzacych z wierzcholka
	edge getNext(){
		return m_succ;
	}
	
	//poprzednia krawedz na liscie wychodzacych z wierzcholka
	edge getPrev(){
		return m_pred;
	}
	
	//nastepna krawedz na liscie WCHODZACYCH do wierzcholka
	edge getInNext(){
		return m_inSucc;
	}
	
	//poprzednia krawedz na liscie WCHODZACYCH do wierzcholka
	edge getInPrev(){
		return m_inPred;
	}
	
	//nastepna krawedz na liscie GRAFU (globalna lista)
	edge getGlobalNext(){
		return m_globalSucc;
	}
	
	//poprzednia krawedz na liscie GRAFU (globalna lista)
	edge getGlobalPrev(){
		return m_globalPred;
	}
	
	//drukuje krawedz na stand. wyjscie, w postaci (source.id, target.id)
	//przyklad: cout << e
	friend std::ostream& operator << ( std::ostream& stream, EdgeElement &e);
		
private:
	
	bool m_isHidden;
	int m_id;
	int m_weight;
	node m_source;
	node m_target;
	edge m_succ;
	edge m_pred;
	edge m_globalSucc;
	edge m_globalPred;
	edge m_inPred;
	edge m_inSucc;
	
};

#endif
