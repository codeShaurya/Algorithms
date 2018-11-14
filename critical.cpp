#include <bits/stdc++.h>
using namespace std;

int dfs(int root, vector<int> &vis, vector<vector<pair<int, int>>> &G, stack<int> &s)
{
  vis[root] = 1;
  for (int i = 0; i < G[root].size(); i++)
  {
    if (!vis[G[root][i].first])
      dfs(G[root][i].first, vis, G, s);
  }
  s.push(root);
}
int main()
{
  int a;
  int n, e;
  cin >> n >> e;
  vector<vector<pair<int, int>>> G(n + 1);
  for (int i = 0; i < e; i++)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    G[from].push_back({to, -1 * weight});
  }
  stack<int> topo;
  vector<int> vis(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
      dfs(i, vis, G, topo);
  }
  vector<int> sorted;
  while (!topo.empty())
  {
    sorted.push_back(topo.top());
    topo.pop();
  }
  vector<int> minDist(n + 1, INT_MAX - 1000);
  int from;
  cin >> from;
  vector<int> parent(n + 1, -1);
  for (int i = 0; i < sorted.size(); i++)
  {
    if (sorted[i] == from)
    {
      minDist[sorted[i]] = 0;
    }
    for (int j = 0; j < G[sorted[i]].size(); j++)
    {
      if (minDist[sorted[i]] + G[sorted[i]][j].second < minDist[G[sorted[i]][j].first])
      {
        parent[G[sorted[i]][j].first] = sorted[i];
        minDist[G[sorted[i]][j].first] = minDist[sorted[i]] + G[sorted[i]][j].second;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (minDist[i] == INT_MAX - 1000)
    {
      cout << "Reaching to " << i << " is not possible" << endl;
    }
    else
    {
      cout << "Reaching to " << i << " will take distance:- " << minDist[i] << " " << endl;
      int j = i;
      cout << i << " ";
      while (parent[j] != -1)
      {
        cout << parent[j] << " ";
        j = parent[j];
      }
      cout << endl;
    }
  }
}
