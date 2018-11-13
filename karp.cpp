//Done

#include <bits/stdc++.h>
using namespace std;

bool match(string p, string t, int s)
{
  for (int i = 0; i < p.length(); i++)
  {
    if (p[i] != t[i + s])
      return false;
  }
  return true;
}

int main()
{
  string p, t;
  cout << "enter text :";
  cin >> t;
  cout << "enter pattern :";
  cin >> p;
  int l = p.length();
  int h = 0;
  int r = 0;
  int m = 1;
  if (l > t.length())
  {
    cout << "pattern not found in the text ";
    return 0;
  }
  for (int i = 0; i < l; i++)
  {
    h = h * 26 + (p[i] - 'a');
    r = r * 26 + (t[i] - 'a');
    m = m * 26;
  }

  vector<int> v;
  if (h == r)
  {
    bool ans = match(p, t, 0);
    if (ans)
      v.push_back(0);
  }

  for (int i = l; i < t.length(); i++)
  {
    r = r * 26 - m * (t[i - l] - 'a') + (t[i] - 'a');
    if (h == r)
    {
      bool ans = match(p, t, i - l + 1);
      if (ans)
        v.push_back(i - l + 1);
    }
  }
  cout << "total match of pattern is " << v.size() << endl;
  cout << "and the index arr : " << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " to " << v[i] + l - 1 << endl;

  return 0;
}
