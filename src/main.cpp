#include "parser.hpp"

int main(int argc, char *argv[]) {
    lutop::Parser parser{};
    auto processes = parser.getProcs();
    parser.printProcesses(processes);
    return 0;
}
