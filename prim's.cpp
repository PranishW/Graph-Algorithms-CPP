// Prim's Algorithm for MST
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cout<<"Enter vertices and edges :- ";
    cin>>v>>e;
    unordered_map<int,vector<pair<int,int>>> g;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // stores <edge weight,node> in pairs
	// min heap (ascending priority queue) for finding min edge weight node in less time complexity
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"Enter vertex1 and vertex2 and edge weight :-";
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> key(v,INT_MAX);    // to store weight of edge between node and its parent
    vector<int> mst(v,0);		   // if node exists in MST then mst[node] = 1
    vector<int> parent(v,-1);	   // store parent of each node
    key[0] = 0;
    pq.push({0,0});
    for(int i=0;i<v;i++)
    {
        int u,mini;
		// 	for(int j=0;j<v;j++)
		// 	{
		// 		if(mst[j]==0 and key[j]<mini)
		// 		{
		// 			u = j;
		// 			mini = key[j];
		// 		}
		//	}
		// find minimum value node from key using priority queue(min heap)
        auto p = pq.top();
        pq.pop();
        mini = p.first;
        u = p.second;
        // mark minimum value node as true in mst 
        mst[u] = 1;
        // check its adjacent nodes with mst false
        for(auto it: g[u])
        {
            if(mst[it.first]==0 and it.second<key[it.first])
            {
                key[it.first] = it.second;
                parent[it.first] = u;
                pq.push({it.second,it.first});
            }
        }
    }
    for(int i=1;i<v;i++)
        cout<<parent[i]<<"->"<<i<<" "<<key[i]<<endl;
    return 0;
}
