#include<stdio.h>
#include<conio.h>

int main()
{
    int n,i,j,a[100],x;
    printf("Enter the size for array : ");
    scanf("%d",&n);
    printf("Enter elements for array : ");
    
    for(i=0; i<n; i++)
    {
       scanf("%d",&a[i]);
    }
    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                x=a[j];
                a[j]=a[i];
                a[i]=x;
            }
        }
    }
    printf("The sorted array is : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}
