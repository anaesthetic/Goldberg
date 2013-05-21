#include "Scc.h"
#include <algorithm> //min
//miaumiau
Scc::Scc(Graph & graph): m_graph(graph), m_scc(graph.getNodesNumber()), m_index(graph.getNodesNumber()), m_low(graph.getNodesNumber()), m_on_stack(graph.getNodesNumber()), m_dfs_colour(graph.getNodesNumber())
{
    m_scc_position.resize(m_graph.getNodesNumber()+1);
    m_top_order.resize(m_graph.getNodesNumber()+1);
}
void Scc::findAll()
{
    m_id=1;
    m_scc_number=1;
    for(node n = m_graph.getFirstNode(); n != 0; n = n->getNext())
    {
        m_low[n] = -1;
        m_dfs_colour[n] = 0;
    }
    
    while(!m_stack.empty())
        m_stack.pop();
    
    node v = m_graph.getFirstNode();
    stack <node> dfs;
            
    while(v != 0)
    {
        if(m_low[v] == -1)
        {
            node w;
            dfs.push(v);
            while(!dfs.empty())
            {
                cout<<dfs.top()->getId()<<endl;
                w=dfs.top();
                if(m_dfs_colour[w] == 0)
                {
                    if(m_dfs_colour[w] == 1)
                        m_dfs_colour[w] = 2;
                    else
                    {
                        m_dfs_colour[w] = 1;
                        m_index[w] = m_id;
                        m_low[w] = m_id;
                        m_id++;
                        m_stack.push(w);
                        m_on_stack[w] = 1;
                        //cout<<dfs.top()->getId()<<"   id: "<<m_index[dfs.top()]<<endl;
                        for(edge e = w->getFirstEdge(); e != 0; e = e->getNext())
                        {    
                            if(e->getWeight() <= 0)
                            { 
                                //cout<<"LALALALAAAA"<<endl;
                                if(m_low[e->getTarget()] == -1 && m_dfs_colour[e->getTarget()] == 0)
                                {
                                    //cout<<"wrzucamy na stos: "<<e->getTarget()->getId()<<endl;
                                    dfs.push(e->getTarget());
                                }
                                else
                                {
                                    if(m_on_stack[e->getTarget()] == 1)
                                    {
                                        m_low[w] = min(m_low[w],m_low[e->getTarget()]);
                                        //cout<<"LOW["<<w->getId()<<"]="<<m_low[w]<<endl;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if(m_dfs_colour[w] == 1)
                    {
                        for(edge e = w->getFirstEdge(); e != 0; e = e->getNext())
                        {    
                            if(e->getWeight() <= 0)
                            { 
                                if(m_on_stack[e->getTarget()] == 1 && m_index[e->getTarget()] > m_index[w])
                                {
                                    m_low[w] = min(m_low[w],m_low[e->getTarget()]);
                                    //cout<<"LOW["<<w->getId()<<"]="<<m_low[w]<<endl;
                                }
                            }
                        }
                        //cout<<"przetworzony: "<<w->getId()<<"     LOW["<<w->getId()<<"]="<<m_low[w]<<endl;
                        m_dfs_colour[w] = 2;
                        
                        if(m_index[w] == m_low[w])
                        {
                            m_scc[w] = m_scc_number;
                            int count=1;
                            node top;
                            do
                            {
                                top = m_stack.top();
                                m_scc[top] = m_scc_number;
                                m_on_stack[top]=0;
                                m_stack.pop();
                                count++;
                            }    
                            while(!m_stack.empty() && top != w);
                            m_scc_position[m_scc_number]=count;
                            m_scc_number++;
                        }
                    }
                    dfs.pop();        
                }            
            }
        }
        v = v->getNext();
    }
    m_scc_position[0]=0;
    for(int i=1; i<m_scc_position.size(); i++)
    {
        m_scc_position[i]+=m_scc_position[i-1];
        m_scc_position[i]-=m_scc_position[1];
    }
}
void Scc::topOrder()
{
    vector <int> count;
    count.resize(m_graph.getNodesNumber());
    int scc_number;
    for(node n=m_graph.getFirstNode(); n!=0; n=n->getNext())
    {
        scc_number=m_scc[n];
        cout<<"!"<<m_scc_position[scc_number]<<endl;
        
        m_top_order[m_scc_position[scc_number]+count[scc_number]]=n;
        count[scc_number]++;
    }
    for(int i=0; i<m_top_order.size()-1; i++)
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
