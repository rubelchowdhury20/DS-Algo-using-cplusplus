#include <bits/stdc++.h>
using namespace std;


class disjointSet{
    private:
        int *parent, *rank, n;

    public:
        disjointSet(int n){
            parent = new int[n];
            rank = new int[n];
            this->n = n;
        }

        int find(int i){
            if(parent[i] == i){
                return i;
            }
            else{
                return find(parent[i]);
            }
        }

        void Union(int x, int y){
            int x_p = find(x);
            int y_p = find(y);

            if (x_p == y_p){
                return;
            }
            else{
                if(rank[x] > rank[y]){
                    parent[y] = x;
                }
                else if(rank[x] < rank[y]){
                    parent[x] = y;
                }
                else{
                    parent[x] = y;
                    rank[y]++;
                }
            }
        }
};


int main(){
    disjointSet obj(5);
    obj.Union(2, 3);
    obj.Union(1, 4);
    obj.Union(0, 1);

    if(obj.find(2) == obj.find(1)){
        cout << "the node 2 and 3 are connected" << endl;
    }
    if(obj.find(1) == obj.find(2)){
        cout << "the node 2 and 1 are connected" << endl;
    }
}
