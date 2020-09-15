// link to the problem page https://www.codechef.com/problems/LECANDY


#include <iostream>
#include <cstdio>   

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= b; --(i))

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    FOR(i,0,T){
        int N, A, sum = 0;
        scanf("%d %d", &N, &A);

        FOR(j,0,N){
            int a;
            scanf("%d", &a);
            sum += a;
        }

        if (sum <= A){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}