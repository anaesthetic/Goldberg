#include "Layers.h"
GoldbergLayers::GoldbergLayers(Graph & graph, NodeArray < int > & distances )
{
    //m_layers.resize();
    m_graph = graph;
    m_layers.resize(m_graph.getNodesNumber());
    for ( node n= m_graph.getFirstNode(); n!=0; n=n->getNext())
    {
        m_layers[-(distances[n])].push_back(n);
    }
}
int GoldbergLayers::getMaxNotEmptyBucket()
{
    for(int i=m_layers.size()-1; i>=0; i--)
        if(!m_layers[i].empty())
            return i;
}
