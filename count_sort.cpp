#include<iostream>
#include<climits>
using namespace std;

void CountSort(int *arr, int n){
    // find max
    int max = INT32_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > max) max = arr[i];
    }

    // initialize count array
    int count_arr[max+1] = {0};
    for (int i = 0; i < n; i++){
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= max; i++){
        count_arr[i] += count_arr[i-1];
    }
    
    int output[n] = {0};
    for (int i = n-1; i >= 0; i--){
        int a = arr[i];
        int b = --count_arr[a];
        output[b] = a;
    }
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
    cout << endl;
}
int main(){
    int n;
    cout << "enter the length of the array : ";
    cin >> n;
    int *arr = new int[n];
    cout << "enter elements for the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    CountSort(arr, n);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}