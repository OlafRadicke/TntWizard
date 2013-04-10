#ifndef VIEWCREATOR_H
#define VIEWCREATOR_H 

#include <iostream>
#include <string>
#include <stdio.h>    
#include <stdlib.h> 
#include <fstream>

#include "ComponentInfo.h"

using namespace std; 

/**
 * A helper class for store component member.
 **/
class  ViewCreator {
    
public:
    
    ViewCreator ( ComponentInfo cinfo ) {
        this->m_compInfo = cinfo;
    };
    
    void Run ( void );
    
private:
    
    /**
    * Name of component member.
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
    
    void createDir ( string path ) {
        string command = "mkdir " + path;
        int result = system( command.c_str() );
        printf ("The value returned was: %d.\n",result);
        cout << "result: " << result << endl;
        
    }
    
    void writingFile ( string filename, string textvalue){
        ofstream Zieldatei("Datei.txt");
        Zieldatei << "Dies ist der neue Text\n";
        Zieldatei.close();        
                
//         ofstream myfile();
        ofstream myfile( filename.c_str() );
//         myfile.open (filename);
        myfile << textvalue;
        myfile.close();        
    }
    
};


#endif 