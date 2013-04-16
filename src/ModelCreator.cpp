
#include "ModelCreator.h"

void ModelCreator::creatH ( void ) {
    std::string codeOutput = "";
    
    codeOutput += "#ifndef " + upercase( m_compInfo.getName() ) +"_H \n";
    codeOutput += "#define " + upercase( m_compInfo.getName() ) +"_H \n\n"; 
    codeOutput += "#include <string> \n\n"; 
    codeOutput += "#include <tntdb/connection.h>\n"; 
    codeOutput += "#include <tntdb/connect.h>\n"; 
    codeOutput += "#include <tntdb/result.h> \n\n"; 
    codeOutput += "class " + m_compInfo.getName() + " { \n\n";    
    codeOutput += "public:\n\n"; 
    
    // create geter functions.
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t /** \n";
        codeOutput += "\t * @return. \n";
        codeOutput += "\t **/ \n";
        codeOutput += "\t " + m_compInfo.getMemberCType(i) + " const";
        codeOutput += " get" + m_compInfo.ComponentMembers[i].getName() +"( ) const {;\n";
        codeOutput += "\t\t return this->m_" + m_compInfo.ComponentMembers[i].getName() + ";\n";
        codeOutput += "\t } \n\n";
    }        
    
    
    // create seter functions.
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t /** \n";
        codeOutput += "\t * @arg newValue. \n";
        codeOutput += "\t **/ \n";
        codeOutput += "\t void set" + m_compInfo.ComponentMembers[i].getName() +"( ";
        codeOutput +=  m_compInfo.getMemberCType(i) + " newValue ) {;\n";
        codeOutput += "\t\t this->m_" + m_compInfo.ComponentMembers[i].getName();
        codeOutput += " = newValue;\n";
        codeOutput += "\t } \n\n";
    }      
      
    codeOutput += "private:\n\n"; 
    
    // create private members.
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t /** \n";
        codeOutput += "\t * No comment \n";
        codeOutput += "\t **/ \n";
        codeOutput += "\t void " + m_compInfo.getMemberCType(i) + " ";
        codeOutput += "m_" + m_compInfo.ComponentMembers[i].getName() + ";\n\n";
    }     
    codeOutput += "};\n";
    writingFile ( "modelles/" + m_compInfo.getName() + ".h", codeOutput);    
}

void ModelCreator::creatCPP( void ) {
    
    std::string codeOutput = "";
    codeOutput += "#include \"" + m_compInfo.getName() + ".h\" \n\n"; 
    codeOutput += "/**\n";
    codeOutput += " Table create command:\n";
    codeOutput += "CREATE TABLE  " + m_compInfo.getName() +" ( \n";
    codeOutput += "\t id  \t SERIAL \t PRIMARY KEY, \n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t " + m_compInfo.ComponentMembers[i].getName();
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
    codeOutput += "void " + m_compInfo.getName() + "::saveAsNew( ) { \n"; 
    codeOutput += "\t std::string sqlcommand = \"\"; \n"; 
    codeOutput += "\t tntdb::Connection conn;\n"; 
    codeOutput += "\t tntdb::Result result; \n";       
    codeOutput += "\t conn = tntdb::connect( \"SET-DB-DRIVER\" ); \n";
    
    
    
    
    codeOutput += "\t sqlcommand = \"INSERT INTO " + m_compInfo.getName() +"\"; \n";
    codeOutput += "\t sqlcommand += \"( \"\n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        codeOutput += "\t sqlcommand += \"\t " + m_compInfo.ComponentMembers[i].getName() ;
        // if not the last item...
        if ( (i+1) <m_compInfo.ComponentMembers.size() ) {
            codeOutput += ", \";\n";
            
        } else {
            codeOutput += " \" ;\n";
        }
    }
    codeOutput += "\t sqlcommand += \") VALUES ( \"\n";
    for ( unsigned int i=0; i<m_compInfo.ComponentMembers.size(); i++) {
        if ( m_compInfo.ComponentMembers[i].getType() == "number" ) {
            codeOutput += "\t sqlcommand += \"\t \" + m_" + m_compInfo.ComponentMembers[i].getName() + " + \"";
        } else {
            codeOutput += "\t sqlcommand += \"\t '\" + m_" + m_compInfo.ComponentMembers[i].getName() + " + \"'" ;
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
    
    writingFile ( "modelles/" + m_compInfo.getName() + "Model.cpp", codeOutput); 
}

void ModelCreator::Run ( void ) {
    createDir ( "modelles" );    
    creatH();
    creatCPP();
}



std::string ModelCreator::upercase ( std::string keywords ) {
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


std::string ModelCreator::strReplace (std::string rep, std::string wit, std::string in) {
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