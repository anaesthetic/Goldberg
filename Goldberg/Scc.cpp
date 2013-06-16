#include "Scc.h"
#include <algorithm> //min
//miaumiau
Scc::Scc(Graph & graph): m_graph(graph), m_scc(graph.getNodesNumber()), m_index(graph.getNodesNumber()), m_low(graph.getNodesNumber()), m_on_stack(graph.getNodesNumber()), m_dfs_colour(graph.getNodesNumber())
{
    m_scc_position.resize(m_graph.getNodesNumber());
    m_top_order.resize(m_graph.getNodesNumber());
}
void Scc::findAll()
{
    //inicjalizacja
    m_id=1;
    m_scc_number=0;
    for(node n = m_graph.getFirstNode(); n != 0; n = n->getNext())
    {
        m_low[n] = -1;
        m_dfs_colour[n] = UNVISITED;
    }
    while(!m_stack.empty())
        m_stack.pop();
    node v = m_graph.getFirstNode();
    stack <node> dfs;
    //
    while(v != 0)
    {
        if(m_low[v] == -1)
        {
            node w;
            dfs.push(v);
            while(!dfs.empty())
            {
                w=dfs.top();
                if(m_dfs_colour[w] == UNVISITED)
                {
                    if(m_dfs_colour[w] == VISITED)
                        m_dfs_colour[w] = PROCESSED;
                    else
                    {
                        m_dfs_colour[w] = VISITED;
                        m_index[w] = m_id;
                        m_low[w] = m_id;
                        m_id++;
                        m_stack.push(w);
                        m_on_stack[w] = true;
                        for(edge e = w->getFirstEdge(); e != 0; e = e->getNext())
                        {    
                            if(e->getWeight() <= ACTIVE_EDGE_WEIGHT_BOUND)
                            { 
                                if(m_low[e->getTarget()] == -1 && m_dfs_colour[e->getTarget()] == UNVISITED)
                                {
                                    dfs.push(e->getTarget());
                                }
                                else
                                {
                                    if(m_on_stack[e->getTarget()] == VISITED)
                                    {
                                        m_low[w] = min(m_low[w],m_low[e->getTarget()]);
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if(m_dfs_colour[w] == VISITED)
                    {
                        for(edge e = w->getFirstEdge(); e != 0; e = e->getNext())
                        {    
                            if(e->getWeight() <= ACTIVE_EDGE_WEIGHT_BOUND)
                            { 
                                if(m_on_stack[e->getTarget()] == true && m_index[e->getTarget()] > m_index[w])
                                {
                                    m_low[w] = min(m_low[w],m_low[e->getTarget()]);
                                }
                            }
                        }
                        m_dfs_colour[w] = PROCESSED;
                        
                        if(m_index[w] == m_low[w])
                        {
                            m_scc[w] = m_scc_number;
                            int count=0;
                            node top;
                        
                            do
                            {
                                top = m_stack.top();
                                m_scc[top] = m_scc_number;
                                m_on_stack[top]=false;
                                m_stack.pop();
                                count++;
                            }    
                            while(!m_stack.empty() && top != w);
                            m_scc_position[m_scc_number]=count;
                            cout<<"m_scc_position["<<m_scc_number<<"]="<<count<<endl;
                            m_scc_number++;
                        }
                    }
                    dfs.pop();        
                }            
            }
        }
        v = v->getNext();
    }
    m_scc_position.resize(m_scc_number);
    for(int i=1; i<m_scc_position.size(); i++)
    {
        cout<<i<<" th scc position - before: " <<m_scc_position[i]<<endl;
        m_scc_position[i] = m_scc_position[i] + m_scc_position[i-1];
    }
    for(int i=0; i<m_scc_position.size(); i++)
    {
        m_scc_position[i]--;
        cout<<i<<" th scc position - after: " <<m_scc_position[i]<<endl;
    }
}
void Scc::topOrder()
{
    vector <int> count;
    count.resize(m_graph.getNodesNumber(),0);
   
    int scc_number;
    for(node n=m_graph.getFirstNode(); n!=0; n=n->getNext())
    {
        scc_number=m_scc[n];
        cout<<"numer skladowej wierzcholka n: "<<n->getId()<<"   to:   "<<scc_number<<endl;
        cout<<"pozycja tego elementu: "<<m_scc_position[scc_number]-count[scc_number]<<endl;
        
        m_top_order[m_scc_position[scc_number]-count[scc_number]]=n;
        count[scc_number]++;
        //cout<<"count: "<<count[scc_number]<<endl;
    }
    for(int i=0; i<m_top_order.size()/2; i++)
    {
        node tmp=m_top_order[i];
        m_top_order[i]=m_top_order[m_top_order.size()-i-1];
        m_top_order[m_top_order.size()-i-1]=tmp;
    }
    cout<<"! wyszlismy"<<endl;
    
    for(int i=0; i<m_top_order.size(); i++)
    {
            cout<<"top "<<m_top_order[i]->getId()<<endl;
    }
    
}
void Scc::negativeCycle()
{
}
int Scc::getSccNumber(node v)
{
    return m_scc[v];
}
