#include <bits/stdc++.h>
#include <stack>
#define NODE 6
#define INF 9999

using namespace std;

int cost[NODE][NODE] = {
    {0, 5, 3, INF, INF, INF},
    {INF, 0, 2, 6, INF, INF},
    {INF, INF, 0, 7, 4, 2},
    {INF, INF, INF, 0, -1, 1},
    {INF, INF, INF, INF, 0, -2},
    {INF, INF, INF, INF, INF, 0}};

void topoSort(int u, bool visited[], stack<int> &stk)
{
  visited[u] = true;
  for (int v = 0; v < NODE; v++)
  {
    if (cost[u][v])
    {
      if (!visited[v])
        topoSort(v, visited, stk);
    }
  }

  stk.push(u);
}

void shortestPath(int start)
{
  stack<int> stk;
  int dist[NODE];

  bool vis[NODE];
  for (int i = 0; i < NODE; i++)
    vis[i] = false;

  for (int i = 0; i < NODE; i++)
    if (!vis[i])
      topoSort(i, vis, stk);

  for (int i = 0; i < NODE; i++)
    dist[i] = INF;
  dist[start] = 0;

  while (!stk.empty())
  {
    int nextVert = stk.top();
    stk.pop();

    if (dist[nextVert] != INF)
    {
      for (int v = 0; v < NODE; v++)
      {
        if (cost[nextVert][v] && cost[nextVert][v] != INF)
        {
          if (dist[v] > dist[nextVert] + cost[nextVert][v])
            dist[v] = dist[nextVert] + cost[nextVert][v];
        }
      }
    }
    for (int i = 0; i < NODE; i++)
      (dist[i] == INF) ? cout << "Infinity " : cout << dist[i] << " ";
  }
}

int main()
{
  int start = 1;
  cout << "Shortest Distance From Source Vertex " << start << endl;
  shortestPath(start);
  return 0;
}