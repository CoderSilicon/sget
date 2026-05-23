#include <iostream>
#include <string>
#include "network.hpp"
#include "parser.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void enableWindowsColors()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode))
        {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " [flag] <URL>\n";
        std::cerr << "Use -h flag to open the documentation\n";
        return 1;
    }

    std::string flag = argv[1];
    std::string url = argv[2];

    // Fetch the response (now includes headers and status code)
    NetworkResponse response = fetchWebpage(url);

    if (response.html.empty() && response.headers.empty())
    {
        std::cerr << "Failed to fetch or received empty response." << std::endl;
        return 1;
    }

    // Pass the full response to the parser
    PageInfo info = parseData(response, url);

    if (flag == "-i")
    {
        printInfoMode(info);
    }
    else if (flag == "-id")
    {
        printDetailedMode(info);
    }
    else if (flag == "-jq")
    {
        printJsonMode(info);
    }
    else
    {
        std::cerr << "Unknown flag: " << flag << "\nUse -i or -jq." << std::endl;
        return 1;
    }

    return 0;
}