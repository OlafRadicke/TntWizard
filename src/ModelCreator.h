#ifndef MODELCREATOR_H
#define MODELCREATOR_H 

#include <iostream>
#include <string>
#include <stdio.h>    
#include <stdlib.h> 
#include <fstream>
#include <map>

#include "ComponentInfo.h"

# define ERROR std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] " <<
# define DEBUG std::cout << "[" << __FILE__ << ":" << __LINE__ << "] " <<

using namespace std; 

/**
 * This Class create a model C++-class for a component.
 **/
class  ModelCreator {
    
public:
    
    ModelCreator ( ComponentInfo cinfo ) {
        this->m_compInfo = cinfo;
    };
    
    /**
    * Starts the process.
    **/      
    void Run ( void );
    
private:
    
    /**
    * Create the .h file.
    **/      
    void creatH ( void );   
    

    /**
    * Create the .cpp file.
    **/      
    void creatCPP ( void );      
    
    /**
    * Info about name and component member.
    **/  
    ComponentInfo m_compInfo;
    
    bool ifDirExist(){
//         ofstream newFile (path, ios::trunc);  
//                                         
//         // path found?
//         if(newFile.good() == false) 
//         {
//             cout << "Directory doesn't exist. Closing wizard" << endl;
//             return false;
//         }      
        return true;
    }
    
    /**
    * Create a directory.
    **/        
    void createDir ( string path ) {
        string command = "mkdir " + path;
        int result = system( command.c_str() );
        DEBUG "The value returned was: " << result << endl;        
    }
    
    /**
    * Write a output file.
    * @arg filename file name.
    * @arg textvalue text value.
    **/     
    void writingFile ( string filename, string textvalue){
        ofstream myfile( filename.c_str() );
        myfile << textvalue;
        myfile.close();        
    }
    
    /**
    * Generat the value of tag "<%args>".
    * @return A sting with args values.
    **/      
    string getEcppArgs ( void );
    
    /**
     * Search and replace function.
     * @param rep search string
     * @param rep replace string
     * @param rep original string
     * @return string with replacements
     **/
    string strReplace (string rep, string wit, string in);

    /**
     * Return a copy of the string with all the cased characters converted to 
     * upercase.
     **/    
    string upercase ( string keywords );    
    
    
    
};


#endif 