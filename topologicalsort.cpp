
#include<bits/stdc++.h>
#define max_nodes 100001
using namespace std;

vector<int> og[max_nodes];
bool visited[max_nodes];
bool wS[max_nodes];
bool gS[max_nodes];
bool iS[max_nodes];

stack<int> startTime;
int cycle=0;
void DFScheck(int source)
{
	visited[source]=true;
	iS[source]=false;
	gS[source]=true;
	for(int i=0;i<og[source].size();i++)
		{
			if(wS[og[source][i]]==false && gS[og[source][i]]==true)
			cycle=1;
			else if(wS[og[source][i]]==false && gS[og[source][i]]==false)
			{
				DFScheck(og[source][i]);
			}
		}
	gS[source]=false;
	wS[source]=true;
}

void DFS(int source)
{
	visited[source]=true;
	for(int i=0;i<og[source].size();i++)
		if(!visited[og[source][i]])
			DFS(og[source][i]);
	startTime.push(source);
}

int main()
{
	int n,m,i,a,b;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		iS[i]=true;
		wS[i]=false;
		gS[i]=false;
	}
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;b--;
		og[a].push_back(b);
	}
	
	for(i=0;i<n;i++)
	visited[i]=false;
	
	for(i=0;i<n;i++)
	if(visited[i]==false)
	DFScheck(i);
	if(cycle==1)
	{
		cout<<"Sandro fails.\n";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		sort(og[i].begin(),og[i].end(),greater<int>());
		visited[i]=false;
	}
	
	for(i=n-1;i>=0;i--)
	if(visited[i]==false)
	DFS(i);
	while(!startTime.empty())
	{
		cout<<startTime.top()+1<<" ";
		startTime.pop();
	}
}
