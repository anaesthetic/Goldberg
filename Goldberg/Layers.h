#ifndef GOLDBERG_LAYERS_
#define GOLDBERG_LAYERS_

#include "Graph.h"
#include "NodeArray.h"
#include "EdgeArray.h"
#include <vector>
using namespace std;
// Klasa odpowaidajaca za wyliczenie i przechowanie warstw potrzebnych
// w algorytmie Goldberga (krok po wyliczeniu spojnych skladowych)

class GoldbergLayers{

public:
	
	//w konstruktorze za parametr podana jest tablica z najkrotsyzmi
	//sciezkami wedlug ktorych maja zostac wyliczone warstwy
	GoldbergLayers(Graph &graph, NodeArray < int > & distances );
	
	//znajduje indeks najdalszego niepustego kubelka
	int getMaxNotEmptyBucket();
	
	//znajduje indeks najbardziej zapelnionego kubelka
	int getBiggestBucket();
	
	//zwraca referncje do podanego kubelka
	vector <node> & getBucketById(int id){
		return m_layers[id];
	}
	

private:

	//wskaznik na tablice N - list ( N - warstw)
	vector < vector < node > > m_layers;
	Graph m_graph;
};


#endif
