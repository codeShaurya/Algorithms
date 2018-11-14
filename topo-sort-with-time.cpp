//code is not working

#include <bits/stdc++.h>
using namespace std;

#define NIL -1

enum c
{
  white = -5,
  gray,
  black
};
int n;
int d[6], f[6], time;
int graph[6][6] = {{0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0}};
int color[6], pred[6];
void DFS_VISIT(int u)
{
  int v;
  color[u] = gray;
  time++;
  d[u] = time;
  for (v = 0; v < 6; v++)
  {
    if (graph[u][v] != 0)
    {
      if (color[v] == white)
      {
        pred[v] = u;
        DFS_VISIT(v);
      }
    }
  }
  color[u] = black;
  printf("%5d", u);
  f[u] = ++time;
}
int main()
{
  int i, j;
  time = 0;
  for (i = 0; i < 6; i++)
  {
    color[i] = white;
    pred[i] = NIL;
  }
  printf("The DFS traversal of the graph gives:\n");
  for (i = 0; i < 6; i++)
  {
    if (color[i] == white)
      DFS_VISIT(i); // call DFS_Visit(u)
  }
  printf("\n\nThe discovery & finishing time of the vertices are:\n");
  for (i = 0; i < 6; i++)
  {
    printf("For vertex %d\n\td[%d]=%d \tf[%d]=%d\n", i, i, d[i], i, f[i]);
  }
  int highest;
  int idx;
  printf("\n\nTopological Sort :\t", idx);
  for (j = 0; j < 6; ++j)
  {
    highest = f[j];
    for (i = 0; i < 6; ++i)
    {
      if (f[i] > highest)
      {
        highest = f[i];
        idx = i;
      }
    }
    printf("%d\t", idx);
    f[idx] = -1;
  }
  getch();
  return 0;
}