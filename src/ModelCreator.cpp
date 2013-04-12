
#include "ModelCreator.h"

void ModelCreator::creatH ( void ) {
    string codeOutput = "";
    
    codeOutput += "#ifndef " + upercase( m_compInfo.Name ) +"_H \n";
    codeOutput += "#define " + upercase( m_compInfo.Name ) +"_H \n\n"; 
    codeOutput += "#include <string> \n\n"; 
    codeOutput += "#include <tntdb/connection.h>\n"; 
    codeOutput += "#include <tntdb/connect.h>\n"; 
    codeOutput += "#include <tntdb/result.h> \n\n"; 
    codeOutput += "class " + m_compInfo.Name + " { \n\n";    
    codeOutput += "public:\n\n"; 
    
    // create geter functions.
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t /** \n";
        codeOutput += "\t * @return. \n";
        codeOutput += "\t **/ \n";
        codeOutput += "\t " + m_compInfo.getMemberCType(i);
        codeOutput += " get" + m_compInfo.ComponentMembers[i].Name +"( ) {;\n";
        codeOutput += "\t\t return this->m_" + m_compInfo.ComponentMembers[i].Name + ";\n";
        codeOutput += "\t } \n\n";
    }        
    
    
    // create seter functions.
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t /** \n";
        codeOutput += "\t * @arg newValue. \n";
        codeOutput += "\t **/ \n";
        codeOutput += "\t void set" + m_compInfo.ComponentMembers[i].Name +"( ";
        codeOutput +=  m_compInfo.getMemberCType(i) + " newValue ) {;\n";
        codeOutput += "\t\t this->m_" + m_compInfo.ComponentMembers[i].Name;
        codeOutput += " = newValue;\n";
        codeOutput += "\t } \n\n";
    }      
      
    codeOutput += "private:\n\n"; 
    
    // create private members.
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t /** \n";
        codeOutput += "\t * No commant \n";
        codeOutput += "\t **/ \n";
        codeOutput += "\t void " + m_compInfo.getMemberCType(i) + " ";
        codeOutput += "m_" + m_compInfo.ComponentMembers[i].Name + ";\n\n";
    }     
    codeOutput += "};\n";
    writingFile ( "modelles/" + m_compInfo.Name + ".h", codeOutput);    
}

void ModelCreator::creatCPP( void ) {
    
    string codeOutput = "";
    codeOutput += "#include \"" + m_compInfo.Name + ".h\" \n\n"; 
    codeOutput += "/**\n";
    codeOutput += " Table create command:\n";
    codeOutput += "CREATE TABLE  " + m_compInfo.Name +" ( \n";
    codeOutput += "\t id  \t SERIAL \t PRIMARY KEY, \n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t " + m_compInfo.ComponentMembers[i].Name;
        codeOutput += "\t " + m_compInfo.getMemberSQLType(i) + " \t NOT NULL";
        // if not the last item...
        if ( i<m_compInfo.ComponentMembers.size() ) {
            codeOutput += ",";
            
        }
        codeOutput += " \n";
    }
    codeOutput += ");\n ";
    codeOutput += "**/\n ";
  
    // Function
    codeOutput += "void " + m_compInfo.Name + "::saveAsNew( ) { \n"; 
    codeOutput += "\t std::string sqlcommand = \"\"; \n"; 
    codeOutput += "\t tntdb::Connection conn;\n"; 
    codeOutput += "\t tntdb::Result result; \n";       
    codeOutput += "\t conn = tntdb::connect( \"SET-DB-DRIVER\" ); \n";
    
    
    
    
    codeOutput += "\t sqlcommand = \"INSERT INTO " + m_compInfo.Name +"\"; \n";
    codeOutput += "\t sqlcommand += \"( \"\n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t sqlcommand += \"\t " + m_compInfo.ComponentMembers[i].Name ;
        // if not the last item...
        if ( (i+1) <m_compInfo.ComponentMembers.size() ) {
            codeOutput += ", \";\n";
            
        } else {
            codeOutput += " \" ;\n";
        }
    }
    codeOutput += "\t sqlcommand += \") VALUES ( \"\n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        if ( m_compInfo.ComponentMembers[i].Type == "number" ) {
            codeOutput += "\t sqlcommand += \"\t \" + m_" + m_compInfo.ComponentMembers[i].Name + " + \"";
        } else {
            codeOutput += "\t sqlcommand += \"\t '\" + m_" + m_compInfo.ComponentMembers[i].Name + " + \"'" ;
        }
        // if not the last item...
        if ( (i+1) <m_compInfo.ComponentMembers.size() ) {
            codeOutput += ",\" ;\n";
        }else {
            codeOutput += " \" ;\n";
        }
    }
    codeOutput += "\t sqlcommand += \");\" \n\n";    
    codeOutput += "\t conn.execute( sqlcommand );\n";   
    codeOutput += "} \n"; 
    
    writingFile ( "modelles/" + m_compInfo.Name + ".cpp", codeOutput);    
}

void ModelCreator::Run ( void ) {
    createDir ( "modelles" );    
    creatH();
    creatCPP();
}



string ModelCreator::upercase ( string keywords ) {
    keywords = strReplace ( "a", "A", keywords);
    keywords = strReplace ( "b", "B", keywords);
    keywords = strReplace ( "c", "C", keywords);
    keywords = strReplace ( "d", "D", keywords);
    keywords = strReplace ( "e", "E", keywords);
    keywords = strReplace ( "f", "F", keywords);
    keywords = strReplace ( "g", "G", keywords);
    keywords = strReplace ( "h", "H", keywords);
    keywords = strReplace ( "i", "I", keywords);
    keywords = strReplace ( "j", "J", keywords);
    keywords = strReplace ( "k", "K", keywords);
    keywords = strReplace ( "l", "L", keywords);
    keywords = strReplace ( "m", "M", keywords);
    keywords = strReplace ( "n", "N", keywords);
    keywords = strReplace ( "o", "O", keywords);
    keywords = strReplace ( "p", "P", keywords);
    keywords = strReplace ( "q", "Q", keywords);
    keywords = strReplace ( "r", "R", keywords);
    keywords = strReplace ( "s", "S", keywords);
    keywords = strReplace ( "t", "T", keywords);
    keywords = strReplace ( "u", "U", keywords);
    keywords = strReplace ( "v", "V", keywords);
    keywords = strReplace ( "w", "W", keywords);
    keywords = strReplace ( "x", "X", keywords);
    keywords = strReplace ( "y", "Y", keywords);
    keywords = strReplace ( "z", "Z", keywords);
    return keywords;
}


string ModelCreator::strReplace (string rep, string wit, string in) {
  int pos;
  while (true) {
    pos = in.find(rep);
    if (pos == -1) {
      break;
    } else {
      in.erase(pos, rep.length());
      in.insert(pos, wit);
    }
  }
  return in;
}