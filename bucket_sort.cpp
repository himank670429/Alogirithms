#include<iostream>
#include<vector>
using namespace std;

void InsertionSort(vector<float> arr){
    int n = arr.size();
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

void BucketSort(float *arr, int n){   
    vector<float> buckets[n];
    for (int i = 0; i < n; i++){
        int index = arr[i] * n;
        buckets[index].push_back(arr[i]);
    }
    for (int i = 0, j = 0; i < n; i++){
        if (buckets[i].size() > 0){
            InsertionSort(buckets[i]);
            for (int k = 0; k < buckets[i].size(); k++){
                arr[j] = buckets[i][k];
                j++;
            }
        }
    }
}

int main(){
    int n;
    cout << "enter the length of the array : ";
    cin >> n;
    float *arr = new float[n];
    cout << "enter elements for the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BucketSort(arr, n);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}