#ifndef CRONTOLLERCREATOR_H
#define CRONTOLLERCREATOR_H 

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
 * This class create a controller for a component.
 **/
class  CrontollerCreator {
    
public:
    
    CrontollerCreator ( ComponentInfo cinfo ) {
        this->m_compInfo = cinfo;
    };
    
    void Run ( void );
    
private:
    
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
    
};


#endif 