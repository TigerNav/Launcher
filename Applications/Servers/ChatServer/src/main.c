////////////  Chat Room Server Code ////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAXCLIENTS 999999
#define PORT 5000

int socket_desc, client_sock, client_size;

// This will store all the server address data like ports and IP
struct sockaddr_in Server_Address;

// Will act like a client in the server and store all the data of the client
struct sockaddr_in Client_Address;

pthread_t thread;
pthread_t thread_array[MAXCLIENTS];

char getmessage[65000];
char sendmessage[65000];

int client_message;

void *EchoThread(void *ptr) {

    int new_socket = *((int *)ptr);

    while(1) {

        
        client_message = recv(new_socket, getmessage, sizeof(getmessage + 1), 0);

        if(client_message < 0) {
            perror("\n cant recive anything from client \n");
            exit(1);
        }
        printf("Message recived to client \n");
        

        printf("%s", getmessage);

        
        if((send(new_socket, getmessage, sizeof(getmessage + 1), 0)) == -1) { 
            perror("\n Error with sending message \n");
            exit(1);
        }
        printf("Message sent to client \n");

        sleep(1);

        
        
    }

}

int main() {

    // Socket Descriptor (a pointer of arrays)
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc < 0) {
        printf("\n shit fuck \n");
        exit(1);
    }

    // Defines Connection outside machine
    Server_Address.sin_family       = AF_INET;
    // Opening Port
    Server_Address.sin_port         = htons(PORT);
    // IP
    Server_Address.sin_addr.s_addr  = inet_addr("192.168.1.125");


    // Binds server to port and IP

    if((bind(socket_desc, (struct sockaddr*) &Server_Address, sizeof(Server_Address))) < 0) {
        perror("Error while trying to bind");
        exit(1);
    }

    printf("\n Accepted Bind \n");
    
    // Find any clients that are trying to join
    if((listen(socket_desc, 1)) < 0) {
        printf("\n Could not find any clients \n");
    }
    printf("\n Searching for clients \n");


    while(1) {
        // Accepting any incoming connections
        client_size = sizeof(Client_Address);
           
        int client_sock = accept(socket_desc, (struct sockaddr*) &Client_Address, (socklen_t*)&client_size);
        if(client_sock < 0){
            printf("\n Server could not accept socket connection \n");
        }
        printf("\n Client Join from port : %i \n Client Join from IP : %i \n", Client_Address.sin_port, Client_Address.sin_addr.s_addr);
        
        pthread_create(&thread, NULL, &EchoThread, &client_sock);
        
    }
    return 0;
}