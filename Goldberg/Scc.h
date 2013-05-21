#ifndef SCC_
#define SCC_

#include "Graph.h"
#include "NodeArray.h"
#include<stack>
#include<vector>
#include<set>

using namespace std;

class Scc
{
    public:
        Scc(Graph &graph);
        void findAll();
        void find(node v);
        void topOrder();
        void negativeCycle();
        int getSccNumber(node v);
        
    private:
        Graph &m_graph;
        stack <node> m_stack;
        vector <int> m_scc_position;
        vector <node> m_top_order;
        NodeArray <int> m_on_stack;
        NodeArray <int> m_scc; // m_scc[node]=scc_number(node);
        NodeArray <int> m_index;
        NodeArray <int> m_low;
        int m_id;
        int m_scc_number;
        NodeArray <int> m_dfs_colour; // 0 - white, 1 - grey, 2 - black
        
};
#endif
