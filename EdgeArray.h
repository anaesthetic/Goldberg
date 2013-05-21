#include "EdgeElement.h"

/*
 * EdgeArray <T> jest tablica symboliczna przechowujaca pary <edge,T>
 * gdzie edge jest kluczem, a T wartoscia. Pozwala na dostep w czasie
 * stalym do wartosci stowarzyszonej z danym kluczem. 
 * 
 * Warunek: uzytkownik powinien zapewnic aby kazdy z przechowywanych
 * kluczy mial unikalne ID, a rozmiar tablicy byl wiekszy niz 
 * najwieksza wartosc ID stowarzyszona z kluczem.
 * 
 * Dzialanie: EdgeArray < T > opakowuje zwykla tablice T i zapewnia
 * operator EdgeArray[v] ktory utozsamia v z jej unikalna wartoscia ID
 * i zwraca wartosc tablicy m_tab w miejscu v->getId().
 */
 
template  <typename T>
class EdgeArray {
	
public:

	EdgeArray(int size): m_size(size){
		m_tab = new T[size];
	}
	
	~EdgeArray(){
		delete m_tab;
	}
	
	T& operator [](edge e){
		return m_tab[ e->getId() ]; //klucz znajdujemy po unikalnym ID 
	}
	
	const T& operator [](edge e) const{
		return m_tab[e->getId()];
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
