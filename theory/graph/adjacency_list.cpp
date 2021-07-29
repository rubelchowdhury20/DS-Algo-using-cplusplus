/*
Directed Graph Representation in Adjacency List form
In this representation 
*/


#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// A utility function to add an edge to directed graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

/*
void printGraph(vector<int> adj[], int nodes){
    for(int i=0; i<nodes; i++){
        cout << "size of the node " << i << " is ";
        cout << adj[i].size() << endl;

        for (auto j = adj[i].begin(); j!= adj[i].end(); j++){
            cout << "The edge is from " << i << " to " << *j << endl;
        }
    }
}
*/

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main(){
    int nodes, edges;
    cin >> nodes;
    cin >> edges;
    vector <int> adj[nodes];
    for(int i=0; i<edges; i++){
        int u, v;
        cin >> u;
        cin >> v;
        addEdge(adj, u, v);
    }

    printGraph(adj, nodes);
    return 0;

}