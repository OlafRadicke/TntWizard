#include <iostream>
#include <string>
#include <vector>

#include "TypInfo.h"
#include "ComponentInfo.h"
#include "ViewCreator.h"

using namespace std; 


int main( int argc, char* argv[] )
{
    ComponentInfo compInfo = ComponentInfo();
    string argType = "";
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-H" || string(argv[i]) == "--help" ) {
            cout << "tntwizard -C <component name> <type> <typename>" << endl;
            cout << "Typs:" << endl;
            cout << "\t --text" << endl;
            cout << "\t --textarea" << endl;
            cout << "\t --password" << endl;
            cout << "\t --number" << endl;
            cout << "\t --select" << endl;
            cout << "" << endl;
            cout << "Examples:" << endl;
            cout << "tntwizard -C NewComponent --text LoginName --password PassWord" << endl;
            cout << "tntwizard -C MyComp --text UserName RealName --number UserID" << endl;
            break;
        }
        
        if ( string(argv[i]) == "-C" || string(argv[i]) == "--component" ) {
            argType = "--component";
            continue;
        }
        if ( string(argv[i]) == "-T" || string(argv[i]) == "--text" ) {
            argType = "--text";
            continue;
        }
        if ( string(argv[i]) == "-TE" || string(argv[i]) == "--textarea" ) {
            argType = "--textarea";
            continue;
        }
        if ( string(argv[i]) == "-PW" || string(argv[i]) == "--password" ) {
            argType = "--password";
            continue;
        }
        if ( string(argv[i]) == "-N" || string(argv[i]) == "--number" ) {
            argType = "--number";
            continue;
        }
        if ( string(argv[i]) == "-S" || string(argv[i]) == "select" ) {
            argType = "select";
            continue;
        }
        ///////////// is no argument. is a value... /////////////////
        if ( argType == "--component" ) {
            compInfo.Name = string(argv[i]);
            continue;
        }
        if ( argType == "--text" ) {
            TypInfo typInfo = TypInfo();
            typInfo.Type = "text";
            typInfo.Name = string(argv[i]);
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--textarea" ) {
            TypInfo typInfo = TypInfo();
            typInfo.Type = "textarea";
            typInfo.Name = string(argv[i]);
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--password" ) {
            TypInfo typInfo = TypInfo();
            typInfo.Type = "password";
            typInfo.Name = string(argv[i]);
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--number" ) {
            TypInfo typInfo = TypInfo();
            typInfo.Type = "number";
            typInfo.Name = string(argv[i]);
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--select" ) {
            TypInfo typInfo = TypInfo();
            typInfo.Type = "select";
            typInfo.Name = string(argv[i]);
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
    }
    ViewCreator vc( compInfo );
    vc.Run();
    cout << "Ende..." << endl;
}