
#include "wfrest/HttpServer.h"
using namespace wfrest;

int main(int argc, char* argv[])
{
    HttpServer server;
    server.GET("/hello", [](const HttpReq* req, HttpResp* resp)
    {
        resp->String("world\n");
    });

    if(server.start(8888) == 0)
    {
        getchar();
        server.stop();
    }else
    {
        fprintf(stderr, "Cannot start server\n");
    }

    return 0;
}

/**
 * @test 
 * ./HttpServerDemo
 * 
 * curl -v http://127.0.0.1:8888/hello
 * 
 * curl -v http://ip:port/hello
 * 
 */