#include<iostream>

using namespace std;

int partition(int array[], int p, int r){
    int i, j, flag;
    i = p - 1;
    int pivot = array[r];
    for (j = p; j < r; j++){
        if (array[j] < pivot) {
            i++;
            flag = array[i];
            array[i] = array[j];
            array[j] = flag;

        }
    }

    flag = array[i + 1];
    array[i + 1] = pivot;
    array[r] = flag;

    return i+1;
}

void quickSort(int array[], int p, int r){
    int q;
    if (p < r){
        q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}


void printArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {3, 4, 1, 9, 2, 8, 5, 6};
    int size = sizeof(array)/sizeof(array[0]);

    printf("The given array \n");
    printArray(array, size);

    quickSort(array, 0, size-1);

    printf("The sorted array \n");
    printArray(array, size);

}