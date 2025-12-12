#include "parser.hpp"

int main(int argc, char *argv[]) {
    lutop::Parser parser{};
    auto processes = parser.getProcesses();
    parser.printProcesses(processes);
    return 0;
}
