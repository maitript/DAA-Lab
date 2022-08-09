    #include<stdio.h>
    int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
    void bfs(int v) {
    	for (i=1;i<=n;i++)
    	  if(a[v][i] && !visited[i])
    	   q[++r]=i;		//Adding the node to the queue if it isn't visited
    	if(f<=r) {
    		visited[q[f]]=1;
    		bfs(q[f++]);
    	}
    }
    void main() {
    	int v;
    	printf("\n Enter the number of vertices:");
    	scanf("%d",&n);
    	for (i=1;i<=n;i++) {
    		q[i]=0;
    		visited[i]=0;		//Initializing every vertex to zero initially
    	}
    	printf("\n Enter graph data in matrix form:\n");
    	for (i=1;i<=n;i++)
    	  for (j=1;j<=n;j++)
    	   scanf("%d",&a[i][j]);	//Taking the input of the matrix
    	printf("\n Enter the starting vertex:");
    	scanf("%d",&v);			//Taking the input of the starting vertex
    	bfs(v);
    	printf("\n The node which are reachable are:\n");
    	for (i=1;i<=n;i++)
    	  if(visited[i])		//Printing nodes that are reachable
    	   printf("%d\t",i); else
    	   printf("\n Bfs is not possible");
    }
