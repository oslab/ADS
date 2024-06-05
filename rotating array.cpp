#include<stdio.h>
 int rotate_array(int arr[],int l,int h)
 {
 if(l<h)
 {
 if(arr[l]<arr[h])
 return arr[l];
 int mid=l+(h-l)/2;
 if(arr[mid]>arr[h])
 return rotate_array(arr,mid+1,h);
 else
 return rotate_array(arr,l,mid);
 }
 return arr[l];
 }
 int main()
 {
 int n,size;
 printf("Enter size: ");
scanf("%d",&size);
 int a[size],i;
 for(i=0;i<size;i++)
 {
 scanf("%d",&a[i]);
 }
 printf("Minimum number: %d",rotate_array(a,0,size-1));
 }
