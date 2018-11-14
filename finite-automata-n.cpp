#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

void computeTransFun(string pat, int M, int TF[][NO_OF_CHARS])
{
  int i, lps = 0, x;

  for (x = 0; x < NO_OF_CHARS; x++)
    TF[0][x] = 0;
  TF[0][pat[0]] = 1;

  for (i = 1; i <= M; i++)
  {

    for (x = 0; x < NO_OF_CHARS; x++)
      TF[i][x] = TF[lps][x];

    TF[i][pat[i]] = i + 1;

    if (i < M)
      lps = TF[lps][pat[i]];
  }
}

void search(string pat, string txt)
{
  int M = pat.length();
  int N = txt.length();

  int TF[M + 1][NO_OF_CHARS];

  computeTransFun(pat, M, TF);

  int i, j = 0;
  for (i = 0; i < N; i++)
  {
    j = TF[j][txt[i]];
    if (j == M)
    {
      printf("\n pattern found at index %d", i - M + 1);
    }
  }
}

int main()
{
  string txt, pat;
  cout << "Enter the pattern : ";
  cin >> pat;
  cout << "Enter the string ";
  cin >> txt;
  search(pat, txt);
  return 0;
}
