#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[])
{
	struct sockaddr_in client;
	if (argc != 3)
	{
		printf("Input format not connect");
	}
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if (sockfd ==-1)
	{
		printf("Error in socket creation");
	}
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = htons(atoi(argv[2]));
	while(1)
	{
		char buffer[100];
		printf("\nEnter message to be send to server: ");
		gets(buffer);
		
		if(sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,sizeof(client)),0)
		{
			printf("Error in sending");
		}
		if(strcmp(buffer,"bye")== 0)
			break;
		char reply[100];
		int i=sizeof(client);
		int k=(recvfrom(sockfd,reply,100,0,(struct sockaddr*)&client,&i));
	  	if(k<0)
	    		printf("error in receiving\n");
		printf("\nGot a datagram:%s",reply);
		
	}
	return 0;
}


