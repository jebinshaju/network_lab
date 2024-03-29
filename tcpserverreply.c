#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char buff[100];
	char k;
	socklen_t len;
	
	int sock_desc,temp_sock_desc;
	struct sockaddr_in server, client;
	sock_desc = socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_desc == -1)
	{
		printf("Error in socket creation.");
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port  = 3003;
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	k = bind(sock_desc,(struct sockaddr*)&server, sizeof(server));
	
	if(k == -1)
	{
		printf("Error in binding");
	}
	
	k = listen(sock_desc,5);
	
	if(k ==-1)
	{
		printf("Error in listening");
	}
	
	len = sizeof(client);
	temp_sock_desc = accept(sock_desc,(struct sockaddr*)&client,&len);
	if(temp_sock_desc==-1)
	{
		printf("Error in creating temporary socket creation");
	}
	do
	{
		k = recv(temp_sock_desc,buff,100,0);
		if(k ==-1)
		{
			printf("Error in recieving");
		}
		
		printf("\nMessage got from client : %s",buff);
		char reply[100];
		printf("\nEnter the reply: ");
		gets(reply);
		
		k= send(temp_sock_desc,reply,100,0);
		close(temp_sock_desc);
		if(strcmp(reply,"bye")== 0)
			break;
	}while(1);
	return 0;
	
}

/*
user@user:~/monkey$ ./server 8080


Message got from client : hi
Enter the reply: hello
Error in recieving
Message got from client : hi
Enter the reply: bye
user@user:~/monkey$ 

 
*/

