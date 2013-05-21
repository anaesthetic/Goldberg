#include "EdgeElement.h"
#include <assert.h>

EdgeElement::~EdgeElement()
{
	node v = m_source;
	if(m_succ != 0){
		m_succ->m_pred = m_pred;
	}
	if(m_pred != 0){
		m_pred->m_succ = m_succ;
	}
	if(m_pred == 0){
		assert(v->m_firstEdge == this); 
		v->m_firstEdge = m_succ;
	}
	
	if(m_globalSucc != 0){
		m_globalSucc->m_globalPred = m_globalPred;
	}
	if(m_globalPred != 0){
		m_globalPred->m_globalSucc = m_globalSucc;
	}
	
	v = m_target;
	if(m_inSucc != 0){
		m_inSucc->m_inPred = m_inPred;
	}
	if(m_inPred != 0){
		m_inPred->m_inSucc = m_inSucc;
	}
	if(m_inPred == 0){
		assert(v->m_firstInEdge == this);
		v->m_firstInEdge = m_inSucc;
	}
	
}

std::ostream& operator << ( std::ostream& stream, EdgeElement &e)
{
		stream << "(" << *e.m_source << "," << *e.m_target << ")";
}
