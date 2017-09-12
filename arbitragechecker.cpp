//
//  arbitragechecker.cpp



#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#define inf 10000007
using namespace std;

struct graph{
    
    struct node{
        
        int d;
        int prev = 0;
    };
    
    int n=0, noofconnections=0;
    vector<vector<double> > dist;
    vector<node> nodes;
    
    graph(int numberofnodes, int s)
    {
        n = numberofnodes;
        noofconnections=n*n;
        dist.assign(n, vector<double>(n,inf));
        node x;
        x.d=inf;
        nodes.assign(n, x);
        nodes[s].d=0;
        
        for(int i = 0; i <noofconnections; i++)
        {
            int a=0,b=0, temp=0;
            cout<<"Enter first currency number: ";
            cin>>a;
            cout<<"Enter second currency number: ";
            cin>>b;
            cout<<"One unit of Cuurency A buys how many units of Currency B? ";
            cin>>temp;
            dist[a][b]=-1*log(temp);
        }
    }
    
    void relax(int u, int v)
    {
        if(nodes[v].d> (nodes[u].d + dist[u][v]))
        {
            nodes[v].d = (nodes[u].d + dist[u][v]);
            nodes[v].prev = u;
        }
    }
    //Bellman Ford Algorithm
    void bellmanford()
    {
        for(int i = 0; i<n-1; i++)
        {
            for(int u = 0; u<n; u++)
            {
                for(int v = 0; v<n; v++)
                {
                    relax(u, v);
                }
            }
        }
        for(int u = 0; u<n; u++)
        {
            for(int v = 0; v<n; v++)
            {
                if(nodes[v].d> (nodes[u].d+dist[u][v]))
                {
                    goto skiphere;
                }
            }
        }
        cout<<"You're good to go!";
        goto skiphere2;
    skiphere:
        cout<<"There exist descrepencies in the conversion rates.";
    skiphere2:
        cout<<"\n";
    }
};

int main()
{
    int n = 0, s = 0;
    cout<<"Enter number of nodes: "<<endl;
    cin>>n;
    graph g(n,s);
    g.bellmanford();
}
