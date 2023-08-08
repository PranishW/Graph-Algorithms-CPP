#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>>&g,unordered_map<int,int>&visited,int src)
{
	visited[src] = 1;
	cout<<src<<" ";
	for(int i:g[src])
	{
		if(!visited[i])
			dfs(g,visited,i);
	}	
}

int main()
{
	int n,m;
	cout<<"Enter the no of vertices and edges :- ";
	cin>>n>>m;
	unordered_map<int,vector<int>>g;
	unordered_map<int,int>visited;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cout<<"Enter vertex1 and vertex2 :- ";
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int src;
	cout<<"Enter the source vertex :-";
	cin>>src;
	dfs(g,visited,src);
	return 0;
}
