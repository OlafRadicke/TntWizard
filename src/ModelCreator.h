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
    void createDir ( std::string path ) {
        std::string command = "mkdir " + path;
        int result = system( command.c_str() );
        DEBUG "The value returned was: " << result << std::endl;        
    }
    
    /**
    * Write a output file.
    * @arg filename file name.
    * @arg textvalue text value.
    **/     
    void writingFile ( std::string filename, std::string textvalue){
        std::ofstream myfile( filename.c_str() );
        myfile << textvalue;
        myfile.close();        
    }
    
    /**
    * Generat the value of tag "<%args>".
    * @return A sting with args values.
    **/      
    std::string getEcppArgs ( void );
    
    /**
     * Search and replace function.
     * @param rep search string
     * @param rep replace string
     * @param rep original string
     * @return string with replacements
     **/
    std::string strReplace (std::string rep, std::string wit, std::string in);

    /**
     * Return a copy of the string with all the cased characters converted to 
     * upercase.
     **/    
    std::string upercase ( std::string keywords );    
    
    
    
};


#endif 