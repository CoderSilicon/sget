#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>

struct NetworkResponse {
    std::string html;
    std::string headers;
    long statusCode = 0;
    
    // New Low-Level Network Stats
    std::string remoteIp;
    long remotePort = 0;
    double totalTime = 0.0;
    double dnsTime = 0.0;
    double downloadSpeed = 0.0;
    long redirectCount = 0;
};

NetworkResponse fetchWebpage(const std::string& url);

#endif // NETWORK_HPP