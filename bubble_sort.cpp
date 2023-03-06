#include<iostream>
using namespace std;

void BubbleSort(int *arr, int n){
    for (int i = n-1; i >= 0; i --){
        bool swaped = 0;
        for (int j = 0; j <= i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaped = 1;
            }
        }
        if (!swaped){
            return;
        }
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
    BubbleSort(arr,n);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}