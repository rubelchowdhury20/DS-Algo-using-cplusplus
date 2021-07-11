/**
 * - 14/01/2021
 * link:     https://www.codechef.com/problems/ALTARAY
 * 
 * Complexity:  O(N) per test
 * Timing:      0.38 out of 2
 *
 * Description:
 * starting from the end and counting every alternate signs.
 */


#include<iostream>
using namespace std;


void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int T;
    cin >> T;
    for (int t=0; t<T; ++t){
        int N;
        cin >> N;
        int arr[N], alt_length[N];
        for (int n=0; n<N; ++n){
            cin >> arr[n];
            alt_length[n] = 1;
        }
        bool current_sign;
        if(arr[N-1] >= 0){
            current_sign = true;
        }
        else{
            current_sign = false;
        }
        for (int i=N-2; i>=0; --i){
            if ((current_sign == true) && (arr[i] < 0)){
                alt_length[i] = alt_length[i+1]+1;
            }
            else if ((current_sign == false) && (arr[i] >= 0)){
                alt_length[i] = alt_length[i+1]+1;
            }

            if(arr[i] >= 0){
                current_sign = true;
            }
            else{
                current_sign = false;
            }
        }

        printArray(alt_length, N);
    }
} 
