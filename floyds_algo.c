/*FLOYD'S  ALGORITHM*/

#include<stdio.h>
#include<math.h>
int min(int,int);

/*the element in p[i][j] of the current distance matrix is replaced by sum of 
  p[i][k] and p[k][j] if and only if this sum is less than the current value of 
  p[i][j]*/
void floyd(int p[10][10],int n) 
{
        int i,j,k;
        for (k=1;k<=n;k++)
        {
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                {
                    p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
                    printf("%d\t",p[i][j]);
                }
                printf("\n");
            }
            printf("end of matrix %d \n",k);
            printf("\n");
        }
}

int min(int a,int b)     //function to find minimum element
{
        if(a<b)
        {
            return(a);
        }
        else
        {
            return(b);
        }
}

void main()
{
        int p[10][10],n;
        printf("enter dimension of square matrix\n");
        scanf("%d",&n);
        printf("enter adjacent matrix\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&p[i][j]);
            }
        }
        printf("\n Matrix of input data: \n"); 
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                printf("%d\t",p[i][j]);    //printing input matrix
            }
            printf("\n");
        }
        printf("\n");
        
        floyd(p,n);
        
        printf("\n least weight matrix: \n");
        for (int i=1;i<=n;i++) 
        {
            for (int j=1;j<=n;j++)
            {
                printf("%d\t",p[i][j]);
            }
            printf("\n");
        }
}
