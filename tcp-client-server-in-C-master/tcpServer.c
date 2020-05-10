#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void connectc(char ipbuf[])
{
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("[+]Client Socket Created Sucessfully.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(ipbuf);

	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("[+]Connected to Server.\n");

	recv(clientSocket, buffer, 1024, 0);
	printf("[+]Data Recv: %s\n", buffer);
	printf("[+]Closing the connection.\n");
}

void main(int argc, char *argv[]){


if(argc>=2)
{
	//int i=2;
	int sockfd;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	int flag=0;

	socklen_t addr_size;
	char buffer[100];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
//	printf("[+]Server Socket Created Sucessfully.\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("[+]Bind to Port number %d.\n", 4444);

	listen(sockfd, 5);
	int aflag;
	printf("[+]Listening...\n");
	printf("Connect?\n");
	scanf("%d",&aflag);	
	if(aflag)
	{
		connect()
	}
	newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
	printf("Connection Established.\n");
	while(1)
	{
		printf("\n1.Send a message?\n2.Receive a msg?");
		scanf("%d",&flag);
		if(flag==1)
		{
			printf("\nEnter msg\n");
			scanf("%s",buffer);
			send(newSocket,buffer,strlen(buffer),0);
			printf("Msg sent!\n");
		}
		else if(flag==2)
		{
			recv(newSocket,buffer,1024,0);
			printf("Recv: %s\n",buffer);
		}
	}

	//strcpy(buffer, argv[i]);

	//send(newSocket, buffer, strlen(buffer), 0);
	//printf("Msg successfully sent\n");
	//strcpy(buffer,"");
	//recv(newSocket,buffer,1024, 0);
	//printf("%s\n",buffer);
	//printf("Msg successfully rec\n");
	//}
//	printf("[+]Closing the connection.\n");
}
else
printf("exit");
}
