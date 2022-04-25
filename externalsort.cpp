#include <bits/stdc++.h>
using namespace std;

int primary_sort(int i, int n, int ar[], int r, int b)
{
  int end = min(i + (r * b), n);
  sort(ar + i, ar + end);
  return min(b, n);
}

void externalsort(int b, int r, int n, int ar[])
{
  int IO = 0, runsize = b, passnum = 0;
  while (1)
  {
    for (int i = 0; i < n; i += r * b)
    {
      int x = primary_sort(i, n, ar, r, runsize);
      IO += 2 * x;
    }
    cout << passnum << " " << runsize << " " << IO << endl;
    if (runsize >= n)
      break;
    runsize *= 2;
    // pnum
    passnum++;
  }
}

bool isSorted(int ar[], int n)
{
  for (int i = 1; i < n; i++)
  {
    if (ar[i - 1] > ar[i])
      return false;
  }
  return true;
}

void print(int n, int ar[])
{
  for (int i = 0; i < n; i++)
  {
    cout << ar[i] << endl;
  }
}

int main()
{
  int b, r, n;
  cin >> b >> r >> n;
  int ar[n];
  for (int i = 0; i < n; i++)
  {
    cin >> ar[i];
  }
  cout << 2 * n * (ceil(log(min(n, b)) / log(b - 1)) + 1) << endl;
  externalsort(b, r, n, ar);
  // cout << isSorted(ar,n) << endl;
  // print(n, ar);

  return 0;
}