
#include "CrontollerCreator.h"

string CrontollerCreator::getEcppArgs ( void ) {
    string argsOutput = "";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        argsOutput += "\t " + m_compInfo.htmlToCType( i );
        argsOutput += " " + m_compInfo.ComponentMembers[i].Type + ";\n";        
    }
    return argsOutput;
}

void CrontollerCreator::Run ( void ) {
    string controllOutput = "";
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
    controllOutput += "\t" + m_compInfo.Name + " object" + m_compInfo.Name + "; \n \n";
    controllOutput += "\t// is button \"save_button\" kicked? \n";
    controllOutput += "\tif ( save_button == \"save_pressed\" ) { \n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        if ( m_compInfo.ComponentMembers[i].Type == "checkbox" ) {
            controllOutput += "\t\tif ( is_private_data == \"false\" ) {\n";
                controllOutput += "\t\t\tobject" + m_compInfo.Name + ".set" + \
                    m_compInfo.ComponentMembers[i].Name + \
                    "( false ); \n";
            controllOutput += "\t\t} else {\n";
                controllOutput += "\t\t\tobject" + m_compInfo.Name + ".set" + \
                    m_compInfo.ComponentMembers[i].Name + \
                    "( false ); \n";
            controllOutput += "\t\t} \n";
        } else {
            controllOutput += "\t\tobject" + m_compInfo.Name + ".set" + \
                m_compInfo.ComponentMembers[i].Name + \
                "( " + m_compInfo.ComponentMembers[i].Name + " ); \n";
        }
    }    

    controllOutput += "\t\t" + m_compInfo.Name + ".saveAsNew( ); \n";
    controllOutput += "\t\tfeedback = \"Data is stored!\"; \n";
    controllOutput += "\t}  \n";
    controllOutput += "</%cpp> \n";
   
    createDir ( "controller" );
    writingFile ( "controller/" + m_compInfo.Name + "Controller.ecpp", controllOutput);
}

