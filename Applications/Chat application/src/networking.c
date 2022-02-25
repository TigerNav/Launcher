#include "networking.h"

int socket_desc;
struct sockaddr_in server_addr;

char server_message[65000];
char client_message[65000];
char colonbreak[10];

void ConnectToServer() {
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc < 0) {
        perror("\n Unable to create LE socket \n");
    }
    printf("\n Socket succ Created \n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.125");

    if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("\n Unable to connect \n");
    }
    printf("\n Connection with server succ \n");

    if(recv(socket_desc, server_message, sizeof(server_message), 0) < 0) {
        perror("\n Error while reciving server's message \n");
    }

    printf("\n shit nigga \n");

    fflush(stdout);
}

void SendMessage() {
    strcpy(" : ",colonbreak);
    strcpy(strcat(strcat(getUsername(), colonbreak),gtk_entry_get_text(GTK_ENTRY(getEntry()))), client_message);
    if(send(socket_desc, client_message, sizeof(client_message), 0) < 0) {
        perror("\n shit didnt send \n");
    }

    
}