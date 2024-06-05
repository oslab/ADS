#include <stdlib.h>
#include <stdio.h>
void quicksort(int arr[25],int low,int high){
   int i, j, pivot, temp, val;
   if(low<high){
      pivot=low;
      //printf("Pivot = %d\n",pivot);
      i=low;
      j=high;
      while(i<j){
         while(arr[i]<=arr[pivot]&&i<high)
            i++;
         while(arr[j]>arr[pivot]&&j>low)
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }//while
      temp=arr[pivot]; 
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,low,j-1);
      quicksort(arr,j+1,high);
   }//if
}
int main(){
   int i, count, arr[25];
   printf("Number of elements in the array: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

   quicksort(arr,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);

   return 0;
}
