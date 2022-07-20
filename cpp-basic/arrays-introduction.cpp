#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

  int len;
  
  // init len after its read!
  cin >> len;
  int arr[len];
  
  // fill while cin has more elems
  for (int i = 0; i < len; i++)
    cin >> arr[i];
  
  // print reverse order  
  for (int i = len - 1; i >= 0; i--)
    cout << arr[i] << " ";
  return 0;
}
