//Done

#include <bits/stdc++.h>
using namespace std;
int lps[10000];
void computeLPS(string s, int l)
{
  int i = 1;
  lps[0] = 0;
  int length = 0;
  while (i < l)
  {
    if (s[i] == s[length])
    {
      length++;
      lps[i] = length;
      i++;
    }
    else
    {
      if (length != 0)
        length = lps[length - 1];
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}
int searchPatten(string t, string p)
{
  int count = 0;
  int i = 0;
  int j = 0;
  while (i < t.length())
  {
    if (t[i] == p[j])
    {
      i++;
      j++;
      cout << j << " characters matches upto index " << i - 1 << "\n";
    }
    if (j == p.length())
    {
      count++;
      cout << "match found at index " << i - p.length() << endl;
      j = lps[j - 1];
    }
    else if (i < t.length() && t[i] != p[j])
    {
      if (j != 0)
        j = lps[j - 1];
      else
      {
        i++;
      }
    }
  }
  return count;
}

int main()
{
  string t, p;
  cout << "Enter text : ";
  cin >> t;
  cout << "Enter pattern : ";
  cin >> p;
  cout << " LPS is computed \n";
  computeLPS(p, p.length());
  int ans = searchPatten(t, p);

  cout << ans << " matches found .\n";

  return 0;
}
