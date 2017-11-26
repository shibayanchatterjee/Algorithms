#include <iostream>
#include <cstdlib>
using namespace std;

void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int size){
    cout<<"Array: ";
    for (int i = 0; i < size; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void mergeSort(int arr[], int l, int r){
    int mid = 0;
    if (l < r){
        mid = (l + (r-1))/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    return;
}
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    
    i = 0, j = 0, k = 1;
    while (i < n1 and j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            ++i;
        }
        else{
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
}
int main ( int argc, char** argv ) {
    int arr[] = {10, 8, 36, 22, 39, 16};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size-1);
    cout<<"After doing merge_sort: ";
    printArray(arr, arr_size);
    return 0;
}

