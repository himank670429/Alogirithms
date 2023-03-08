#include <iostream>
using namespace std;

int Partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start- 1;
    for (int j = start; j < end; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void QuickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pi = Partition(arr, start, end);
        QuickSort(arr, start, pi - 1);
        QuickSort(arr, pi + 1, end);
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
    
    QuickSort(arr, 0, n - 1);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}