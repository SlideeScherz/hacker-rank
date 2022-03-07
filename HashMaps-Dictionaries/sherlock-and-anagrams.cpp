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
  map<int, int> m1, m2;

  for (int i = 0; i < s.length(); i++)
  {

    int occurances = 1;
    int ascii = int(s.at(i));

    cout << m1.count(ascii) << endl;

    if (m1.count(ascii))
    {
      occurances = 2;
      cout << "TRUE!" << endl;
    }

    m1.emplace(ascii, occurances);
  }

  // prints the elements
  cout << "KEY\tOCCURANCES\n";
  for (auto itr = m1.begin(); itr != m1.end(); ++itr)
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
