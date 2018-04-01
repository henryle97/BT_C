#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTEX = 100;         //So dinh max
vector<int> adj[MAX_VERTEX];        //Adjacency List: Danh sach ke

//Function to add a edge in a undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Function to print the adjacency list represented of graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; v++)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head";
        for (auto x : adj[v])
            cout << "-> " << x <<endl;
    }
}
int main()
{
    int V = 5;      // 5 vertex
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);

    return 0;
}
