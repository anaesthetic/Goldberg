#include "NodeElement.h"


NodeElement::~NodeElement()
{	
	if(m_succ != 0){
		m_succ->m_pred = m_pred;
	}
	if(m_pred != 0){
		m_pred->m_succ = m_succ;
	}
	
	for(edge e = m_firstEdge; e != 0; e = e->m_succ){
		if(e->m_pred != 0) delete e->m_pred;
		e->m_pred = 0;
		if(e->m_succ == 0){
			delete e;
			break;
		}
	}
	
	for(edge e = m_firstInEdge; e != 0; e = e->m_inSucc){
		if(e->m_inPred != 0) delete e->m_inPred;
		e->m_inPred = 0;
		if(e->m_inSucc == 0){
			delete e;
			break;
		}
	}	
}

std::ostream& operator << ( std::ostream& stream, NodeElement &v)
{
	stream << v.m_id;
}
