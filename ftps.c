#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char buff[10000];
	char k,str[10000];
	socklen_t len;
	FILE *f1;		
	
	int sock_desc,temp_sock_desc;
	struct sockaddr_in server,client;
	sock_desc = socket(AF_INET,SOCK_STREAM,0);
	
	if(sock_desc == -1)
	{
		printf("Error in  socket creation.");
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = 3003;
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3003;
	
	k= bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
	
	if(k==-1)
	{
		printf("Error in binding");
	}
	
	k= listen(sock_desc,5);
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
	
 	 close(sock_desc);
       read(temp_sock_desc, &str, 60);
       printf("\nClient message\n File Name : %s\n", str);
       f1=fopen(str, "r");
       while(fgets(buff, 10000, f1)!=NULL)
       {
            write(temp_sock_desc,buff,20);
            printf("%s\n",buff);
       }
       fclose(f1);
       printf("\nFile Transferred\n");
	close(temp_sock_desc);
	return 0;
	
}

/*
user@user:~/monkey$ ./server 8081

Client message
 File Name : test.txt
this is ia sample file




File Transferred
user@user:~/monkey$ 
*/

