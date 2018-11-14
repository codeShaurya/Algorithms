#include <bits/stdc++.h>
using namespace std;

#define SZ 20
int k;
main()
{
  int i, j, m, F;
  int e[3], a[SZ][SZ], t[SZ][SZ], x[3], n;
  printf("This program is for 2 line and maximum 20 station at each line.\n");
  printf("Enter number of station \n");
  scanf("%d", &n);
  printf("Enter the entry value for line 1 and line2\n");
  scanf("%d%d", &e[1], &e[2]);
  printf("Enter the assembly time for %d stations each of line1 and then of line2 \n", n);
  for (i = 1; i <= 2; i++)
  {
    for (j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);
  }
  printf("Enter the %d transfer time for %d stations each for line1 and then of line2 \n", n - 1, n);
  for (i = 1; i <= 2; i++)
  {
    for (j = 1; j < n; j++)
      scanf("%d", &t[i][j]);
  }
  printf("Enter the exit value for line 1 and line2\n");
  scanf("%d\t%d", &x[1], &x[2]);
  printf("...PLEASE WAIT...\n");
  int f[2][n], l[2][n], L;
  f[1][1] = e[1] + a[1][1];
  f[2][1] = e[2] + a[2][1];
  for (j = 2; j <= n; j++)
  {
    if (f[1][j - 1] + a[1][j] <= f[2][j - 1] + t[2][j - 1] + a[1][j])
    {
      f[1][j] = f[1][j - 1] + a[1][j];
      l[1][j] = 1;
    }
    else
    {
      f[1][j] = f[2][j - 1] + t[2][j - 1] + a[1][j];
      l[1][j] = 2;
    }
    if (f[2][j - 1] + a[2][j] <= f[1][j - 1] + t[1][j - 1] + a[2][j])
    {
      f[2][j] = f[2][j - 1] + a[2][j];
      l[2][j] = 2;
    }
    else
    {
      f[2][j] = f[1][j - 1] + t[1][j - 1] + a[2][j];
      l[2][j] = 1;
    }
  }
  if (f[1][n] + x[1] <= f[2][n] + x[2])
  {
    F = f[1][n] + x[1];
    L = 1;
  }
  else
  {
    F = f[2][n] + x[2];
    L = 2;
  }
  printf("line1\n");
  for (k = 1; k <= n; k++)
  {
    printf("%d\t", f[1][k]);
  }
  printf("\nline2\n");
  for (k = 1; k <= n; k++)
  {
    printf("%d\t", f[2][k]);
  }
  printf("\n optimal value is %d \n", F);
  printf("\n\n");
  printf("line %d ,station %d\n", L, n);
  for (j = n; j >= 2; j--)
  {
    m = l[L][j];
    printf(" line %d,station %d\n", m, j - (n - 1));
  }
  return 0;
}