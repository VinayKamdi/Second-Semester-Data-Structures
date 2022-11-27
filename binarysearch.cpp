#include<iostream>
using namespace std ;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        return mid;

        if (arr[mid] < x)
        l = mid + 1;

        else
        r = mid - 1;
    }
    return -1 ;
}
    int main()
    {
        int n, i, val, arr[20] ;
        
        cout << "Enter the size for array: " ;
        cin >> n ;
        
        cout << "Enter elements for array: " ;
        for(i=0; i<n; i++)
        {
            cin >> arr[i] ;
        }
        
        cout << "Enter the element to search: " ;
        cin >> val ;
        
        int res = binarySearch(arr, 0, n - 1, val);
        
        if (res == -1)
        cout << "Element is not present in array";
        else
        cout << "Element is present at index " << res ;
        
        return 0;
    }

    
