
#include "http-request.h"
#include <string.h>
#include <stdlib.h>

int method_select(char *method)
{
    if(strcmp(method,"GET") == 0)
    {
        return GET;
    }
    else if(strcmp(method,"POST") == 0)
    {
        return POST;
    }
    else if(strcmp(method,"PUT") == 0)
    {
        return PUT;
    }
    else if(strcmp(method,"HEAD") == 0)
    {
        return HEAD;
    }
    else if(strcmp(method,"PATCH") == 0)
    {
        return PATCH;
    }
    else if(strcmp(method,"DELETE") == 0)
    {
        return DELETE;
    }
    else if(strcmp(method,"CONNECT") == 0)
    {
        return CONNECT;
    }
    else if(strcmp(method,"OPTIONS") == 0)
    {
        return OPTIONS;
    }
    else if(strcmp(method,"TRACE") == 0)
    {
        return TRACE;
    }
}

struct HTTP_Request http_request_constructor(char *request_string)
{
    struct HTTP_Request request;
    for (int i = 0; i < strlen(request_string)-1; i++)
    {
        if(request_string[i] == '\n' && request_string[i+1] == '\n')
        {
            request_string[i+1] = '|';
        }
    }
    char *request_line = strtok(request_string, "\n");
    char *header_field = strtok(request_string, "|");
    char *body = strtok(request_string, "|");
    

    char *method =strtok(request_line, " ");
    request.Method = method_select(method);
    char *URI = strtok(NULL, " ");
    request.URI = URI;
    char *HTTPVersion = strtok(NULL, "\n");
    HTTPVersion = strtok(HTTPVersion, "/");
    HTTPVersion = strtok(NULL, "/");
    request.HTTP_Version = (float)atof(HTTPVersion);
    
    
    return request;
}