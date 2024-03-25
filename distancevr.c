#include<stdio.h>
struct node
{
	int dist[100],from[100];
}r[20];
int n,count,i,j,k;
void main()
{
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	int graph[n][n];
	
	printf("Enter matrix.\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the distance from %d to %d: ",i,j);
			scanf("%d",&graph[i][j]);
			graph[i][i]=0;
			r[i].dist[j]=graph[i][j];
			r[i].from[j]=j;
		}
	}
	do
	{
		
		count=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(r[i].dist[j]>r[i].dist[k]+r[k].dist[j])
					{
						r[i].dist[j]=r[i].dist[k]+r[k].dist[j];
						r[i].from[j]=k;
						count++;
					}
				}
			}
		}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		printf("_Distance of router %d to other routers_\n",i);
		for(j=0;j<n;j++)
		{
			printf("Node %d via node %d :: %d\n",j,r[i].from[j],r[i].dist[j]);
		}
	}	
}
/*
Enter number of nodes : 3
Enter matrix.
Enter the distance from 0 to 0: 0
Enter the distance from 0 to 1: 2
Enter the distance from 0 to 2: 7
Enter the distance from 1 to 0: 2
Enter the distance from 1 to 1: 0
Enter the distance from 1 to 2: 3
Enter the distance from 2 to 0: 7
Enter the distance from 2 to 1: 3
Enter the distance from 2 to 2: 0
_Distance of router 0 to other routers_
Node 0 via node 0 :: 0
Node 1 via node 1 :: 2
Node 2 via node 1 :: 5
_Distance of router 1 to other routers_
Node 0 via node 0 :: 2
Node 1 via node 1 :: 0
Node 2 via node 2 :: 3
_Distance of router 2 to other routers_
Node 0 via node 1 :: 5
Node 1 via node 1 :: 3
Node 2 via node 2 :: 0
*/
