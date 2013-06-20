#include "Topologic.h"
#include "Layers.h"
using namespace std;

int main()
{
 	std::cout << "5" << endl;
    Graph g(6, 0);
    cout<<"miau"<<endl;
    g.newEdge(0,1,2);
    g.newEdge(0,5,-1);
    g.newEdge(1,2,4);
    g.newEdge(2,0,-1);
    g.newEdge(2,3,-1);
    g.newEdge(3,5,-1);
    g.newEdge(4,3,-1);
    g.newEdge(5,4,-1);
    
    
    cout<<g;
    Scc s(g);
    s.findAll();
    node v=g.getFirstNode();
    while(v!=0)
    {
        cout<<v->getId()<< ": "<<s.getSccNumber(v)<<endl;
        v=v->getNext();
    }
    cout<<"is negative cycle ? "<<s.negativeCycle()<<endl;
    s.topOrder();
    vector <node> topOrder = s.getTopOrder();
    //for(int i=0; i<topOrder.size(); i++)//node n=g.getFirstNode(); n!=0; n=n->getNext())
    //    cout<<topOrder[i]->getId()<<endl;
    
    NodeArray <int> scc = s.getScc();
    TopologicSSSP t(g);
    
    cout<<"is topologic order? "<<t.checkIfTopologicOrder(topOrder, scc)<<endl;
    
    t.computeSSSP(topOrder, scc);
    node w=g.getFirstNode();
    NodeArray <int> distanceArray = t.getDistanceArray();
    while(w!=0)
    {
        cout<<w->getId()<< ": "<<distanceArray[w]<<endl;
        w=w->getNext();
    }
    
    GoldbergLayers layers(g, distanceArray, scc);
    
    
    for(int i=0; i<g.getNodesNumber(); i++)
    {
        cout<<"bucket "<<i<<": "<<endl;
        vector <node> tmp = layers.getBucketById(i);
        for(int j=0; j<tmp.size(); j++)
            cout<<tmp[j]->getId()<<endl;
    }
    
    system("pause");
    return 0;
}
