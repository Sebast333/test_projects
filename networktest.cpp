#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <net/if.h>
#include <fstream>
#include <sys/ioctl.h>


int main() {
    // Get network interface information
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct ifreq ifr;
    ifr.ifr_addr.sa_family = AF_INET;
    ioctl(sockfd, SIOCGIFADDR, &ifr);

    // Get IP address
    struct sockaddr_in* addr = (struct sockaddr_in*)&ifr.ifr_addr;
    std::string ipAddress = inet_ntoa(addr->sin_addr);

    // Open network log file
    std::ofstream logFile("network_logs.txt");

    // Log IP address and other network information
    logFile << "IP Address: " << ipAddress << std::endl;

    // Close log file
    logFile.close();

    return 0;
}

