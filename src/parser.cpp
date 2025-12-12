#include "parser.hpp"
#include <cstdio>
#include <vector>

using lutop::Parser;
using lutop::Processes;

Processes Parser::getProcesses() {
    Processes result;

    for (const auto &entry : std::filesystem::directory_iterator(m_procPath)) {
        result.processList.push_back({
            entry.path().string(),
            ""
        });
    }

    result.quantityProcesses = result.processList.size();
    return result;
}

Processes Parser::getProcess() { return Processes{}; }

void Parser::printProcesses(lutop::Processes processes) { 
    for (const auto process : processes) {
        std::printf("%s", process.ID.c_str());
    }
}
