#include<stdio.h>
int id,ack;
void send()
{
	printf("Enter the frame id to send: ");
	scanf("%d",&id);
}

void recieve()
{
	printf("Enter the acknowledgement for the frame recieved.Enter 0 if frame lost. (0/ack):");
	scanf("%d",&ack);
	if(ack == 0)
	{
		printf("Frame lost!!!\n");
		recieve();
		
	}
}


int main()
{
	int op;
	do
	{
		send();
		recieve();
		if(id == ack)
		{
			printf("%d recieved succesfully.\n",id);
		}
		else
		{
			printf("Error in transmission. need to retransmit.\n");
			send();
			recieve();
		}
		printf("Enter 1 to continue 0 to stop (1/0): ");
		scanf("%d",&op);
	}while(op == 1);
}
