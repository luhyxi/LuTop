#pragma once

#include <filesystem>
#include <string>
#include <vector>

using string = std::string;

namespace lutop {
    struct Proc {
        string id {"-1"};
        string procName {"unknownName"};
        string procState {"unknownState"};
        string procVmSize {"unknownVmSize"};
    };

    struct Procs {
        int quantityProcesses {0};
        std::vector<Proc> processList {};
        std::vector<Proc>::iterator begin() { return processList.begin(); }
        std::vector<Proc>::iterator end() { return processList.end(); }
    };

    class Parser {
      public:
        Procs getProcs();
        Procs getProc();
        void printProcesses(Procs processes);

      private:
        std::filesystem::path m_procPath {"/proc"};
    };
} // namespace lutop
