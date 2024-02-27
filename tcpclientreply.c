#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff[100];
	int k;
	int sock_desc;
	struct sockaddr_in client;
	sock_desc = socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_desc == -1)
	{
		printf("Error in socket creation.");
	}
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	k= connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
	
	if(k==-1)
	{
		printf("Error in connecting to server.");
	}
	while(1)
	{
		printf("\nEnter the data to send: ");
		gets(buff);
		k= send(sock_desc,buff,100,0);
		
		if(strcmp(buff,"bye")== 0)
			break;
		
		k = recv(sock_desc,buff,100,0);
		if(k ==-1)
		{
			printf("Error in recieving");
		}
		printf("\nReply recieved: %s",buff);
		close(sock_desc);
		if(strcmp(buff,"bye")== 0)
			break;
	}
	return 0;
}

/*
user@user:~/monkey$ ./client localhost 8080

Enter the data to send: hi

Reply recieved: hello
Enter the data to send: bye
user@user:~/monkey$ 

*/

