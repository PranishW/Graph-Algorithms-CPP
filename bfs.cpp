#include <bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int,vector<int>>& g)
{
	queue<int> q;
	unordered_map<int,int> visited;
	int src;
	cout<<"Enter the source vertex :- ";
	cin>>src;
	q.push(src);
	visited[src] = 1;
	while(!q.empty())
	{
		src = q.front();
		cout<<src<<" ";
		q.pop();
		for(int i : g[src])
		{
			if(!visited[i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
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
