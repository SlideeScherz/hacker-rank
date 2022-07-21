#include <bits/stdc++.h>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct Node
{
  int vertex, end, weight;
  int distanceToStart, previousVertex;

  Node(int v, int e, int w)
  {
    vertex = v;
    end = e;
    weight = w;
  }

  void printNode()
  {
    cout << vertex << ": " << end << " " << weight << " D: " << distanceToStart << " prev: " << previousVertex << endl;
  }
};

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
  vector<int> paths = {};
  vector<Node> graphEdges = {};

  cout << "n: " << n << endl;

  // create the nodes from input
  for (int i = 0; i < n; i++)
  {
    /* input
    cout << edges[i][0] << " ";
    cout << edges[i][1] << " ";
    cout << edges[i][2] << endl;
    */
    // cout << "node:\t";
    Node node(edges[i][0], edges[i][1], edges[i][2]);

    // if starting
    if (node.vertex == s)
    {
      node.distanceToStart = 0;
      node.previousVertex = 0;
    }

    // save last vertex
    else if (i > 0)
    {
      node.previousVertex = graphEdges[i - 1].vertex;
    }

    // node.printNode();
    graphEdges.emplace(graphEdges.cend(), node);

    cout << "edge:\t";
    graphEdges[i].printNode();

    /*
    can this node reach next node (next)?
    yes:
      record that cost
      record dist from start
    no:
      next
    */

    for (int i1 = 0; i1 < n; i1++)
    {
      Node thisNode = graphEdges[i1];
      // compare this node to all 1-4 and see if it ends
      for (int i2 = 0; i2 < n; i2++)
      {
        Node nextNode = graphEdges[i2];
      }
    }
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
