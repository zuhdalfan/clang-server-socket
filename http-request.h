/**
 * @file HTTPRequest.h
 * @author zuh
 * @brief 
 * @version 0.1
 * @date 2022-12-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef http_request_h
#define http_request_h

enum HTTP_Methods
{
    GET,
    POST,
    PUT,
    HEAD,
    PATCH,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE
};

struct HTTP_Request
{
    int Method;
    char *URI;
    float HTTP_Version;
};

struct HTTP_Request http_request_constructor(char *request_string);

#endif