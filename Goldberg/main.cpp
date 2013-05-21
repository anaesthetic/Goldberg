#include "Scc.h"
using namespace std;

int main()
{
    Graph g(6, 30);
    //g.newEdge(0,2,0);
    //g.newEdge(0,1,0);
    //g.newEdge(2,3,0);
    //g.newEdge(3,0,0);
    //g.newEdge(3,1,0);
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
    getchar();
    return 0;
}
