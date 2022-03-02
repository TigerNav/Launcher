#include "networking.h"

int socket_desc;
struct sockaddr_in server_addr;

char server_message[1024];
char client_message[1024];
char colonbreak[10];

void 
ConnectToServer() {
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc < 0) {
        perror("\n Unable to create LE socket \n");
    }
    printf("Socket succ Created \n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.125");

    if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("\n Unable to connect \n");
    }

    printf("Connection with server succ \n");

    while(1) {

        if(recv(socket_desc, server_message, sizeof(server_message), 0) < 0) {
            printf("\n error in revicing message \n");
        }

        printf("%s",server_message);
        
    }
}

void
*NetworkThread(void *ptr) {
    ConnectToServer();
}



void 
SendMessage() {
    strcpy(client_message, getUsername());
    strcat(client_message, " : ");
    strcat(client_message, gtk_entry_get_text(GTK_ENTRY(getEntry())));
    strcat(client_message, "\n");
    if(send(socket_desc, client_message, sizeof(client_message), 0) < 0) {
        perror("\n shit didnt send \n");
    }

    
}
