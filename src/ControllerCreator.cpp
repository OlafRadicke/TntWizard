
#include "ControllerCreator.h"

std::string const ControllerCreator::getEcppArgs ( void ) const {
    std::string argsOutput = "";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        argsOutput += "\t " + m_compInfo.getMemberCType( i );
        argsOutput += " " + m_compInfo.ComponentMembers[i].getType() + ";\n";        
    }
    return argsOutput;
}

void ControllerCreator::Run ( void ) {
    std::string controllOutput = "";
    controllOutput += "";
    
    controllOutput += "<%pre> \n";
    controllOutput += "</%pre> \n \n";

    controllOutput += "<%config> \n";
    controllOutput += "</%config> \n \n";

    controllOutput += "<%args> \n";
    controllOutput += this->getEcppArgs ();
    controllOutput += "</%args> \n \n";

    controllOutput += "<%session scope=\"global\"> \n";
    controllOutput += "</%session> \n \n";

    
    controllOutput += "<%cpp> \n";
    controllOutput += "\tstd::string feedback = \"\"; \n";
    controllOutput += "\t" + m_compInfo.getName() + " object" + m_compInfo.getName() + "; \n \n";
    controllOutput += "\t// is button \"save_button\" kicked? \n";
    controllOutput += "\tif ( save_button == \"save_pressed\" ) { \n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        if ( m_compInfo.ComponentMembers[i].getType() == "checkbox" ) {
            controllOutput += "\t\tif ( is_private_data == \"false\" ) {\n";
                controllOutput += "\t\t\tobject" + m_compInfo.getName() + ".set" + \
                    m_compInfo.ComponentMembers[i].getName() + \
                    "( false ); \n";
            controllOutput += "\t\t} else {\n";
                controllOutput += "\t\t\tobject" + m_compInfo.getName() + ".set" + \
                    m_compInfo.ComponentMembers[i].getName() + \
                    "( false ); \n";
            controllOutput += "\t\t} \n";
        } else {
            controllOutput += "\t\tobject" + m_compInfo.getName() + ".set" + \
                m_compInfo.ComponentMembers[i].getName() + \
                "( " + m_compInfo.ComponentMembers[i].getName() + " ); \n";
        }
    }    

    controllOutput += "\t\tobject" + m_compInfo.getName() + ".saveAsNew( ); \n";
    controllOutput += "\t\tfeedback = \"Data is stored!\"; \n";
    controllOutput += "\t}  \n";
    controllOutput += "</%cpp> \n";
   
    createDir ( "controller" );
    writingFile ( "controller/" + m_compInfo.getName() + "Controller.ecpp", controllOutput);
}

