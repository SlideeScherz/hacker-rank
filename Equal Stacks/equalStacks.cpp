#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
  // stacks for input params
  stack<int> st1, st2, st3;

  /* push sum of h(x) to st(x)
   * Example input  h1[3, 2, 1, 1, 1]
   * Would become  st1[8, 5, 3, 2, 1]
   * use h3, st3 as temp storage
   */
  int hItr = 0;
  st3.emplace(0);
  while (!h3.empty())
  {
    // read end of h(x), increment head by sum of tail, write to St3
    st3.emplace(st3.top() + h3.back());

    // manage memory as we parse
    h3.pop_back();

    // loop control logic. copy to h3 to call loop
    // Clear both temps, copy to stack.
    if (h3.empty() && hItr == 0)
    {
      st3.swap(st1);
      h3.swap(h1);
      hItr++;
      st3.emplace(0);
    }
    else if (h3.empty() && hItr == 1)
    {
      st3.swap(st2);
      h3.swap(h2);
      hItr++;
      st3.emplace(0);
    }
  }

  // sum each stack height for result logic
  int hSum1, hSum2, hSum3, hMax;

  // loop and pop until all sums are even
  while (true)
  {
    // read top elem, write to temp
    hSum1 = st1.top();
    hSum2 = st2.top();
    hSum3 = st3.top();

    // check success condition
    // works for empty, or equal
    if (hSum1 == hSum2 && hSum2 == hSum3)
      return hSum1;

    // read max for trim logic
    hMax = max({hSum1, hSum2, hSum3});

    // trim tallest
    if (hMax == hSum1)
      st1.pop();
    else if (hMax == hSum2)
      st2.pop();
    else if (hMax == hSum3)
      st3.pop();
    else
      return 0; // error
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
