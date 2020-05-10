#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444
char buffer[1024];

void serve(char a[])
{
	
	int sockfd;
	struct sockaddr_in serverAddr;

	char ex[1024];	
	strcpy(ex," 2nd pc");
	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("[+] Socket G Created Sucessfully.\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(a);

	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf("[+]Bind to Port number %d.\n", 4444);

	listen(sockfd, 5);
	printf("[+]Listening...\n");
	
	newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
	strcat(buffer,ex);
	send(newSocket, buffer, strlen(buffer), 0);
	printf("[+]Closing the connection.\n");

}

void main(int argc, char *argv[]){


if(argc==2)
{
	int clientSocket;
	struct sockaddr_in serverAddr;
	


	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("[+]Client Socket Created Sucessfully.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

	int flag=connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	if(flag==0)
	{
		printf("[+]Connected to Server.\n");
		recv(clientSocket, buffer, 1024, 0);
		printf("[+]Data Recv: %s\n", buffer);
		serve("10.2.0.105");
		//strcpy(buffer,"jobs123");
		//send(clientSocket,buffer,strlen(buffer),0);
		printf("[+]Closing the connection.\n");
	}
	else
		printf("[+]Server not found\n");

			
}
else
	printf("exit");



}
