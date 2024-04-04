#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff[10000],recvline[10000];
	int k,n;
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
	char file[10000];
	printf("\nEnter the filename to send: ");
	scanf("%s",file);
	write(sock_desc,file,20);
	while((n = read(sock_desc,recvline,20))!= 0)
		printf("%s",recvline);
	close(sock_desc);
	return 0;
}
/*
user@user:~/monkey$ ./client localhost 8081

Enter the filename to send: test.txt
this is ia sample fi
user@user:~/monkey$ 
*/
