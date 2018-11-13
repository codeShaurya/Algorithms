#include<bits/stdc++.h>
using namespace std;
vector<int> a[100001];
bool visited[100001];

void initialize()
{
    for(int i=0;i<100001;i++)
    visited[i]=false;
}
void DFS(int s)
{
    visited[s]=true;
    for(int i=0;i<a[s].size();i++)
        if(visited[a[s][i]]!=true)
            DFS(a[s][i]);
}
int main()
{
    int n,m,temp,x,y,out=0;
    cin>>n>>m;
    temp=m;
    while(temp--)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    initialize();
    cin>>x;
    DFS(x);
    for(int i=1;i<=n;i++)
    if(visited[i]==false)
    out++;
    cout<<out;
}
