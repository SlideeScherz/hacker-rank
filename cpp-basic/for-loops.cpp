#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// english numbers
string numbers[] = {
  "one", "two","three", "four", "five",
  "six", "seven", "eight", "nine"
  };
  
/** Returns string if n is even or odd */  
string isEven(int n) { return (n % 2 == 0) ? "even" : "odd"; }  
  
void numberTranslate(int n1, int n2) 
{  
  for(int i = n1; i <= n2; i++)
  { 
    if(i <= 9) cout << numbers[i-1] << endl;
    else if(i > 9) cout << isEven(i) << endl;
  }
}  

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  int n1, n2;
  cin >> n1;
  cin >> n2;
  
  numberTranslate(n1, n2);
  
  return 0;
}
