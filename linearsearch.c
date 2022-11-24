#include<stdio.h>
#include<conio.h>
int main()
{
int n, i, val, a[100], flag=0 ;
printf("Enter the size for array : ");
scanf("%d",&n);
printf("Enter elements for array : ");
for(i=0; i<n; i++)
{
    scanf("%d",&a[i]);
}
printf("Enter the element to search : ");
scanf("%d",&val);
for(i=0; i<n; i++)
{
    if(val==a[i])
    {
        flag=1;
    }
}
if(flag==1)
{
    printf("Element %d found on %dth position.",val, i);
}
else
{
    printf("Element is not present in array.");
}
    return 0;
}