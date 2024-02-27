#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>

int main(int argc,char* argv[])
{
	struct sockaddr_in server;
	if (argc != 2)
	{
		printf("Input format not correct.");
	}
	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd == -1)
	{
		printf("Error in socket creation.");
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));
	
	if(bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
	{
		printf("Error in binding.");
	}
	
	char buffer[100];
	char reply[100];
	printf("Server waiting.\n");
	do
	{
		strcpy(reply,"");
		int i=sizeof(server);
		int k=(recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server,&i));
	  	if(k<0)
	    		printf("error in receiving\n");
		printf("\nGot a datagram:%s",buffer);
		
		
		printf("\nEnter reply message: ");
//		fgets(reply,100,stdin);
		gets(reply);
		
		//printf("length : %d",strlen(reply));
		
		if(sendto(sockfd,reply,sizeof(reply),0,(struct sockaddr*)&server,sizeof(server)),0)
		{
			printf("\nError in sending");
		}
		if(strcmp(reply,"bye")== 0)
			break;
	}while(strcmp(buffer,"bye")!= 0);
	return 0;
}



