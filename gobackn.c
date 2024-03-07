#include <stdio.h>

void send(int windowsize)
{
	int i;
	for (i=1; i<=windowsize; i++) 
	{
		printf("frame%d is transmitted\n", i);
	}
}

void retransmiter(int windowsize,int retransmit)
{
	int k = windowsize;
	int i=retransmit+1;
	while(k!=0)
	
	{
		printf("frame%d is retransmitted\n", i);
		i++;
		k--;
	}
}
void main() {
	int i, windowsize, retransmit;
	printf("Enter the window size: ");
	scanf("%d", &windowsize);
	send(windowsize);
	while (1) 
	{
		printf("Enter the last recieved acknowledgement:(-1/frame_id): ");
		scanf("%d", &retransmit);
		if (retransmit != -1 ) 
		{
			retransmiter(windowsize,retransmit);
		}
		else 
		{
			break;
		}
	}
}


