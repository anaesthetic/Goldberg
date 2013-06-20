#include "Layers.h"
GoldbergLayers::GoldbergLayers(Graph & graph, NodeArray < int > & distances, NodeArray <int> &scc)
{
    //m_layers.resize();
    m_graph = graph;
    m_layers.resize(m_graph.getNodesNumber());
    m_scc_counter.resize(m_graph.getNodesNumber());
    vector <bool> visited_scc;
    visited_scc.resize(m_graph.getNodesNumber(),false);
    for ( node n= m_graph.getFirstNode(); n!=0; n=n->getNext())
    {
        if(visited_scc[scc[n]]==false)
        {
            visited_scc[scc[n]]=true;
            m_scc_counter[-(distances[n])]++;
        }
        m_layers[-(distances[n])].push_back(n);
    }
}
int GoldbergLayers::getMaxNotEmptyBucket()
{
    for(int i=m_layers.size()-1; i>=0; i--)
        if(!m_layers[i].empty())
            return i;
}
