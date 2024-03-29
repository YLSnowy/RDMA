#include <iostream>
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
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
    int s_server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1234);
    // inet_pton(AF_INET, "15.15.15.5", &serverAddr.sin_addr);
    inet_pton(AF_INET, argv[1], &serverAddr.sin_addr);

    if (connect(s_server, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        cout << "connect error" << endl;
        return 0;
    }

    int loop = 10;
    char buf[4096];
    while (loop)
    {
        send(s_server, buf, 4096, 0);
        recv(s_server, buf, 4096, 0);
        cout << "waiting" << endl;
        loop--;
    }

    cout << "test rtt" << endl;
    clock_t start, end;
    start = clock();
    send(s_server, buf, 1, 0);
    recv(s_server, buf, 1, 0);
    end = clock();
    double rtt = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "rtt = " << rtt << endl;

    int size[20] = {1, 2, 4, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    for (int i = 0; i < 13; i++)
    {
        double sum_time = 0;
        for (int j = 0; j < 10; j++)
        {
            char *send_buf = new char[size[i]];
            memset(send_buf, 0, sizeof(send_buf));
            start = clock();
            int ret = send(s_server, buf, size[i], 0);
            if (ret < 0)
            {
                cout << "send error" << endl;
                return 0;
            }
            ret = recv(s_server, buf, size[i], 0);
            if (ret < 0)
            {
                cout << "recv error" << endl;
                return 0;
            }
            end = clock();
            sum_time += (double)(end - start) / CLOCKS_PER_SEC;
        }
        cout << size[i] * 8 << (size[i] * 8 / (sum_time / 10)) / 1e8 << "Mbps" << endl;
    }
    cout << 1234567 << endl;
    return 0;
}