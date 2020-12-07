#include "TaskWatcher.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

TaskWatcher taskWatcher;

TaskWatcher::TaskWatcher() {
}

TaskWatcher::~TaskWatcher() {
}

void TaskWatcher::onLaunched(const std::vector<std::string>& parameters)
{
}

std::string TaskWatcher::onParameterRecieved(const std::string& pp)
{
    char macs[6][4], ip[256];
    sscanf(pp.c_str(), "%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]",
        macs[0], macs[1], macs[2],
        macs[3], macs[4], macs[5], ip
    );

    uint8_t mac[6];
    mac[0] = strtoul(macs[0], NULL, 16);
    mac[1] = strtoul(macs[1], NULL, 16);
    mac[2] = strtoul(macs[2], NULL, 16);
    mac[3] = strtoul(macs[3], NULL, 16);
    mac[4] = strtoul(macs[4], NULL, 16);
    mac[5] = strtoul(macs[5], NULL, 16);

    uint8_t buf[102] = {255, 255, 255, 255, 255, 255};
    for (int i=0; i<16; ++i) {
        memcpy(buf + (i+1)*6, mac, 6);
    }

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    int optval = 1;
    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &optval, 4);
    if (s < 0) {
        exit(0);
    }

    sockaddr_in addr;
    addr.sin_port = ntohs(10000);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    sendto(s, buf, sizeof(buf), 0, (sockaddr*)&addr, sizeof(addr));
    close(s);

    return pp;
}
