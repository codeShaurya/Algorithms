#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;

vector<pair<int, int> > Graph[10001];
bool visited[10001];
int dist[10001];

int minD(int v)
{
	int i,min_index,minDistance=INT_MAX;
	for(i=1;i<=v;i++)
	if(!visited[i] && dist[i]<=minDistance)
	minDistance=dist[i],min_index=i;
	return min_index;
}

void Dijistra(int source,int v)
{
	dist[source]=0;
	//visited[source]=true;
	for(int i=0;i<v-1;i++)
	{
		int u=minD(v);
		visited[u]=true;
		for(int j=0;j<Graph[u].size();j++)
		{
			if(!visited[Graph[u][j].first])
			{
				dist[Graph[u][j].first]=min(dist[Graph[u][j].first],dist[u]+Graph[u][j].second);
			}
		}
	}
	cout<<endl;
	for(int i=2;i<=v;i++)
	cout<<dist[i]<<" ";
}

int main()
{
	ios::sync_with_stdio(0);
	ll n,m,i,a,b,w;
	cin>>n>>m;
	memset(visited,false,sizeof(visited));
	for(i=0;i<=n;i++)
	dist[i]=INT_MAX;
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		Graph[a].push_back(make_pair(b,w));
	}
	Dijistra(1,n);
}
