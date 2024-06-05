#include<stdio.h>
 int linear_search(int a[],int n,int
 size){ int i;
 for(i=0;i<size;i++){
 if(a[i]==n){
 return i;
 }}
return 0;
 }
 int binary_search(int a[],int key,int l,int h)
 {
 if(l<=h)
 {
 int m=(l+h)/2;
 if(a[m]==key)
 return m;
 else if(key<a[m])
 return binary_search(a,key,l,m-1);
 else
 return binary_search(a,key,m+1,h);
 }
 return-1;
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
 printf("\nEnter a number for linear search: ");
 scanf("%d",&n);
 printf("Linear search %d",linear_search(a,n,size));
 printf("\nEnter a number for binary search: ");
 scanf("%d",&n);
 printf("Binary search %d",binary_search(a,n,0,size-1));
 }
