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
    cout << T;
    for (int t=0; t<T; ++t){
        int N;
        cin >> N;
        int arr[N];
        for (int n=0; n<N; ++N){
            cin >> arr[n];
        }
        
        printArray(arr, N);
    }
} 
