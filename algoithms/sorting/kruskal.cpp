#include<iostream>
#include<vector>
#include<algorithm>
#include "Graph.hpp"

using namespace std;

//create classes and instances for an edge and a graph

class Edge{
    public:

    //declare instances of Edge 
    int node_start;
    int node_end;
    int weight;

    ////construct an edge object which will contain 2 nodes and their weight
    Edge(){}
    Edge(int node1, int node2, int wt): node_start(node1), node_end(node2), weight(wt){}
};

//take the weight from the custructor and use it to make our first evaluation 
//will return true if 
bool cost_comparison(const Edge a, const Edge b){
    //cout << endl << "a.weight=" << a.weight << endl;
    //cout << endl << "b.weight=" << b.weight << endl;
    return a.weight < b.weight;
}

//INDEX WITH CORRECT INT OF FATAL ERROR
//bug 1 line 21

//create a graph class that will hold edges, for n number of nodes
class Graph{

    private:
    int n; //receive number of nodes INDEX CORRECTLY OR FATAL ERROR WILL OCCUR (Fixed)
    vector<Edge> edgelist; // edgelist will store the edges of minimum spanning tree
    vector<int> parent;
    vector<int> rank;

    //construct a graph class to hold n number of
    public:
    Graph(){}
    Graph(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
    }

    void AddEdge(Edge e);
    int FindParent(int node);
    void KruskalMST(vector<Edge>&);
    void DisplayEdges(vector<Edge>&);
};

void Graph :: AddEdge(Edge e){
    edgelist.push_back(e);
}

int Graph :: FindParent(int node){
    if(parent[node] == node)
       return node;
     return FindParent(parent[node]);
}

void Graph :: DisplayEdges(vector<Edge>& tree) {

    int cost = 0;
    cout << "Edges MST: ";
    for(auto& e : tree) {
        cout << "[" << e.node_start << "-" << e.node_end << "](" << e.weight << ") ";
        cost += e.weight;
    }
    cout << endl << "Cost of minimum spanning tree : " << cost << endl;
}

//SOLVE MST USING KRUSKALS ALGO
void Graph :: KruskalMST(vector<Edge>& result) {

    //while i is less than nodes:
    //index 
    //cout << endl << "n: =" << n << endl;
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    // Sort the edges based on their weights
    sort(edgelist.begin(), edgelist.end(), cost_comparison);

    // Apply union-by-rank technique to find the minimum spanning tree.
    for(auto& e : edgelist){
        int root1 = FindParent(e.node_start);
        int root2 = FindParent(e.node_end);

        if(root1 != root2){
           result.push_back(e);
           if(rank[root1] < rank[root2]){
              parent[root1] = root2;
              rank[root2]++;
           } else {
              parent[root2] = root1;
              rank[root1]++;
           }
        }
    }
}

int main(){

    // Nodes
    //0 is a node
    int n = 6; 

    Edge e1(0, 1, 4);
    Edge e2(0, 2, 1);
    Edge e3(0, 3, 5);
    Edge e4(1, 3, 2);
    Edge e5(1, 4, 3);
    Edge e6(1, 5, 3);
    Edge e7(2, 3, 2);
    Edge e8(2, 4, 8);
    Edge e9(3, 4, 1);
    Edge e10(4, 5, 3);

    //call add edge from edge class
    Graph graphOfEdges(n);

    //cout << endl << "graphOfEdges =" << graphOfEdges << endl;
    graphOfEdges.AddEdge(e1);
    graphOfEdges.AddEdge(e2);
    graphOfEdges.AddEdge(e3);
    graphOfEdges.AddEdge(e4);
    graphOfEdges.AddEdge(e5);
    graphOfEdges.AddEdge(e6);
    graphOfEdges.AddEdge(e7);
    graphOfEdges.AddEdge(e8);
    graphOfEdges.AddEdge(e9);
    graphOfEdges.AddEdge(e10);

    ////cout << endl << "graphOfEdges ln 140 =" << graphOfEdges << endl;

    //populate the minimul spanning tree
    //show edges and make comparisons of the tree argument
    vector<Edge> tree; 

    //solve graphOfEdges using the MST algo
    graphOfEdges.KruskalMST(tree);
    graphOfEdges.DisplayEdges(tree);

    //return edges and cost to terminal!
    return 0;
}
