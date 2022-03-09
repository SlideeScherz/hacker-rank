#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 * The function is expected to return an INTEGER.
 * The function accepts 3 integer vectors
 */
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
  int temp = 0; // temp buffer

  stack<int> st1;      //stack for h1 to be copied
  st1.emplace(temp);   // give default
  stack<int> st2(st1); // copy st1 constructor
  stack<int> st3(st1); // copy st1 constructor

  // reverse the input arrays to write to stacks
  reverse(h1.begin(), h1.end());
  reverse(h2.begin(), h2.end());
  reverse(h3.begin(), h3.end());

  // populate stacks with input vectors
  for (const auto &itr : h1)
    st1.emplace(st1.top() + itr);

  for (const auto &itr : h2)
    st2.emplace(st2.top() + itr);

  for (const auto &itr : h3)
    st3.emplace(st3.top() + itr);

  // loop and pop until all sums are even
  while (true)
  {
    // early break, handles empty and equal
    if (st1.top() == st2.top() && st2.top() == st3.top())
      return st1.top();

    // compare heights
    temp = max({st1.top(), st2.top(), st3.top()});

    if (st1.top() == temp)
      st1.pop();
    else if (st2.top() == temp)
      st2.pop();
    else if (st3.top() == temp)
      st3.pop();
  }
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n1 = stoi(first_multiple_input[0]);

  int n2 = stoi(first_multiple_input[1]);

  int n3 = stoi(first_multiple_input[2]);

  string h1_temp_temp;
  getline(cin, h1_temp_temp);

  vector<string> h1_temp = split(rtrim(h1_temp_temp));

  vector<int> h1(n1);

  for (int i = 0; i < n1; i++)
  {
    int h1_item = stoi(h1_temp[i]);

    h1[i] = h1_item;
  }

  string h2_temp_temp;
  getline(cin, h2_temp_temp);

  vector<string> h2_temp = split(rtrim(h2_temp_temp));

  vector<int> h2(n2);

  for (int i = 0; i < n2; i++)
  {
    int h2_item = stoi(h2_temp[i]);

    h2[i] = h2_item;
  }

  string h3_temp_temp;
  getline(cin, h3_temp_temp);

  vector<string> h3_temp = split(rtrim(h3_temp_temp));

  vector<int> h3(n3);

  for (int i = 0; i < n3; i++)
  {
    int h3_item = stoi(h3_temp[i]);

    h3[i] = h3_item;
  }

  int result = equalStacks(h1, h2, h3);

  fout << result << "\n";

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

vector<string> split(const string &str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}