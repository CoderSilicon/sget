#include <iostream>
#include <string>
#include <vector>
#include "network.hpp"
#include "parser.hpp"
#include "colors.hpp" 

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

enum class RunMode
{
    INFO,
    BINFO,
    JSON,
    INVALID
};

// 2. Configuration State
struct AppConfig
{
    std::string url = "";
    RunMode mode = RunMode::INFO;
    bool exitEarly = false;
};

// --- Terminal Commands ---

void printHelp()
{
    std::cout << "\n"
              << Color::CYAN << Color::BOLD << "sget" << Color::RESET
              << " - Web Data Extractor\n\n";

    std::cout << Color::YELLOW << "USAGE:" << Color::RESET << "\n";
    std::cout << "  sget [options] <URL>\n\n";

    std::cout << Color::YELLOW << "EXTRACTION MODES:" << Color::RESET << "\n";
    std::cout << "  " << Color::GREEN << "--info" << Color::RESET << "      Standard metadata extraction (Default)\n";
    std::cout << "  " << Color::GREEN << "--binfo" << Color::RESET << "     Deep and detailed header extraction\n";
    std::cout << "  " << Color::GREEN << "--json" << Color::RESET << "      Raw JSONextraction\n\n";

    std::cout << Color::YELLOW << "SYSTEM FLAGS:" << Color::RESET << "\n";
    std::cout << "  " << Color::GREEN << "--help" << Color::RESET << "      Manual\n";
    std::cout << "  " << Color::GREEN << "--version" << Color::RESET << "   Display core compiler version\n";
    std::cout << "  " << Color::GREEN << "--author" << Color::RESET << "    Display the dev\n\n";

    std::cout << Color::GRAY << "Example: sget --json https://google.com" << Color::RESET << "\n\n";
}

void printVersion()
{
    std::cout << Color::CYAN << "sget " << Color::RESET
              << "version " << Color::BOLD << "1.0.0-core" << Color::RESET << "\n";
}

void printAuthor()
{
    std::cout << "Engineered by " << Color::GREEN << Color::BOLD << "@coderSilicon" << Color::RESET
              << "\n"
              << Color::GRAY << "> It is always better to differ from others." << Color::RESET << "\n";
}

// 3. The Parser Engine
AppConfig parseCLI(const std::vector<std::string> &args)
{
    AppConfig config;

    for (const auto &arg : args)
    {
        // Non-network modes
        if (arg == "--help" || arg == "-h")
        {
            printHelp();
            config.exitEarly = true;
            return config;
        }
        else if (arg == "--version" || arg == "-v")
        {
            printVersion();
            config.exitEarly = true;
            return config;
        }
        else if (arg == "--author")
        {
            printAuthor();
            config.exitEarly = true;
            return config;
        }
        // True Modes
        else if (arg == "--info")
        {
            config.mode = RunMode::INFO;
        }
        else if (arg == "--binfo")
        {
            config.mode = RunMode::BINFO;
        }
        else if (arg == "--json")
        {
            config.mode = RunMode::JSON;
        }
        // Catch unknown flags
        else if (arg.rfind("--", 0) == 0 || arg.rfind("-", 0) == 0)
        {
            std::cerr << Color::RED << "Error: Unknown flag '" << arg << "'\n"
                      << Color::RESET;
            std::cerr << "Run " << Color::GREEN << "sget --help" << Color::RESET << " for valid options.\n";
            config.mode = RunMode::INVALID;
            config.exitEarly = true;
            return config;
        }
        else
        {
            config.url = arg;
        }
    }
    return config;
}

// Main
int main(int argc, char *argv[])
{
    enableWindowsColors();

    std::vector<std::string> args(argv + 1, argv + argc);

    if (args.empty())
    {
        std::cerr << Color::RED << "Error: No target specified.\n"
                  << Color::RESET;
        std::cerr << "Usage: sget [flag] <URL>\n";
        return 1;
    }

    AppConfig config = parseCLI(args);

    if (config.exitEarly)
    {
        return 0;
    }

    if (config.url.empty())
    {
        std::cerr << Color::RED << "Error: Missing target URL.\n"
                  << Color::RESET;
        return 1;
    }

    NetworkResponse response = fetchWebpage(config.url);

    if (response.html.empty() && response.headers.empty())
    {
        std::cerr << Color::RED << "Fatal: Failed to fetch or received empty response." << Color::RESET << "\n";
        return 1;
    }

    PageInfo info = parseData(response, config.url);

    switch (config.mode)
    {
    case RunMode::INFO:
        printInfoMode(info);
        break;
    case RunMode::BINFO:
        printDetailedMode(info);
        break;
    case RunMode::JSON:
        printJsonMode(info);
        break;
    case RunMode::INVALID:
        return 1;
    }

    return 0;
}