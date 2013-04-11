
#include "ViewCreator.h"

string ViewCreator::getEcppArgs ( void ) {
    string argsOutput = "";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        argsOutput += "\t " + m_compInfo.htmlToCType( i );
        argsOutput += " " + m_compInfo.ComponentMembers[i].Type + ";\n";
        
    };
    return argsOutput;
}

void ViewCreator::Run ( void ) {
    string viewOutput = "";
    viewOutput += "";

    viewOutput += "<%include>./src/controller/" + m_compInfo.Name + "Controller.ecpp</%include> \n";
    viewOutput += "<!DOCTYPE HTML>\n";
    viewOutput += "<html>\n";
    viewOutput += "<head>\n";
    viewOutput += "    <title>" + m_compInfo.Name + "</title>\n";
    viewOutput += "    <meta charset = \"UTF-8\" />\n";
    viewOutput += "</head>\n";
    viewOutput += "<body>\n";
    viewOutput += "% if ( feedback != \"\" ) {\n";
    viewOutput += "    <b><$ feedback $> </b>\n";
    viewOutput += "% } else {\n";
    
    viewOutput += "\t<form method=\"post\" >\n";
    
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {  
        viewOutput += "\t\t<p>" + m_compInfo.ComponentMembers[i].Name + ":</p>\n";
        if ( m_compInfo.ComponentMembers[i].Type == "text" ) {
            viewOutput += "\t\t<p><input name=\"";
            viewOutput += m_compInfo.ComponentMembers[i].Name + "\" \n";
            viewOutput += "\t\t\t type=\"text\"\n ";
            viewOutput += "\t\t\t required=\"required\"></p>\n";
            continue;
        }
        
        if ( m_compInfo.ComponentMembers[i].Type == "textarea" ) {
            viewOutput += "\t\t<p><textarea name=\"" + \
                m_compInfo.ComponentMembers[i].Name + "\"  ></textarea></p>\n";
            continue;
        }

        if ( m_compInfo.ComponentMembers[i].Type == "password" ) {
            viewOutput += "\t\t<p><input name=\""; 
            viewOutput += m_compInfo.ComponentMembers[i].Name + "\" \n";
            viewOutput += "\t\t\t type=\"password\" \n";
            viewOutput += "\t\t\t required=\"required\"></p>\n";
            continue;
        }
     
        if ( m_compInfo.ComponentMembers[i].Type == "select" ) {
            viewOutput += "\t\t<p><select name=\"";
            viewOutput += m_compInfo.ComponentMembers[i].Name + "\" >\n";
            viewOutput += "\t\t\t<option value=\"no-set\">No set</option>\n";
            viewOutput += "\t\t</select></p>\n";
            continue;
        }

        if ( m_compInfo.ComponentMembers[i].Type == "number" ) {
            viewOutput += "\t\t<p><input name=\"";
            viewOutput += m_compInfo.ComponentMembers[i].Name + " \n ";
            viewOutput += "\t\t\t type=\"number\" \n";
            viewOutput += "\t\t\t min=\"1\" \n";
            viewOutput += "\t\t\t max=\"100000\"  \n";
            viewOutput += "\t\t\t required=\"required\"></p>\n";
            continue;
        }
        
        if ( m_compInfo.ComponentMembers[i].Type == "checkbox" ) {
            viewOutput += "\t\t<p><input \n " + \
            viewOutput += "\t\t\t type=\"checkbox\"\n ";
            viewOutput += "\t\t\t id=\"" + m_compInfo.ComponentMembers[i].Name + "\"";
            viewOutput += "\t\t\t value=\"true\"";
            viewOutput += "\t\t\t name=\"" + m_compInfo.ComponentMembers[i].Name + "\" />\n";
            viewOutput += m_compInfo.ComponentMembers[i].Name + "</p> \n";         
            continue;
        }  
    
    }
    
    viewOutput += "\t\t<p><button name=\"save_button\" \n";
    viewOutput += "\t\t\t class=\"full_width_button\"  \n"; 
    viewOutput += "\t\t\t value=\"save_pressed\"  \n";
    viewOutput += "\t\t\t type=\"submit\">save</button> \n";
    viewOutput += "\t</form>\n";
    viewOutput += "% }\n";
    viewOutput += "</body>\n";
    viewOutput += "</html>\n";
    
    DEBUG endl;
    createDir ( "views" );
    DEBUG endl;
    writingFile ( "views/" + m_compInfo.Name + "Controller.ecpp", viewOutput);
    DEBUG endl;
    
}

