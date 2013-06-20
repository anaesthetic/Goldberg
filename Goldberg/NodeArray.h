#ifndef NODE_ARRAY_
#define NODE_ARRAY_
#include "NodeElement.h"

/*
 * NodeArray <T> jest tablica symboliczna przechowujaca pary <node,T>
 * gdzie node jest kluczem, a T wartoscia. Pozwala na dostep w czasie
 * stalym do wartosci stowarzyszonej z danym kluczem. 
 * 
 * Warunek: uzytkownik powinien zapewnic aby kazdy z przechowywanych
 * kluczy mial unikalne ID, a rozmiar tablicy byl wiekszy niz 
 * najwieksza wartosc ID stowarzyszona z kluczem.
 * 
 * Dzialanie: NodeArray < T > opakowuje zwykla tablice T i zapewnia
 * operator NodeArray[v] ktora utozsamia v z jej unikalna wartoscia ID
 * i zwraca wartosc tablicy m_tab w miejscu v->getId().
 */

template  <typename T>
class NodeArray {
	
public:

	NodeArray(int size): m_size(size){
		m_tab = new T[size];
	}
	
	~NodeArray(){
		delete m_tab;
	}
	
	T& operator [](node v){
		return m_tab[ v->getId() ]; //klucz znajdujemy po unikalnym ID 
	}
	
	const T& operator [](node v) const{
		return m_tab[v->getId()];
	}
	
	
	int getSize(){
		return m_size;
	}
	
	
	void reset(const T t){
		for(int i = 0; i < m_size; i++){
			m_tab[i] = t;
		}
	}

private:
	T *m_tab;
	int m_size;
};

#endif
