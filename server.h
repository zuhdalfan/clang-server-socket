/**
 * @file server.h
 * @author zuh
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

struct Server
{
    int domain;
    int service;
    int protocol;
    __u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;
    int socket;

    void (*launch)(struct Server *server);
};

struct Server server_constructor(
    int domain, 
    int service,
    int protocol,
    __u_long interface,
    int port,
    int backlog,
    void (*launch)(struct Server *server));


#endif