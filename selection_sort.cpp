#include<iostream>
using namespace std;

void SelectSort(int *arr, int n)
{
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i],arr[min]);
    }
}

int main()
{
    int n;
    cout << "enter the length of the array : ";
    cin >> n;
    int *arr = new int[n];
    cout << "enter elements for the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SelectSort(arr, n);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}