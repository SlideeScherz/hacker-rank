#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int greatestInt(int a, int b, int c, int d) {
  
  int arr[4] = {a, b, c, d};
  int *max = arr; // head of array ptr
  
  // Loop to store largest number to arr[0]
  for(int i = 0; i < 4; ++i) {
    if(*max < arr[i]) {
      *max = arr[i];
    } 
  } 

  return *max;
}


int main() {
  
  int a,b,c,d;
  cin >> a >> b >> c >> d; 
  
  cout << greatestInt(a, b, c, d) << endl;
  
  return 0;
}
