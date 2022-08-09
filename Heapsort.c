// #include<stdio.h>
// #include<math.h>
// #include<conio.h>
// #include<stdlib.h>
// #include<time.h>

// int n,i,temp;

// void heapify(int A[],int n,int i)
// {
//     int largest,l,r; 
//     largest = i;
//     l = (2*i);
//     r = (2*i)+1;
 
//  while(l<=n && A[l]>A[largest])
//  {
//  largest = l;
//  }
//  while(r<=n && A[r]>A[largest])
//  {
//     largest = r;
//  }
//  if(largest!= i)
//  {
//     temp = A[largest];
//     A[largest] = A[i];
//     A[i] = temp;
//     heapify(A,n,largest);
//  }
// }

// void heapsort(int A[],int n)
// {
//     for(i=n/2;i>=1;i--)
//     {
//         heapify(A,n,i);
//     }
//     for(i=n;i>=1;i--)
//     {
//         temp = A[1];
//         A[1] = A[i];
//         A[i] = temp;
//         heapify(A,n,1);
//     }
// }

// void main()
// {
//     int n;
//     printf("Enter the size: ");
//     scanf("%d", &n);
//     int A[n];
//     printf("Enter elements:");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&A[i]);
//     }
//     heapify(A,n,1);
//     printf("After heapsort:\n");
//     heapsort(A,n);
//     for(i=0;i<n;i++)
//     printf("%d",A[i]);


// }


#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
int h[50];


void heapify(int h[],int n)
{
    int i,j,n1,k,heap,v;
    n1=n;
for(i=n1/2;i>=1;i--)
{
    k=i;
    v=h[k];
    heap=0;
     while(!(heap)&&(2*k)<=n1)
    {
         j=2*k;


        if(j<n1)
            if(h[j]<h[j+1])    //if left child is less than right
                j=j+1; 


    if(v>=h[j])
        heap=1;            //already heapified
    else
    {
         h[k]=h[j];
        k=j;
     }
        h[k]=v;       //inside while loop
    }
}
}


void main()
{
int i,n,size,t;
clock_t start,end;
double totaltime;

printf("enter value of n\n");
scanf("%d",&n);
//printf("enter array elements\n");
for(i=1;i<=n;i++)
{
h[i]=rand();
}
//scanf("%d",&h[i]);
printf("elements\n");
for(i=1;i<=n;i++)
{
printf("%d\t",h[i]);
}

start=clock();
heapify(h,n);
printf("elemts heapified:\n");
for(i=1;i<=n;i++)
printf("%d\t",h[i]);


for(i=n;i>=1;i--)
{
t=h[1];
h[1]=h[i];
h[i]=t;
size=i-1;
heapify(h,size);
}
end=clock();


printf("elements sorted\n");
for(i=1;i<=n;i++)
printf("%d\t",h[i]);
totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("time taken is %e",totaltime);

}