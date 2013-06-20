#ifndef GOLDBERG_
#define GOLDBERG_

#include "Graph.h"
#include "NodeArray.h"
#include "EdgeArray.h"
using namespace std;
// za konstruktor klasa Goldberg pobiera graf i kopiuje go (modyfikacje
// dokonywane beda tylko na kopii). Aby utrzymac lacznosc miedzy starymi
// a nowymi wierzcholkami i krawedziami stworzone zostaja dwie tablice
// NodeArray oraz EdgeArray (NodeArray[v] zwraca odpowiednik v w starym
// grafie, podobnie EdgeArray[e]). 
//
// Jezeli chodzi o znajdowanie SSSP (topologiczne, Diala, Dijkstry) oraz
// znadjowanie spojnych skladowych to mozemy albo tworzyc za kazdym ich
// wywolaniem nowe obiekty tego typu, albo trzymac po jednej ich instancji
// jako pola w klasie Goldberg i tylko restartowac je (np. czyscic ich tablice)
// za kazdym razem kiedy chcemy ich uzyc. Tu pogladowo bede tworzyl 
// je za kazda iteracja.

class Goldberg{

public:
	
	//m_G zostaje kopia grafu G; Od tej pory wsyzstkie obliczenia zostaja
	//wykonywane na m_G; do G wracamy tylko po to by odczytac jakies
	//pierwotne wartosci, np. pierwotne wartosci krawedzi. Robimy
	//to za pomoca tablic EdgeArray.
	//W m_G kazdy wierzcholek ma swoje unikalne ID z zakresu [1..N];
	Goldberg(const Graph & G);
	
	//powieksza dwukrotnie dana krawedz + sufit (symulacja bottom - up);
	//zastosowac operacje bitowe. Aby zajrzec  do pierwotnej wartosci
	//e (jest to potrzebne zeby wyliczyc powiekszenie) zajrzec
	//do tablicy m_edges[e];
	int promote(edge e, int round){
		int basic_weight = m_edges[e]->weight;
		int current_weight = e->weight;
		//tu operacje bitowe na basic i current_weight;
		return result; //result = 2 * basic + sufit czy jakos tam
	}
	
	//stosuje promote do kazdej krawedzi (przejscie o jedna rekurencje wyzej);
	void promoteGraph(int level);
	
	
	//znajduje i zapisujedo m_lowest najmniejsza z krawedzi
	void findLowest();
	
	//dzieli wszystkie krawedzie przez taka potege dwojki,
	//aby lowest >= -1
	void goBottom(); 
	
	
	//algorytm Goldberga
	void run(){
 		findLowest(); //znajdz minimalna krawedz
 		goBottom(); // spadamy na dno rekurencji
 		clearPotential(); //zerujemy tablice potencjalow
		for(int level = 0; level < /* tu tyle ile potrzeba wywolan rekurencyjnych*/; level++)
		{
			//jestesmy na ustalonym levelu = k (czyli na k - tym od dolu wywolaniu rekurencyjnym)

		}
	
	}
private;
	//graf na ktorym bedizemy wykonywac obliczenia. Kopia G.
	Graph m_G;
	
	//tablica przechowujaca potencjaly. Na poczatku dla kazdego wierzcholka
	//rowna zero
	NodeArray < int > potential;
	
	//waga najmniejszej z krawedzi
	int m_lowest;
	
	NodeArray < int > m_nodes;
	EdgeArray < int > m_edges;
};

#endif
