#include<stdio.h>
#include<stdlib.h>

struct packet{
int psize;
int done;
}p[30];

int filled=0,bsize,n,outrate;

void bfull()
{
  printf("\nBucket is full...");
  exit(0);
}



int main()
{ 
        int i;
	printf("Enter no of packets: ");
	scanf("%d",&n);
	
	
	for(i=1;i<=n;i++)
	{
	        printf("Enter size of packet %d: ",i);
	        p[i].done=0;
		scanf("%d",&p[i].psize);
	}
	
	printf("Enter bucket size: ");
	scanf("%d",&bsize);
	
	printf("Enter outflow outrate: ");
	scanf("%d",&outrate);
	
	i=1;
	 while(i!=n+1){       
		if(p[i].psize > bsize)
		{
		  printf("\nPacket %d is discarded",i);
		  printf("packet size %d",p[i].psize );
		  p[i].done=1;
		}
		else
		{
			if(p[i].psize > outrate)
			{
		         filled = filled+p[i].psize;
		         if(filled==bsize)
		      	    bfull();  	      	 
			 	p[i].psize= p[i].psize-outrate;      
                        printf("\nTransmitting packet %d ",i);
 				filled=filled-outrate; 
				printf("\n\tCurrent Bucket size left after outflow of %d: %d",outrate,bsize-filled);
				printf("\n\tCurrent size of packet%d left: %d",i,p[i].psize);                
			}
			else if(p[i].psize==outrate)
			{
		         filled = filled+p[i].psize;
		         p[i].done = 1;
		         if(filled==bsize){
		      	  bfull();
		         }
	      	 p[i].psize=0;
	      	 printf("\nTransmitting packet %d ",i);
			 filled=filled-outrate; 
			 printf("\n\tCurrent Bucket size left after outflow of %d: %d",outrate,bsize-filled);
			 printf("\n\tCurrent size of packet%d left: %d",i,p[i].psize);
		      }
		        else
		        {
		         printf("\nDiscarding packet %d", i);
		         p[i].done=1;
		        
		        }
		  }
		  if(p[i].done==1)
		  {			  		  
		  i++;
		  }
		  printf("\n");
		 }
		  
}
		       
		       
/*
user@user:~/monkey$ gcc leakybucket.c && ./a.out
Enter no of packets: 3
Enter size of packet 1: 200
Enter size of packet 2: 300
Enter size of packet 3: 250
Enter bucket size: 500
Enter outflow outrate: 100

Transmitting packet 1 
	Current Bucket size left after outflow of 100: 400
	Current size of packet1 left: 100

Transmitting packet 1 
	Current Bucket size left after outflow of 100: 400
	Current size of packet1 left: 0

Transmitting packet 2 
	Current Bucket size left after outflow of 100: 200
	Current size of packet2 left: 200

Bucket is full...user@user:~/monkey$ 

*/		         
		         
			 
			 
		
