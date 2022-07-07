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
  
string isEven(int n)
{
  return (n % 2 == 0) ? "even" : "odd";
}  
  
void numberTranslate(int n) 
{  
  for(int i = 0; i < 10; i++)
  { 
    if(n <= i) cout << numbers[i-1] << endl;
    else if(n > 9) cout << isEven(i) << endl;
  }
  cout << "done\n";
}  

int main() {
  /* Enter your code here. 
  Read input from STDIN. Print output to STDOUT */
  
  int n1, n2;
  cin >> n1;
  cin >> n2;
  
  numberTranslate(n1);
  numberTranslate(n2);

  return 0;
}