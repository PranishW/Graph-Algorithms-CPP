#include <bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int,vector<int>>& g)
{
	queue<int> q;
	unordered_map<int,int> visited,parent;
	int src,dest;
	cout<<"Enter the source vertex :- ";
	cin>>src;
	cout<<"Enter the dest vertex :- ";
	cin>>dest;
	q.push(src);
	visited[src] = 1;
	parent[src]=-1;
	while(!q.empty())
	{
		int node = q.front();
// 		cout<<src<<" ";
		q.pop();
		for(int i : g[node])
		{
			if(!visited[i])
			{
				visited[i] = 1;
				parent[i] = node;
				q.push(i);
			}
		}
	}
	int currNode = dest;
	vector<int> rev;
	rev.push_back(currNode);
	while(currNode!=src)
	{
	    rev.push_back(parent[currNode]);
	    currNode = parent[currNode];
	}
	reverse(rev.begin(),rev.end());
	for(int i:rev)
	    cout<<i<<" ";
	    
}

int main()
{
	int n,m;
	cout<<"Enter the no of vertices and edges :- ";
	cin>>n>>m;
	unordered_map<int,vector<int>> g;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cout<<"Enter vertex1 and vertex2 :- ";
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(g);
	return 0;
}
