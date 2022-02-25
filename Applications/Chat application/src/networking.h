#ifndef NETWORKING_H
#define NETWORKING_H
#define PORT 5000
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <gtk/gtk.h>
#include "ui_elements.h"
#include "json_info.h"


void EchoThread();
void ConnectToServer();
void SendMessage();


#endif