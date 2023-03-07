#include<iostream>
using namespace std;

void Merge(int *arr, int start, int mid, int end){
    int left_length = mid-start+1;
    int right_length = end-mid;

    int left_arr[left_length];
    int right_arr[right_length];

    for (int i = 0; i < left_length; i++){
        left_arr[i] = arr[start+i];
    }
    for (int i = 0; i < right_length; i++){
        right_arr[i] = arr[mid+1+i];
    }
    int left_index = 0, right_index = 0, k = start;
    while (left_index < left_length && right_index < right_length){
        if (left_arr[left_index] < right_arr[right_index]){
            arr[k] = left_arr[left_index];
            left_index++;
        }
        else{
            arr[k] = right_arr[right_index];
            right_index++;
        }
        k++;
    }
    while (left_index < left_length){
        arr[k] = left_arr[left_index];
        k++;
        left_index++;
    }
    while (right_index < right_length){
        arr[k] = right_arr[right_index];
        k++;
        right_index++;
    }
}

void MergeSort(int *arr, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, start, mid, end);
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
    MergeSort(arr,0,n-1);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}