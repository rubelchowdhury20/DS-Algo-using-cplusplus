/**
 * 14/01/2021 -
 * link:     https://www.codechef.com/problems/DELISH
 * 
 * Complexity:  
 * Timing:      
 *
 * Description:
 */


#include<iostream>
#include <cstdlib>

using namespace std;

const int inf = 1000000001;
const int ninf = -1000000001;

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; ++t){
        int N;
        scanf("%d", &N);
        int D[N], max_lr[N], min_lr[N], max_rl[N], min_rl[N];
        for(int n=0; n<N; ++n){
            scanf("%d", &D[n]);
            max_lr[n] = D[n];
            min_lr[n] = D[n];
            max_rl[n] = D[n];
            min_rl[n] = D[n];
        }

        for(int n=N-2; n>=0; --n){
            if(max_lr[n] + max_lr[n+1] > max_lr[n]){
                max_lr[n] = max_lr[n] + max_lr[n+1];
            }
            if(min_lr[n] + min_lr[n+1] < min_lr[n]){
                min_lr[n] = min_lr[n] + min_lr[n+1];
            }
        }
        for(int n=1; n<N; ++n){
            if(max_rl[n] + max_rl[n-1] > max_rl[n]){
                max_rl[n] = max_rl[n] + max_rl[n-1];
            }
            if(min_rl[n] + min_rl[n-1] < min_rl[n]){
                min_rl[n] = min_rl[n] + min_rl[n-1];
            }
        }
        // for(int n=N-2; n>=0; --n){
        //     if(max_lr[n] < max_lr[n+1]){
        //         max_lr[n] = max_lr[n+1];
        //     }
        //     if(min_lr[n] > min_lr[n+1]){
        //         min_lr[n] = min_lr[n+1];
        //     }
        // }
        // for(int n=1; n<N; n++){
        //     if(max_rl[n] < max_rl[n-1]){
        //         max_rl[n] = max_rl[n-1];
        //     }
        //     if(min_rl[n] > min_rl[n-1]){
        //         min_rl[n] = min_rl[n-1];
        //     }
        // }

        int max_value = ninf;
        for (int i=0; i<N-1; ++i){
            if(abs(max_rl[i] - min_lr[i+1]) > max_value){
                max_value = abs(max_rl[i] - min_lr[i+1]);
            }
        }
        for (int i=0; i<N-1; ++i){
            if(abs(min_rl[i] - max_lr[i+1]) > max_value){
                max_value = abs(min_rl[i] - max_lr[i+1]);
            }
        }

        printf("%d ", max_value);
        // printf("\n");
    }
}