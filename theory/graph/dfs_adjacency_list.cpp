/* Implementation of DFS using adjacency Matrix
This implementation is for connected graph.
Not implemented in a recursion manner.
For more info check this link
https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
*/


#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}

void printArray(vector <int> adj[], int nodes){
    for(int i=0; i<nodes; i++){
        cout << "Nodes adjacent to " << i << " " << endl;
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}


int main(){
    int nodes, edges;
    cout << "Please enter the number of nodes." << endl;
    cin >> nodes;
    cout << "Please enter the number of edges." << endl;
    cin >> edges;

    vector <int> adj[nodes];
    int u, v;
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);

    printArray(adj, nodes);

    stack <int> nodeStack;
    bool visited[nodes];
    for(int i=0; i<nodes; i++){
        visited[i] = false;
    }
    nodeStack.push(0);
    visited[0] = true;
    while(!nodeStack.empty()){
        int currentNode = nodeStack.top();
        nodeStack.pop();
        for(auto x: adj[currentNode]){
            if(visited[x] == false and x <= nodes){
                nodeStack.push(x);
                visited[x] = true;
                cout << "Node " << x << " is visited." << endl;
            }
        }
    }
}