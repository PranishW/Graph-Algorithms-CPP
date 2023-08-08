// Dijktra's Shortest Path Algorithm for weighted Graph
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,vector<pair<int,int>>> g;
    int e,v;
    cout<<"Enter vertices:-";
    cin>>v;
    cout<<"Enter edges:-";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"Enter vertex1 and vertex2 and edge weight :-";
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> dist(v,INT_MAX);
    set<pair<int,int>> st;      // {distance,node}
    int source;
    cout<<"Enter source vertex :-";
    cin>>source;
    dist[source] = 0;
    st.insert({0,source});
    while(!st.empty())
    {
        // fetch top pair
        auto top = *(st.begin());
        int Nodedist = top.first,Topnode = top.second;
        st.erase(st.begin());    // removing top pair
        for(auto ng: g[Topnode])
        {
            if(Nodedist+ng.second<dist[ng.first])
            {
                auto record = st.find({dist[ng.first],ng.first}); // search record of node in the set 
                // if record found delete the pair
                if(record!=st.end())    // record found
                    st.erase(record);
                dist[ng.first] = Nodedist + ng.second; // update dist vector with shorter distance
                st.insert({dist[ng.first],ng.first});  // insert updated pair 
            } 
        }
    }
    cout<<"Distance of each vertex from "<<source<<" vertex is :- ";
    for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
    return 0;
}
