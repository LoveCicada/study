
#include "RDWebSocketServer.h"
#include <iostream>
using namespace std;

int main(int argc, char *arg[]) {
    static_cast<int>(argc);
    static_cast<char**>(arg);
    cout << "server" << endl;

    RDWebSocketServer server;
    server.Listen(9090);

    return 0;
}
