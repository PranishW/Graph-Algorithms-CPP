// Kruskal's Algorithm to find MST
#include <bits/stdc++.h>

using namespace std;
void makeSet(vector<int>& parent,vector<int>& rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int parentNode(vector<int>& parent,int node)
{
    if(parent[node]==node)
        return node;
    return parent[node] = parentNode(parent,parent[node]);  // path compression
}
void unionSet(vector<int>& parent,vector<int>& rank,int u,int v)    // merging two disjoint sets
{
    u = parentNode(parent,u);
    v = parentNode(parent,v);
    if(rank[u]<rank[v])
        parent[u] = v;
    else if(rank[u]>rank[v])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
bool cmp(vector<int>& a,vector<int>& b)
{
    return a[2]<b[2];
}
int main()
{
    int e,v,minweight=0;
    cout<<"Enter vertices:-";
    cin>>v;
    cout<<"Enter edges:-";
    cin>>e;
    vector<vector<int>> edges; 	// no adjacency list
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"Enter vertex1 and vertex2 and edge weight :-";
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(v),rank(v);
    makeSet(parent,rank,v);  // make individual nodes as disjoint sets
    for(int i=0;i<e;i++)
    {
        int u = parentNode(parent,edges[i][0]);
        int v = parentNode(parent,edges[i][1]);
        if(u!=v)
        {
            minweight+= edges[i][2];
            unionSet(parent,rank,u,v);  // merge/union of 2 disjoint sets
        }
    }
    cout<<"MST with minimum weight = "<<minweight;
    return 0;
}
