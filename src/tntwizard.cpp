#include <iostream>
#include <string>
#include <vector>

#include "TypInfo.h"
#include "ComponentInfo.h"
#include "ControllerCreator.h"
#include "ModelCreator.h"
#include "ViewCreator.h"



int main( int argc, char* argv[] )
{
    ComponentInfo compInfo = ComponentInfo();
    std::string argType = "";
    for (int i = 1; i < argc; ++i) {
        if ( std::string(argv[i]) == "-H" || std::string(argv[i]) == "--help" ) {
            std::cout << "tntwizard -C <component name> <type> <typename>" << std::endl;
            std::cout << "Typs:" << std::endl;
            std::cout << "\t --text" << std::endl;
            std::cout << "\t --textarea" << std::endl;
            std::cout << "\t --password" << std::endl;
            std::cout << "\t --number" << std::endl;
            std::cout << "\t --select" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Examples:" << std::endl;
            std::cout << "tntwizard -C NewComponent --text LoginName --password PassWord" << std::endl;
            std::cout << "tntwizard -C MyComp --text UserName RealName --number UserID" << std::endl;
            break;
        }
        
        if ( std::string(argv[i]) == "-C" || std::string(argv[i]) == "--component" ) {
            argType = "--component";
            continue;
        }
        if ( std::string(argv[i]) == "-T" || std::string(argv[i]) == "--text" ) {
            argType = "--text";
            continue;
        }
        if ( std::string(argv[i]) == "-TE" || std::string(argv[i]) == "--textarea" ) {
            argType = "--textarea";
            continue;
        }
        if ( std::string(argv[i]) == "-PW" || std::string(argv[i]) == "--password" ) {
            argType = "--password";
            continue;
        }
        if ( std::string(argv[i]) == "-N" || std::string(argv[i]) == "--number" ) {
            argType = "--number";
            continue;
        }
        if ( std::string(argv[i]) == "-S" || std::string(argv[i]) == "--select" ) {
            argType = "select";
            continue;
        }
        if ( std::string(argv[i]) == "-S" || std::string(argv[i]) == "--checkbox" ) {
            argType = "checkbox";
            continue;
        }
        
        
        ///////////// is no argument. is a value... /////////////////
        if ( argType == "--component" ) {
            compInfo.Name =  std::string(argv[i]) ;
            continue;
        }
        if ( argType == "--text" ) {
            TypInfo typInfo = TypInfo();
            typInfo.setType("text");
            typInfo.setName( std::string(argv[i]) );
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--textarea" ) {
            TypInfo typInfo = TypInfo();
            typInfo.setType( "textarea" );
            typInfo.setName(  std::string(argv[i]) );
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--password" ) {
            TypInfo typInfo = TypInfo();
            typInfo.setType( "password" );
            typInfo.setName(  std::string(argv[i]) );
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--number" ) {
            TypInfo typInfo = TypInfo();
            typInfo.setType( "number" );
            typInfo.setName(  std::string(argv[i]) );
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--select" ) {
            TypInfo typInfo = TypInfo();
            typInfo.setType( "select" );
            typInfo.setName(  std::string(argv[i]) );
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        if ( argType == "--checkbox" ) {
            TypInfo typInfo = TypInfo();
            typInfo.setType( "checkbox" );
            typInfo.setName(  std::string(argv[i]) );
            compInfo.ComponentMembers.push_back( typInfo );
            continue;
        }
        
    }
    ViewCreator vc( compInfo );
    vc.Run();
    ControllerCreator cc( compInfo );
    cc.Run();
    ModelCreator mc( compInfo );
    mc.Run();
    std::cout << "Ende..." << std::endl;
}