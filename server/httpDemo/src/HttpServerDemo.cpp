
#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"
#include "wfrest/json.hpp"
#include "./task/CXTaskManager.h"
#include <iostream>
using namespace std;
using namespace wfrest;
using Json = nlohmann::json;

#define UNUSED(x) (void)(x)

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo)
{
    UNUSED(signo);
    wait_group.done();
}

void buildTask()
{
    CXSubTask::ExecParam execParam;
    execParam.cmd = "python3";
    execParam.args.push_back("/mnt/d/code/private/test/linux/subProcess/1.py");
    CXTaskPtrVec pTaskPtrVec;

    int nCount = 2;
    for(int i = 0; i < nCount; i++)
    {
        CXTaskPtr pTaskPtr(new CXTask);
        for(int j = 0; j < nCount; j++)
        {
            CXSubTaskPtr pSubTaskPtr(new CXSubTask);
            pSubTaskPtr->m_execParam = execParam;
            pTaskPtr->m_pTaskVec.push_back(pSubTaskPtr);
        }
        pTaskPtrVec.push_back(pTaskPtr);
    }

    CXTaskManager taskManager;
    taskManager.m_pTaskVec = pTaskPtrVec;
    taskManager.Run();

    OutputVecGroup outputVecGroup;
    taskManager.GetOutputVecGroup(outputVecGroup);
    for(const auto& outputVec : outputVecGroup)
    {
        for(const auto& output : outputVec)
        {
            for (const auto &str : output.outputResult)
            {
                std::cout << str << std::endl;
            }
        }
    }
}

int main()
{
    signal(SIGINT, sig_handler);

    HttpServer svr;

    // curl -v http://ip:port/hello
    svr.GET("/hello", [](const HttpReq *req, HttpResp *resp)
    {
        UNUSED(req);
        resp->String("world\n");
    });
    // curl -v http://ip:port/data
    svr.GET("/data", [](const HttpReq *req, HttpResp *resp)
    {
        UNUSED(req);
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
        // reference, no copy here
        std::string& body = req->body();
        fprintf(stderr, "post data : %s\n", body.c_str());

        Json jsonReq;
        jsonReq = req->json();
        
        buildTask();

 #if 0       
        std::string str1 = "I got it--> !\n";
        std::string str2 = "I got it---> !\n";
        std::string str = str1 + str2;
        resp->String(str);
#else
        Json json;
        json["task"] = 123;
        json["result"] = "task result";
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

/**
 * @see postman test or curl  
 * 
 */