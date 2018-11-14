#include <iostream>
using namespace std;
int t1[20], t2[20];
int min(int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}
int fun(int a[][2], int t[][2], int e[2], int x[2], int n)
{
  int l1[20];
  int l2[20];
  l1[0] = 1;
  l2[0] = 2;
  t1[0] = a[0][0] + e[0];
  t2[0] = a[0][1] + e[1];
  for (int i = 1; i < n; i++)
  {
    if (t2[i - 1] + t[i][1] + a[i][0] <= t1[i - 1] + a[i][0])
      l1[i] = 2;
    else
      l1[i] = 1;
    t1[i] = min(t2[i - 1] + t[i][1] + a[i][0], t1[i - 1] + a[i][0]);
    if (t1[i - 1] + t[i][0] + a[i][1] <= t2[i - 1] + a[i][1])
      l2[i] = 1;
    else
      l2[i] = 2;
    t2[i] = min(t1[i - 1] + t[i][0] + a[i][1], t2[i - 1] + a[i][1]);
  }
  if (t1[n - 1] + x[0] < t2[n - 1] + x[1])
  {
    for (int i = 0; i < n; i++)
      cout << l1[i] << " ";
  }
  else
  {
    for (int i = 0; i < n; i++)
      cout << l2[i] << " ";
  }
  int p = min(t1[n - 1] + x[0], t2[n - 1] + x[1]);
  return p;
}
int main()
{
  int n;
  cin >> n;
  int a[n][2];
  int t[n][2];
  int e[2];
  int x[2];
  cout << "enter time at station" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << "enter value of station " << i << "at line j" << j << endl;
      cin >> a[i][j];
    }
  }
  cout << "enter time at diagnol crossing of station and line" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << "enter value of station " << i << "at line j" << j << endl;
      cin >> a[i][j];
    }
  }
  cout << "entry time of line 1" << endl;
  cin >> e[0];
  cout << "entry time of line 2" << endl;
  cin >> e[1];
  cout << "exit time of line 1" << endl;
  cin >> x[0];
  cout << "exit time of line 2" << endl;
  cin >> x[1];
  int l = fun(a, t, e, x, n);
  cout << "answer is" << l;
  return 0;
}
