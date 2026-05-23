#include "network.hpp"
#include <curl/curl.h>
#include <iostream>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    ((std::string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}

static size_t HeaderCallback(char* buffer, size_t size, size_t nitems, void* userdata) {
    size_t totalSize = size * nitems;
    ((std::string*)userdata)->append(buffer, totalSize);
    return totalSize;
}

NetworkResponse fetchWebpage(const std::string& url) {
    CURL* curl;
    CURLcode res;
    NetworkResponse response;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.html);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, HeaderCallback);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response.headers);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Trace/1.0");

        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            std::cerr << "Network error: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Extract HTTP Status
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.statusCode);
            
            // Extract Low-Level Telemetry
            char* ip;
            curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &ip);
            if(ip) response.remoteIp = ip;
            
            curl_easy_getinfo(curl, CURLINFO_PRIMARY_PORT, &response.remotePort);
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response.totalTime);
            curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &response.dnsTime);
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &response.downloadSpeed);
            curl_easy_getinfo(curl, CURLINFO_REDIRECT_COUNT, &response.redirectCount);
        }
        
        curl_easy_cleanup(curl);
    }
    return response;
}