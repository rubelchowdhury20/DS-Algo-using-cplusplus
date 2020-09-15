// link https://www.codechef.com/problems/CNOTE

#include <cstdio>

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= b; --(i))

using namespace std;

int main(){
    int T;
    bool isLucky;
    scanf("%d", &T);
    FOR(i, 0, T){
        isLucky = false;
        int X, Y, K, N;
        scanf("%d %d %d %d", &X, &Y, &K, &N);
        int R = X - Y;
        int p, c;
        FOR(j, 0, N){
            scanf("%d %d", &p, &c);
            if(c <= K && p >= R){
                isLucky = true;
                break;
            }
        }

        if (isLucky){
            printf("LuckyChef\n");
        }
        else{
            printf("UnluckyChef\n");
        }
    }

    return 0;
}