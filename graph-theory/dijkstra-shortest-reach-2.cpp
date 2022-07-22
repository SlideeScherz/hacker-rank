#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
For people using c++ (std::cin, std::cout, specifically) and getting timeout on 7,
remember to turn off synchronization with the standard C stream objects:
std::ios_base::sync_with_stdio(false);
That did the trick for me (no need to change your code to scanf and printf)
*/

/*
 * Complete the 'shortestReach' function below.
 * edges are connections between nodes
 * The function accepts following parameters:
 * @param {int} n number of nodes in the graph.
 * @param {2D_INTEGER_ARRAY} edges
 * @param {int} s the starting node number
 * @return {intarray} For each of the  test cases:
 * print a single line consisting ***n-1*** space separated integers,
 * denoting the shortest distance to the ***n-1*** nodes from starting position ***s***
 * in increasing order of their labels, excluding ***s***.
 * For unreachable nodes, print ```-1```.
 */
vector<int> shortestReach(int n, vector<vector<int>> edges, int s)
{
  cout << "n: " << n << endl;
  cout << "s: " << s << endl;

  // return value
  vector<int> paths = {};

  // this index was visited
  vector<bool> visited = {};

  // init paths, 4 nodes = 3 paths!
  // set all visited to false
  for (int i = 0; i < n - 1; i++)
  {
    paths.emplace(paths.cend(), INT_MAX);
    visited.emplace(visited.cend(), false);
  }

  // start always 0
  paths[s - 1] = 0;

  // iterator for exploring
  int index, neighbor;

  index = *min_element(paths.begin(), paths.end());

  // explore all
  while (index < n)
  {
    cout << index << endl;

    neighbor = index + 1;

    // visit all neighbors that are not visited

    // reset distance, and toggle visited

    // select next node
    index++;
  }

  return paths;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++)
  {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++)
    {
      edges[i].resize(3);

      string edges_row_temp_temp;
      getline(cin, edges_row_temp_temp);

      vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

      for (int j = 0; j < 3; j++)
      {
        int edges_row_item = stoi(edges_row_temp[j]);

        edges[i][j] = edges_row_item;
      }
    }

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    vector<int> result = shortestReach(n, edges, s);

    for (size_t i = 0; i < result.size(); i++)
    {
      fout << result[i];

      if (i != result.size() - 1)
      {
        fout << " ";
      }
    }

    fout << "\n";
  }

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
  return s;
}

string rtrim(const string &str)
{
  string s(str);
  s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
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
