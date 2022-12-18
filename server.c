/**
 * @file server.c
 * @author zuh
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(
    int domain, 
    int service,
    int protocol,
    __u_long interface,
    int port,
    int backlog,
    void (*launch)(struct Server *server))
{
    struct Server server;
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    server.socket = socket(domain, service, protocol);
    if(server.socket == 0){
        perror("failed to connect socket ...\n");
        exit(1);
    }
    if(bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))<0){
        perror("failed to bind socket ...\n");
        exit(1);
    }
    if(listen(server.socket, server.backlog)<0){
        perror("failed to listen socket ...\n");
    }
    server.launch = launch;

    return server;
}
