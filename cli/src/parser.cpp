#include "parser.hpp"
#include "colors.hpp"
#include <iostream>
#include <regex>
#include <algorithm>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string extractRegex(const std::string &text, const std::regex &pattern)
{
    std::smatch match;
    if (std::regex_search(text, match, pattern) && match.size() > 1)
    {
        return match[1].str();
    }
    return "Not found";
}

PageInfo parseData(const NetworkResponse &netData, const std::string &url)
{
    PageInfo info;
    info.url = url;
    info.statusCode = netData.statusCode;
    info.sizeBytes = netData.html.size();

    // Save the raw HTML data
    info.rawHtml = netData.html;

    std::regex serverRegex("Server: ([^\r\n]+)");
    std::regex typeRegex("Content-Type: ([^\r\n]+)");
    info.server = extractRegex(netData.headers, serverRegex);
    info.contentType = extractRegex(netData.headers, typeRegex);

    std::regex titleRegex("<title>([^<]*)</title>", std::regex_constants::icase);
    std::regex descRegex("<meta[^>]+name=[\"']description[\"'][^>]+content=[\"']([^\"']+)[\"']", std::regex_constants::icase);
    std::regex iconRegex("<link[^>]+rel=[\"'](?:shortcut )?icon[\"'][^>]+href=[\"']([^\"']+)[\"']", std::regex_constants::icase);

    info.title = extractRegex(netData.html, titleRegex);
    info.description = extractRegex(netData.html, descRegex);
    info.logoUrl = extractRegex(netData.html, iconRegex);

    info.rawHeaders = netData.headers;
    info.remoteIp = netData.remoteIp;
    info.remotePort = netData.remotePort;
    info.totalTime = netData.totalTime;
    info.dnsTime = netData.dnsTime;
    info.downloadSpeed = netData.downloadSpeed;
    info.redirectCount = netData.redirectCount;

    return info;
}

void printInfoMode(const PageInfo &info)
{
    std::string statusColor = Color::GREEN;
    if (info.statusCode >= 400)
    {
        statusColor = Color::RED;
    }
    else if (info.statusCode >= 300)
    {
        statusColor = Color::YELLOW;
    }

    std::cout << Color::CYAN << Color::BOLD << "\n=== Inspected Data ===" << Color::RESET << std::endl;

    std::cout << Color::MAGENTA << Color::BOLD << "[  ]" << Color::RESET << std::endl;
    std::cout << Color::BOLD << "URL:          " << Color::RESET << Color::GRAY << info.url << Color::RESET << std::endl;
    std::cout << Color::BOLD << "Status Code:  " << Color::RESET << statusColor << Color::BOLD << info.statusCode << Color::RESET << std::endl;
    std::cout << Color::BOLD << "Server:       " << Color::RESET << info.server << std::endl;
    std::cout << Color::BOLD << "Content-Type: " << Color::RESET << info.contentType << std::endl;
    std::cout << Color::BOLD << "Page Size:    " << Color::RESET << Color::GREEN << info.sizeBytes << " bytes" << Color::RESET << "\n"
              << std::endl;

    std::cout << Color::MAGENTA << Color::BOLD << "[ METADATA ]" << Color::RESET << std::endl;
    std::cout << Color::BOLD << "Title:        " << Color::RESET << Color::YELLOW << info.title << Color::RESET << std::endl;
    std::cout << Color::BOLD << "Description:  " << Color::RESET << info.description << std::endl;
    std::cout << Color::BOLD << "Logo/Favicon: " << Color::RESET << Color::GRAY << info.logoUrl << Color::RESET << "\n"
              << std::endl;

    std::cout << Color::MAGENTA << Color::BOLD << "[ Raw Data Preview ]" << Color::RESET << std::endl;
    size_t previewLength = std::min(info.rawHtml.length(), (size_t)150);
    std::cout << Color::GRAY << info.rawHtml.substr(0, previewLength) << "...\n"
              << Color::RESET;

    std::cout << Color::CYAN << Color::BOLD << "=====================\n"
              << Color::RESET << std::endl;
}

void printDetailedMode(const PageInfo &info)
{
    std::string statusColor = (info.statusCode >= 400) ? Color::RED : (info.statusCode >= 300 ? Color::YELLOW : Color::GREEN);

    std::cout << Color::CYAN << Color::BOLD << "\n=== [ TRACE ADVANCED AUDIT ] ===" << Color::RESET << std::endl;

    std::cout << Color::MAGENTA << Color::BOLD << "\n[ SOCKET & TELEMETRY ]" << Color::RESET << std::endl;
    std::cout << Color::BOLD << "Target URL:       " << Color::RESET << info.url << std::endl;
    std::cout << Color::BOLD << "Remote IP:        " << Color::RESET << Color::YELLOW << info.remoteIp << Color::RESET << ":" << info.remotePort << std::endl;
    std::cout << Color::BOLD << "Status Code:      " << Color::RESET << statusColor << Color::BOLD << info.statusCode << Color::RESET << std::endl;
    std::cout << Color::BOLD << "DNS Lookup Time:  " << Color::RESET << info.dnsTime << " seconds" << std::endl;
    std::cout << Color::BOLD << "Total Fetch Time: " << Color::RESET << info.totalTime << " seconds" << std::endl;
    std::cout << Color::BOLD << "Download Speed:   " << Color::RESET << (info.downloadSpeed / 1024.0) << " KB/s" << std::endl;
    std::cout << Color::BOLD << "Redirects Followed: " << Color::RESET << info.redirectCount << std::endl;

    std::cout << Color::MAGENTA << Color::BOLD << "\n[ WEBPAGE METADATA ]" << Color::RESET << std::endl;
    std::cout << Color::BOLD << "Title:            " << Color::RESET << info.title << std::endl;
    std::cout << Color::BOLD << "Description:      " << Color::RESET << info.description << std::endl;
    std::cout << Color::BOLD << "Favicon/Logo:     " << Color::RESET << info.logoUrl << std::endl;

    std::cout << Color::MAGENTA << Color::BOLD << "\n[ RAW HTTP RESPONSE HEADERS ]" << Color::RESET << std::endl;
    std::cout << Color::GRAY << info.rawHeaders << Color::RESET; // Dumps the exact block from the server

    std::cout << Color::CYAN << Color::BOLD << "================================" << Color::RESET << "\n"
              << std::endl;
}

void printJsonMode(const PageInfo &info)
{
    json j;
    j["url"] = info.url;
    j["status_code"] = info.statusCode;
    j["size_bytes"] = info.sizeBytes;

    j["headers"]["server"] = info.server;
    j["headers"]["content_type"] = info.contentType;

    j["metadata"]["title"] = info.title;
    j["metadata"]["description"] = info.description;
    j["metadata"]["logo"] = info.logoUrl;

    // Add the full raw HTML to the JSON output
    j["raw_html"] = info.rawHtml;

    std::cout << j.dump(4) << std::endl;
}