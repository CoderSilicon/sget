#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include "network.hpp"

struct PageInfo {
    std::string url;
    long statusCode;
    size_t sizeBytes;
    
    // Raw Data
    std::string rawHtml;
    std::string rawHeaders; // To dump the literal HTTP headers
    
    // HTML Metadata
    std::string title;
    std::string description;
    std::string logoUrl;
    
    // HTTP Header Data
    std::string server;
    std::string contentType;

    // Advanced Telemetry
    std::string remoteIp;
    long remotePort;
    double totalTime;
    double dnsTime;
    double downloadSpeed;
    long redirectCount;
};

PageInfo parseData(const NetworkResponse& netData, const std::string& url);

void printInfoMode(const PageInfo& info);
void printJsonMode(const PageInfo& info);
void printDetailedMode(const PageInfo& info); // <--- NEW FUNCTION

#endif // PARSER_HPP