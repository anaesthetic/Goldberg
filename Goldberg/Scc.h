#ifndef SCC_
#define SCC_

#include "Graph.h"
#include "NodeArray.h"
#include<stack>
#include<vector>
#include<set>
using namespace std;

#define ACTIVE_EDGE_WEIGHT_BOUND 0
#define UNVISITED 0
#define VISITED 1
#define PROCESSED 2
class Scc
{
    public:
        Scc(Graph &graph);
        void findAll();
        void find(node v);
        void topOrder();
        void negativeCycle();
        int getSccNumber(node v);
        NodeArray <int> m_scc; // m_scc[node]=scc_number(node);
        vector <node> m_top_order;
        
    private:
        Graph &m_graph;
        stack <node> m_stack;
        vector <int> m_scc_position;
        
        NodeArray <int> m_on_stack;
        
        NodeArray <int> m_index;
        NodeArray <int> m_low;
        int m_id;
        int m_scc_number;
        NodeArray <int> m_dfs_colour; // 0 - white, 1 - grey, 2 - black
        
};
#endif
