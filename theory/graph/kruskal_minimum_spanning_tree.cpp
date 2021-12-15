#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src, dst, weight;
};

class Graph{
    public:
        int V, E;
    Edge* edge;
};

Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

class subset{
    public:
        int parent;
        int rank;
};

int find(subset subsets[], int i){
    if(subsets[i].parent == i){
        return i;
    }
    else{
        subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
}

void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (xroot == yroot){
        return;
    }
    if(subsets[x].parent != subsets[y].parent){
        if(subsets[x].rank > subsets[y].rank){
            subsets[y].parent = x;
        }
        else if(subsets[x].rank < subsets[y].rank){
            subsets[x].parent = y;
        }
        else{
            subsets[x].parent = y;
            subsets[y].rank++;
        }
    } 
}

int compare(const void* a, const void* b){
    Edge* a1 = (Edge*) a;
    Edge* b1 = (Edge*) b;
    if(a1->weight > b1->weight){
        return 1;
    }
    else if(a1->weight < b1->weight){
        return -1;
    }
    else{
        return 0;
    }
}

void kruskalMST(Graph* graph){
    int V = graph->V;
    Edge result[V]; // Array where the final Minimum Spanning Tree will be saved

    int r=0;  // Keeping track of the edge index of result
    int e=0;  // keeping track of explored edges
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    subset* subsets = new subset[V];
    for(int i=0; i<V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    while(r<(graph->V)-1 and e < graph->E){
        Edge current_edge = graph->edge[e++];
        int root_x = find(subsets, current_edge.src);
        int root_y = find(subsets, current_edge.dst);

        if(root_x != root_y){
            result[r++] = current_edge;
            Union(subsets, root_x, root_y);
        }

    }

    cout << "Following are the edges of the minimum spanning tree" << endl;
    int minimum_cost = 0;
    for(int i=0; i<r; i++){
        cout << "Edge from " << result[i].src << " to " << result[i].dst << endl;
        minimum_cost += result[i].weight;
    }
    cout << "Total cost " << minimum_cost << endl;
}

int main(){
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph

    Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dst = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dst = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);
    return 0;
}

