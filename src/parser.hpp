#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using string = std::string;

namespace lutop {
    struct Process {
        string ID{"-1"};
        string Info{""};
    };

    struct Processes {
        int quantityProcesses{0};
        std::vector<Process> processList{};
        std::vector<Process>::iterator begin() { return processList.begin(); }
        std::vector<Process>::iterator end() { return processList.end(); }
    };

    class Parser {
      public:
        Processes getProcesses();
        Processes getProcess();
        void printProcesses(Processes processes);

      private:
        fs::path m_procPath{"/proc"};
    };
} // namespace lutop
