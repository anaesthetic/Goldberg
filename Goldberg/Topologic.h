#ifndef GOLDBERG_TOPOLOGIC_SSSP_
#define GOLDBERG_TOPOLOGIC_SSSP_

#include "NodeElement.h"
#include "EdgeElement.h"
//#include "NodeArray.h"
//#include "Graph.h"
#include "Scc.h"

#include <vector>
#include <stack>


#define WEIGHT_BOUND 0
#define DIST_INIT 0
 
class TopologicSSSP{

public:

	TopologicSSSP(Graph& G);
	
	void computeSSSP(const std::vector<node> &topSortArray, NodeArray<int> &sccArray);

	bool checkIfTopologicOrder(const std::vector<node> &topSortArray, NodeArray<int> &sccArray);
	
	void computePredForest(NodeArray<int> &sccArray);
	
	NodeArray < node > & getPredForest() {
		return m_predForest;
	}
	
	NodeArray < int > & getDistanceArray() { 
		return m_distanceArray;
	}
	
private:

	void resetArrays() {
		m_visited.reset(0);
		m_predForest.reset(0);
		m_distanceArray.reset(DIST_INIT);
		for(int i = 0; i < m_G.getNodesNumber(); i++) {
			m_componentDistanceArray[i] = DIST_INIT;
			m_componentPredsArray[i] = 0;
			m_componentBestArray[i] = 0;
		}
	}
	

	void relaxEdge(int sourceComponent, int targetComponent, edge e);

	NodeArray<int> m_distanceArray;
	NodeArray<int> m_visited;
	std::stack<node> m_stack;
	int m_negative_vertices;
	NodeArray < node > m_predForest;
	std::vector <int> m_componentDistanceArray;
	std::vector <node> m_componentPredsArray;
	std::vector <node> m_componentBestArray;
	Graph & m_G;
};

#endif
