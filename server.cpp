#include<iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <sys/timeb.h>
#include <sys/time.h>
using namespace std;

int main()
{
    int s_server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in ServerAddr;
    ServerAddr.sin_family = AF_INET;
    // ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_pton(AF_INET, "0.0.0.0", &ServerAddr.sin_addr);

    ServerAddr.sin_port = htons(1234);

    if (bind(s_server, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) < 0)
    {
        cout << "bind port error" << endl;
        return -1;
    }

    listen(s_server, 5);
    cout << "begin listenning" << endl;

    int s_client = accept(s_server, (struct sockaddr *)NULL, NULL);

    // warm-up
    int loop = 10;
    char* send_buf = new char[4096];
    char* recv_buf = new char[4096];
    while (loop)
    {
        memset(send_buf, 0, 4096);
        recv(s_client, send_buf, 4096, 0);
  
        memset(recv_buf, 0, 4096);
        send(s_client, recv_buf, 4096, 0);
        cout << "waiting" << endl;
        loop--;
    }

    cout << "test rtt" << endl;
    recv(s_client, send_buf, 4096, 0);
    send(s_client, recv_buf, 4096, 0);

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            recv(s_server, buf, size[i], 0);
            send(s_server, buf, size[i], 0);
        }
    }

	return 0;
}