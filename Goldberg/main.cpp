#include "Topologic.h"
using namespace std;

int main()
{
    Graph g(60, 30);
    /*
    g.newEdge(0,1,0);
    g.newEdge(0,5,0);
    g.newEdge(1,2,0);
    g.newEdge(2,0,0);
    g.newEdge(2,3,0);
    g.newEdge(3,5,0);
    g.newEdge(4,3,0);
    g.newEdge(5,4,0);
    */
    
    cout<<g;
    Scc s(g);
    s.findAll();
    node v=g.getFirstNode();
    while(v!=0)
    {
        cout<<v->getId()<< ": "<<s.getSccNumber(v)<<endl;
        v=v->getNext();
    }
    s.topOrder();
    
    TopologicSSSP t(g);
    cout<<t.checkIfTopologicOrder(s.m_top_order, s.m_scc);
    
    getchar();
    return 0;
}
