#include<iostream>

using namespace std;

void merge (int arr[], int l, int m, int r){
    int i, j, k;

    // length of left and right array
    int n1 = m - l + 1;
    int n2 = r - m;

    // initializing subarrays to save the left and right portion of the array seperately
    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }

    // initializing i, j, k variables
    i = 0;
    j = 0;
    k = l;

    // looping though both the arrays and sorting them back to the main array arr
    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // putting the remaining elements from either left array or right array to the main array
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        // finding the middle point
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {9, 1, 5, 3, 7, 9, 8};
    int size = sizeof(a)/sizeof(a[0]);

    printf("The given array is \n");
    printArray(a, size);
    
    mergeSort(a, 0, size-  1);

    printf("The sorted array is \n");
    printArray(a, size);

    return 0;
}