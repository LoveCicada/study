
#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"
#include "wfrest/json.hpp"
#include <thread>
#include <chrono>
#include <sstream>

using namespace wfrest;
using Json = nlohmann::json;

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo)
{
    wait_group.done();
}

int main()
{
    signal(SIGINT, sig_handler);

    HttpServer svr;

    // curl -v http://ip:port/hello
    svr.GET("/hello", [](const HttpReq *req, HttpResp *resp)
    {
        resp->String("world\n");
    });
    // curl -v http://ip:port/data
    svr.GET("/data", [](const HttpReq *req, HttpResp *resp)
    {
        std::string str = "Hello world";
        resp->String(std::move(str));
    });

    svr.ROUTE("/multi", [](const HttpReq *req, HttpResp *resp)
    {
        std::string method(req->get_method());
        resp->String(std::move(method));
    }, {"GET", "POST"});

    // curl -v http://ip:port/post -d 'post hello world'
    svr.POST("/post", [](const HttpReq *req, HttpResp *resp)
    {

        std::thread::id _tid = std::this_thread::get_id();
        std::stringstream ss;
        ss << _tid;
        // reference, no copy here
        std::string& body = req->body();
        fprintf(stderr, "post data : %s, _tid: %s\n", body.c_str(), ss.str().c_str());
        
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
 #if 0       
        std::string str1 = "I got it--> !\n";
        std::string str2 = "I got it---> !\n";
        std::string str = str1 + str2;
        resp->String(str);
#else
        Json json;
        json["test"] = 123;
        json["json"] = "test json";
        resp->Json(json);
#endif
        
    });

    if (svr.track().start(8888) == 0)
    {
        svr.list_routes();
        wait_group.wait();
        svr.stop();
    } else
    {
        fprintf(stderr, "Cannot start server");
        exit(1);
    }
    return 0;
}