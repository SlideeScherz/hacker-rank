/**
 * thank you to https://euler.stephan-brumme.com/
 * for assistance. adaptations of mine are below
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef unsigned long long u64; // unsigned long long
typedef unsigned int uInt16;    // unsigned int

// recursively count solutions
u64 count(
    uInt16 digits,
    bool haveAny = false,
    bool haveZero = false,
    bool haveOne = false,
    bool haveA = false)
{

  /* base cases */
  // case 1. solved ?
  if (haveZero && haveOne && haveA && digits < 15)
    return 1ULL << (4 * digits); // same as pow(16, digits);

  // case 2. processed all digits ? (but no combination of 0, 1, A found)
  if (digits == 0)
    return 0;

  // assume current digit is not 0, 1 or A
  u64 next = count(digits - 1, true, haveZero, haveOne, haveA);

  u64 result = 13 * next;

  // try to use a zero (only allowed if already have any non-zero digit => "no leading zero")
  result += haveZero ? next : count(digits - 1, haveAny, haveAny, haveOne, haveA);

  // try to use 1
  result += haveOne ? next : count(digits - 1, true, haveZero, true, haveA);

  // try to use A
  result += haveA ? next : count(digits - 1, true, haveZero, haveOne, true);

#ifndef ORIGINAL
  result %= 1000000007ULL;
#endif

  return result;
}

int main()
{
  // read stdin and store in input
  unsigned int input;
  cin >> input;

  // count number of solutions and send sto stdout
  cout << count(input) << endl;

  return 0;
}
