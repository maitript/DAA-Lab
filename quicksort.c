#include<stdio.h>
#include<time.h>
#include<stdlib.h>

clock_t start,end;
double tt;

void quicksort(int a[],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot]&&j>first)
            j--;
         if(i<j){
            temp=a[i];		// Swapping number[i] and number[j]
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;			//Swapping pivot and number[j]
      quicksort(a,first,j-1);	//Calling the quicksort function recursively
      quicksort(a,j+1,last);

   }
}

void main(){
   int i, count;

   printf("Enter the size of the array: ");   //Taking input of size of array
   scanf("%d",&count);
   srand(time(0));

   printf("Enter %d elements: ", count);	
   int a[count];

   for(i=0;i<count;i++)		//Using rand to generate a random no
   {
    	int r = rand();
	    a[i] = r;
   }
   printf("Before Sorting:");
   for(i=0;i<count;i++)
	   printf("%d\n",a[i]);

	
   start = clock();
   quicksort(a,0,count-1);	     //Calling the quicksort function
   end = clock();

   printf("After Sorting:");
   for(i=0;i<count;i++)
           printf("%d\n",a[i]);

	
   tt = (double)(end - start)/CLOCKS_PER_SEC;    //Calculating the total time taken
   printf("Time taken is %lf",tt);
}
