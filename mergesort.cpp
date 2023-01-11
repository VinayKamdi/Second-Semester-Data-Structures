#include<iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub)
{
    //size and array
    int n1=mid-lb+1;
    int n2=ub-mid;
    int a[n1];
    int b[n2];
    
    //extract elements
    for(int i=0; i<n1; i++)
    {
        a[i]=arr[lb+i];
    }
    for(int i=0; i<n2; i++)
    {
        b[i]=arr[mid+i+1];
    }
    
    //reset counter
    int i=0;
    int j=0;
    int k=lb;
    
    //placing elements back in order
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergesort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid+1, ub);
        
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int n, i, arr[20];
    std::cout << "Enter size of the array: ";
    std::cin >> n;
    std::cout << "Enter "<< n << " elements for the array: ";
    for(i=0; i<n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << std::endl;
    
    mergesort(arr, 0, n-1);
    
    std::cout << "The sorted array: ";
    for(i=0; i<n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
}
