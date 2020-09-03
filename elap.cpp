#include "ArgParser.h"
using namespace std;

int main(int argc, char *argv[]) {
    elap::ArgParser parser;
    parser.addCommand("cmdA", 0, INT32_MAX);
    parser.addCommand("cmdB", 0, INT32_MAX);
    parser.addCommand("cmdC", 1, INT32_MAX);
    parser.addParam('a', "a", 0, 0);
    parser.addParam('b', "b", 0, 0);
    parser.addParam('v', "verbose", 0, 1);
    parser.addParam('f', "force", 1, INT32_MAX);

    for (int i=1; i<argc; i++) cout<<argv[i]<<endl;

    cout << "==" << endl;

    if (!parser.parse(argc, argv)) {
        cout << parser.getError() << endl << endl;
        return 1;
    }
    elap::Param* cmd = parser.getCommand();
    if (cmd!= nullptr) {
        cout <<cmd->name;
        for (auto opt:cmd->options) {
            cout << " "<< opt;
        }
        cout << endl;
    }

    auto parvec = parser.getParams();
    for (auto par: parvec) {
        cout <<par->name;
        for (auto opt:par->options) {
            cout << " "<< opt;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
