/**
 * @file test.c
 * @author zuh
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include "server.h"

void launch(struct Server *server)
{
    char buffer[30000];
    int flag;
    while(1)
    {
        printf("==== WAITING FOR CONNECTION ====\n");
        int address_len = sizeof(server->address);
        int new_socket = accept(
            server->socket, 
            (struct sockaddr *)&server->address, 
            (socklen_t *)&address_len);
        // read(new_socket, buffer, 30000);
        recv(new_socket, buffer, 30000, flag);
        printf("%s\n",buffer);
        char *hello =   "HTTP/1.1 200 OK\n"
                        "Date: Mon, 27 Jul 2009 12:28:53 GMT\n"
                        "Server: Apache/2.2.14 (Win32)\n"
                        "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n"
                        "Content-Length: 88\n"
                        "Content-Type: text/html\n"
                        "Connection: Closed\n"
                        "<html><body><h1>Home Deus</h1></body></html>";
        // write(new_socket, hello, strlen(hello));
        send(new_socket, hello, 1000, flag);
        shutdown(new_socket, SHUT_RDWR);
    }
}

int main()
{
    struct Server server = server_constructor(
        AF_INET,
        SOCK_STREAM,
        0,
        INADDR_ANY,
        80,
        10,
        launch
    );
    server.launch(&server);

}