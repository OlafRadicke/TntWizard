
#include "ViewCreator.h"


void ViewCreator::Run ( void ) {
    std::string viewOutput = "";
    viewOutput += "";

    viewOutput += "<%include>./src/controller/" + m_compInfo.getName() + "Controller.ecpp</%include> \n";
    viewOutput += "<!DOCTYPE HTML>\n";
    viewOutput += "<html>\n";
    viewOutput += "<head>\n";
    viewOutput += "    <title>" + m_compInfo.getName() + "</title>\n";
    viewOutput += "    <meta charset = \"UTF-8\" />\n";
    viewOutput += "</head>\n";
    viewOutput += "<body>\n";
    viewOutput += "% if ( feedback != \"\" ) {\n";
    viewOutput += "    <b><$ feedback $> </b>\n";
    viewOutput += "% } else {\n";
    
    viewOutput += "\t<form method=\"post\" >\n";
    
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {  
        viewOutput += "\t\t<p>" + m_compInfo.ComponentMembers[i].getName() + ":</p>\n";
        if ( m_compInfo.ComponentMembers[i].getType() == "text" ) {
            viewOutput += "\t\t<p><input name=\"";
            viewOutput += m_compInfo.ComponentMembers[i].getName() + "\" \n";
            viewOutput += "\t\t\t type=\"text\"\n ";
            viewOutput += "\t\t\t required=\"required\"></p>\n";
            continue;
        }
        
        if ( m_compInfo.ComponentMembers[i].getType() == "textarea" ) {
            viewOutput += "\t\t<p><textarea name=\"" + \
                m_compInfo.ComponentMembers[i].getName() + "\"  ></textarea></p>\n";
            continue;
        }

        if ( m_compInfo.ComponentMembers[i].getType() == "password" ) {
            viewOutput += "\t\t<p><input name=\""; 
            viewOutput += m_compInfo.ComponentMembers[i].getName() + "\" \n";
            viewOutput += "\t\t\t type=\"password\" \n";
            viewOutput += "\t\t\t required=\"required\"></p>\n";
            continue;
        }
     
        if ( m_compInfo.ComponentMembers[i].getType() == "select" ) {
            viewOutput += "\t\t<p><select name=\"";
            viewOutput += m_compInfo.ComponentMembers[i].getName() + "\" >\n";
            viewOutput += "\t\t\t<option value=\"no-set\">No set</option>\n";
            viewOutput += "\t\t</select></p>\n";
            continue;
        }

        if ( m_compInfo.ComponentMembers[i].getType() == "number" ) {
            viewOutput += "\t\t<p><input name=\"";
            viewOutput += m_compInfo.ComponentMembers[i].getName() + "\" \n ";
            viewOutput += "\t\t\t type=\"number\" \n";
            viewOutput += "\t\t\t min=\"1\" \n";
            viewOutput += "\t\t\t max=\"100000\"  \n";
            viewOutput += "\t\t\t required=\"required\"></p>\n";
            continue;
        }
        
        if ( m_compInfo.ComponentMembers[i].getType() == "checkbox" ) {
            viewOutput += "\t\t<p><input \n " + \
            viewOutput += "\t\t\t type=\"checkbox\"\n ";
            viewOutput += "\t\t\t id=\"" + m_compInfo.ComponentMembers[i].getName() + "\"";
            viewOutput += "\t\t\t value=\"true\"";
            viewOutput += "\t\t\t name=\"" + m_compInfo.ComponentMembers[i].getName() + "\" />\n";
            viewOutput += m_compInfo.ComponentMembers[i].getName() + "</p> \n";         
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
    
    createDir ( "views" );
    writingFile ( "views/" + m_compInfo.getName() + "Controller.ecpp", viewOutput);
    DEBUG std::endl;
    
}

