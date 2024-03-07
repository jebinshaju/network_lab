#include <stdio.h>
void send(int windowsize)
{
	int i;
	for (i=1; i<=windowsize; i++) {
		printf("frame%d is transmitted\n", i);
	}
}

void retransmiter(int retransmit)
{
	printf("frame%d is retransmitted\n", retransmit);
}


void main() {
	int i, windowsize, retransmit;
	printf("Enter the window size: ");
	scanf("%d", &windowsize);
	for (i=1; i<=windowsize; i++) {
		printf("frame%d is transmitted\n", i);
	}
	while (1) {
		printf("Enter the frame that didn't receive ack:(-1/frameID): ");
		scanf("%d", &retransmit);
		if (retransmit != -1 ) {
			retransmiter(retransmit);
		}
	
		else {
			break;
		}
	}
}
