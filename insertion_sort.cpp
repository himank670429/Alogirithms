#include<iostream>
using namespace std;

void InsertionSort(int *arr, int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    cout << "enter the length of the array : ";
    cin >> n;
    int *arr = new int[n];
    cout << "enter elements for the array : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    InsertionSort(arr,n);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}