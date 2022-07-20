#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void absSumAndDiff(int *a, int *b)
{
  int sum = *a + *b;
  int absDiff = *a - *b > 0 ? *a - *b : -(*a - *b);
  cout << sum << endl;
  cout << absDiff << endl;
}

int main() {
  
  int a,b;
  cin >> a >> b;
  
  int &aPtr = a;
  int &bPtr = b;
  
  absSumAndDiff(&aPtr, &bPtr);
  
  return 0;
}
