
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 500
int t[MAX];



int horspool(char src[],char p[])
{
 int i,j,k,m,n;
 n=strlen(src);
 m=strlen(p);
 printf("nLength of text=%d",n);        //Prints length of the string
 printf("n Length of pattern=%d",m);    //Prints length of the substring
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==src[i-k]))          //Comparing the characters of the string and substring
   k++;
  if(k==m)
   return(i-m+1);
  else
   i+=t[src[i]];
 }
 //end of while loop
 return -1;
}


void shifttable(char p[])             //It shows the number of shifts each character has to take
{
 int i,j,m;
 m=strlen(p);
 for(i=0;i<MAX;i++)           
  t[i]=m;
 for(j=0;j<m-1;j++)
  t[p[j]]=m-1-j;
  //end of for loop
}


void main()
{
 char src[100],p[100];
 int pos;
 printf("Enter the text :");
 gets(src);
 printf("Enter the pattern to be searched:");
 gets(p);
 shifttable(p);               //Calling the shift table function
 pos=horspool(src,p);         //Calling the horsepool function
 if(pos>=0)
  printf("The desired pattern was found starting from position %d",pos+1);
 else
  printf("The pattern was not found in the given text");
}
