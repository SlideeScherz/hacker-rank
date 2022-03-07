#include <bits/stdc++.h>

#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int sherlockAndAnagrams(string s)
{
  // result obj
  int pairs = 0;

  cout << s << endl;

  // create hashmaps for string
  map<int, int> m1;

  for (int i = 0; i < s.length(); i++)
  {

    int ascii = int(s.at(i)); // char to ascii
    int occurances = 1;           // occurances for this ascii key

    // check if key exists
    if (m1.count(ascii) == 1)
    {
      occurances = m1.at(ascii); // get element of occurances
      m1.erase(ascii);           // erase old
      occurances++;              // inc occurances
    }
    
    m1.emplace(ascii, occurances);
  }

  //REMEBER THE CONSTRAINTS 
  //S will always be longer than 2.
  //Split each word in half, and whatever letters are the same use those to try and match the first word
  //Re do this and increment pairs for each sucessful match 

  // prints the elements
  cout << "KEY\tOCCURANCES\n";
  for (auto itr = m1.begin(); itr != m1.end(); itr++)
  {
    cout << itr->first << '\t' << itr->second << '\n';
  }

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
