    #include<stdio.h>
    #include<math.h>


    int max(int a,int b) {			//Finds the maximum of two elements
    	if(a>b)
    	 return(a); else
    	 return(b);
    }
	
    void warshal(int p[10][10],int n) {		//Computes the transitive closure
    	int i,j,k;
    	for (k=1;k<=n;k++)
    	  for (i=1;i<=n;i++)
    	   for (j=1;j<=n;j++)
    	    p[i][j]=max(p[i][j],p[i][k]&&p[k][j]);
    }



    void main() {
    	int p[10][10],n,i,j;
    	printf("\n Enter the number of vertices:");
    	scanf("%d",&n);
		printf("Enter the input matrix:\n");
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&p[i][j]);
			}
		}

    	printf("\n Matrix of input data: \n");		//Printing the adjacency matrix
    	for (i=1;i<=n;i++) {
    		for (j=1;j<=n;j++)
    		   printf("%d\t",p[i][j]);
    		printf("\n");
    	}
    	warshal(p,n);
    	printf("\n Transitive closure: \n");		//Printing the path matrix
    	for (i=1;i<=n;i++) {
    		for (j=1;j<=n;j++)
    		   printf("%d\t",p[i][j]);
    		printf("\n");
    	}
 
    }
