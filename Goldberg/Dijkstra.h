#ifndef DIJKSTRA_
#define DIJKSTRA_
/* algorytm Dijkstry jako parametr wczytuje graf z wagami >= 0
 * i wykonuje algorytm SSSP z zadanego zrodla s.
 */
 
class Dijkstra{

public:
	//konstruktor z zadana referencja do grafu oraz zrodlem (default NULL)
	Dijkstra(Graph& G, node source = 0);
	
	//byc moze bedziemy chcieli miec tylko jeden obiekt Dijkstra ktory
	//dla roznych grafow bedize wykonywac algorytm SSSP. Dlatego
	//warto zapewnic metode ktora pozwala "zrestartowac" algorytm
	//Dijkstry.
	void reaload(G, node source = 0);
	
	//ta funkcja ma zwracac referencje do tablicy z wartosciami 
	//najkrotszych sciezek dla wierzcholkow G.
	NodeArray < int > & getD(){
		return m_d;
	}
	
	//ta funkcja ma zwracac referencejt o tablicy z poprzednikami
	//w najkrotszych sciezkach
	NodeArray < int > & getPreds(){
		return m_preds;
	}

private:

	//kopiec uzyty w trakcie dzialania algorytmu dijkstry\
	//kluczem sa aktualne najkrotsze odleglosci, wartosciami: wskazniki
	//na wierzcholki
	BinaryHeap < int, node > m_heap;
	
	//tablica przechowujaca wynik algorytmu: wartosci najkrotszych 
	//sciezek
	NodeArray < int > m_d;
	
	//tablica przechowujaca wynik algorytmu: wskaznik na poprzednika
	//w najkrotszej sciezce
	NodeArray < node > m_preds;
};
#endif
