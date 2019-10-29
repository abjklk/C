// C program to display hostname 
// and IP address 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <string.h> 

// Returns host information corresponding to host name 
void checkHostEntry(struct hostent * hostentry) 
{ 
	if (hostentry == NULL) 
	{ 
		perror("gethostbyname"); 
		exit(1); 
	} 
} 

int main() 
{ 
    char addr[20];
    printf("Enter remote host address\n");
    scanf("%s",addr); 
	char *IPbuffer; 
	struct hostent *host_entry; 
	int hostname; 

	// To retrieve host information 
	host_entry = gethostbyname(addr); 
	checkHostEntry(host_entry); 

	// To convert an Internet network 
	// address into ASCII string 
	IPbuffer = inet_ntoa(*((struct in_addr*) 
						host_entry->h_addr_list[0])); 

	printf("Host IP: %s", IPbuffer); 

	return 0; 
} 
