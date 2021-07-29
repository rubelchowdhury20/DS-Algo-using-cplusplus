// Directed Graph representation in Adjacency Matrix form

#include <bits/stdc++.h>
#include <istream>

using namespace std;

void printArray(int **adj, int n, int m){
    for(int i=0; i<n; i++){
        cout << "Elments of node " << i <<endl;
        for(int j=0; j<m; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    int nodes, edges;
    cout << "Please enter the number of nodes in the graph." << endl;
    cin >> nodes;
    cout << "Please enter the number of edges in the graph." << endl;
    cin >> edges;

    int **adj = new int*[nodes]; // Declaring dynamic 2d array as array of pointers
    
    for(int i=0; i<nodes; i++){
        adj[i] = new int[nodes];
    }

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<edges; i++){
        int u, v, w;
        cout << "Please enter the source of " << i << " edge" << endl;
        cin >> u;
        cout << "Please enter the destination of " << i << " edge" << endl;
        cin >> v;
        cout << "Please enter the weight of the edge" << endl;
        cin >> w;
        adj[u][v] = w;
    }

    printArray(adj, nodes, nodes);
}