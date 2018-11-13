//Done

#include <bits/stdc++.h>
using namespace std;

int compute(int a, int b, int m)
{
  if (a == 0 || a == 1)
    return a;
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  int ans = compute(a, b / 2, m) % m;
  if (b % 2 == 0)
  {
    cout << "b is even, " << ans << "*" << ans << endl;
    return (ans * ans) % m;
  }
  else
  {
    cout << "b is odd, " << a << "*" << ans << "*" << ans << endl;
    return a * (ans * ans) % m;
  }
}

int main()
{
  int a, b, m;
  cout << "The modular exponenteion is [(a^b) mod m] \n";
  cout << "Enter the value of a, b, m : ";
  cin >> a >> b >> m;

  int ans = compute(a, b, m);

  cout << "Modular expon. is : " << ans << endl;

  return 0;
}
