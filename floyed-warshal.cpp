#include <bits/stdc++.h>
using namespace std;
#define N 1000

int g[N][N];

int main()
{
  int n, i, j, k, e;
  int u, v, d;
  cin >> n >> e;

  for (k = 0; k <= n; k++)
  {
    for (i = 0; i <= n; i++)
      g[k][i] = 1000;
    //here 1000 is taken as max value
  }

  for (i = 0; i <= n; i++)
    g[i][i] = 0;

  for (i = 0; i < e; i++)
  {
    cin >> u >> v >> d;
    g[u][v] = d;
  }
  for (k = 1; k <= n; k++)
  {
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  cout << "Distance matrix\n";
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }

  cin >> u >> v;
  cout << g[u][v] << endl;
}

/*

5 8
2 1 3
5 2 4
5 4 2
1 3 6
4 3 1
3 4 2
4 2 1
1 4 3


*/
