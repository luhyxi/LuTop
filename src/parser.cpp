#include "parser.hpp"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

using lutop::Parser;
using lutop::Proc;
using lutop::Procs;
namespace fs = std::filesystem;

// Declaration of private functions
bool checkDirectoryIsProcess(string path);
void getStatusInfoFromProcess();
Proc getProcFromPath(fs::path path);

Procs Parser::getProcs() {
    Procs result;

    for (const auto &entry : fs::directory_iterator(m_procPath)) {
        string procNumber = entry.path().filename().string();

        if (checkDirectoryIsProcess(procNumber)) {
            continue;
        }

        result.processList.push_back(getProcFromPath(entry.path()));
    }

    result.quantityProcesses = result.processList.size();
    return result;
}

void Parser::printProcesses(Procs processes) {
    for (const auto process : processes) {
        std::putchar('\n');
        std::printf("Id: %s \n", process.id.c_str());
        std::printf("Name: %s \n", process.procName.c_str());
        std::printf("State: %s \n", process.procState.c_str());
        std::printf("Size: %s \n", process.procVmSize.c_str());
        std::putchar('\n');
    }
}

Proc getProcFromPath(fs::path path) {
    fs::path statusPath = path / "status";

    std::ifstream file(statusPath);
    if (!file.is_open()) {
        return {};
    }

    Proc p;
    p.id = path.filename().string();

    std::string line;
    size_t current = 1;

    while (std::getline(file, line)) {
        if (line.rfind("Name:", 0) == 0) {
            p.procName = line.substr(6);
        } else if (line.rfind("State:", 0) == 0) {
            p.procState = line.substr(7);
        } else if (line.rfind("VmSize:", 0) == 0) {
            p.procVmSize = line.substr(8);
        }
    }

    return p;
}

bool checkDirectoryIsProcess(string path) {
    return !std::isdigit(path.at(path.length() - 1));
}
