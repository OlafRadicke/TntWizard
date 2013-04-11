
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
    string viewOutput = "";
    viewOutput += "";
    
///////////////////////////////////////////////////////////////////////////
    
    viewOutput += "<%pre> \n";
    viewOutput += "</%pre> \n \n";

    viewOutput += "<%config> \n";
    viewOutput += "</%config> \n \n";

    viewOutput += "<%args> \n";
    viewOutput += this->getEcppArgs ();
    viewOutput += "</%args> \n \n";

    viewOutput += "<%session scope=\"global\"> \n";
    viewOutput += "</%session> \n \n";

    
    viewOutput += "<%cpp> \n";
    viewOutput += "\tstd::string feedback = \"\"; \n";
    viewOutput += "\t" + m_compInfo.Name + " object" + m_compInfo.Name + "; \n \n";
    viewOutput += "\t// is button \"save_button\" kicked? \n";
    viewOutput += "\tif ( save_button == \"save_pressed\" ) { \n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        if ( m_compInfo.ComponentMembers[i].Type == "checkbox" ) {
            viewOutput += "\t\tif ( is_private_data == \"false\" ) {\n";
                viewOutput += "\t\t\tobject" + m_compInfo.Name + ".set" + \
                    m_compInfo.ComponentMembers[i].Name + \
                    "( false ); \n";
            viewOutput += "\t\t} else {\n";
                viewOutput += "\t\t\tobject" + m_compInfo.Name + ".set" + \
                    m_compInfo.ComponentMembers[i].Name + \
                    "( false ); \n";
            viewOutput += "\t\t} \n";
        } else {
            viewOutput += "\t\tobject" + m_compInfo.Name + ".set" + \
                m_compInfo.ComponentMembers[i].Name + \
                "( " + m_compInfo.ComponentMembers[i].Name + " ); \n";
        }
    }    

    viewOutput += "\t\t" + m_compInfo.Name + ".saveAsNew( ); \n";
    viewOutput += "\tfeedback = \"Data is stored!\"; \n";
    viewOutput += "\t}  \n";
    viewOutput += "</%cpp> \n";
   
    
    DEBUG endl;
    createDir ( "controller" );
    DEBUG endl;
    writingFile ( "controller/" + m_compInfo.Name + "Controller.ecpp", viewOutput);
    DEBUG endl;
    
}

