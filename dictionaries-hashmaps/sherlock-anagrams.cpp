#include <bits/stdc++.h>

#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

map<int, int> stringToAsciiMap(string strIn)
{
  int ascii;      // char to ascii
  int occurances; // temp occurances for this ascii key

  // ascii map of ascii letter (key), and its occurances (value)
  map<int, int> resMap;

  for (int i = 0; i < strIn.length(); i++)
  {
    ascii = int(strIn.at(i)); // get ascii value
    occurances = 1;           // reset occurances to default

    // check if key exists
    if (resMap.count(ascii) == 1)
    {
      occurances = resMap.at(ascii); // get element of occurances
      resMap.erase(ascii);           // erase old
      occurances++;                  // inc occurances
    }

    // if it doesnt exist, occurances will be one, or will update the previous entry
    resMap.emplace(ascii, occurances);
  }

  // prints the elements
  cout << "KEY\tOCCURANCES\n";
  for (auto itr = resMap.begin(); itr != resMap.end(); itr++)
  {
    cout << itr->first << '\t' << itr->second << '\n';
  }

  return resMap;
}

/**
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * @param s input string.
 * @returns integer number of anagrams in the string.
 */
int sherlockAndAnagrams(string s)
{
  int pairs = 0; // result obj

  cout << s << " input\n";

  // REMEBER THE CONSTRAINTS
  // S will always be longer than 2.
  // Split each word in half, and whatever letters are the same use those to try and match the first word
  // Re do this and increment pairs for each sucessful match

  // ascii map of ascii letter (key), and its occurances (value)
  map<int, int> aMap = stringToAsciiMap(s);

  return pairs;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++)
  {
    string s;
    getline(cin, s);

    int result = sherlockAndAnagrams(s);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
