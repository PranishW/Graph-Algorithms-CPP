#include<bits/stdc++.h>
using namespace std;
void BFA(int n,int e,vector<vector<int> >& edges,int src)
{
	vector<int> dist(n+1,INT_MAX);
	dist[src] = 0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<edges.size();j++)
		{
			int u = edges[j][0];
			int v = edges[j][1];
			int w = edges[j][2];
			if(dist[v]>dist[u]+w)
				dist[v] = dist[u] + w;
		}
	}
	bool isNegativecycle = false;		// to detect negative cycle in graph
	for(int j=0;j<edges.size();j++){
        int u=edges[j][0];
        int v=edges[j][1];
    	int w=edges[j][2];
		if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w){   
            dist[v] = dist[u] + w;
            isNegativecycle = true;
        }
    }
    if(isNegativecycle)
       cout<<"Negative Cycle Present"<<endl;
    else{
       for(int i=1;i<n+1;i++)
    		cout<<dist[i]<<" ";
        cout<<endl;
    }
}
int main()
{
	int n,e;
	cout<<"Enter the no of vertices and edges :-";
	cin>>n>>e;
	vector<vector<int> > edges;
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cout<<"Enter vertex1, vertex2 and edge weight :- ";
		cin>>u>>v>>w;
		vector<int> a;
		a.push_back(u);
		a.push_back(v);
		a.push_back(w);
		edges.push_back(a);
	}
	int src;
	cout<<"Enter source vertex :- ";
	cin>>src;
	BFA(n,e,edges,src);
	return 0;
}
