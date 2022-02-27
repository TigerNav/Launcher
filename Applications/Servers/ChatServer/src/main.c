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

char getmessage[65000];
char sendmessage[65000];


void *EchoThread(void *ptr) {

    while(1) {

        int client_sock = accept(socket_desc, (struct sockaddr*) &Client_Address, (socklen_t*)&client_size);
        if(client_sock < 0){
            printf("\n Server could not accept socket connection \n");
        }
        printf("\n Client Join from port : %i \n Client Join from IP : %i \n", Client_Address.sin_port, Client_Address.sin_addr.s_addr);

        if(recv(client_sock, getmessage, sizeof(getmessage), 0) < 0) {
            perror("\n cant recive anything from client \n");
        }
        printf("Message recived to client \n");
        

        printf("%s \n", getmessage);


        if(send(client_sock, getmessage, sizeof(getmessage), 0) < 0) { 
            perror("\n Error with sending message \n");
        }
        printf("Message sent to client \n");

        
        
    }

}

int main() {

    // Socket Descriptor (a pointer of arrays)
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc < 0) {
        printf("\n shit fuck \n");
        return 1;
    }

    // Defines Connection outside machine
    Server_Address.sin_family       = AF_INET;
    // Opening Port
    Server_Address.sin_port         = htons(PORT);
    // IP
    Server_Address.sin_addr.s_addr  = inet_addr("192.168.1.125");


    // Binds server to port and IP

    if(bind(socket_desc, (struct sockaddr*) &Server_Address, sizeof(Server_Address)) < 0) {
        printf("\nError while trying to bind\n");
        return 1;
    }

    printf("\n Accepted Bind \n");
    
    // Find any clients that are trying to join
    if(listen(socket_desc, 1) < 0) {
        printf("\n Could not find any clients \n");
        return 1;
    }
    printf("\n Searching for clients \n");



    while(1) {
        // Accepting any incoming connections
        client_size = sizeof(Client_Address);
           
        
        
        pthread_create(&thread, NULL, &EchoThread, NULL);
        pthread_join(thread, NULL);

        

    }

    
    return 0;

}