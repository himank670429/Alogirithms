#include <iostream>
using namespace std;

void CountSort(int *arr, int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void RadixSort(int *arr, int n)
{
    // Find the maximum number to know number of digits
    int m = INT32_MIN;
    for (int i = 0; i < n; i++){
        if (arr[i] > m) m = arr[i];
    }
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort(arr, n, exp);
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
    
    RadixSort(arr, n);

    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}