#ifndef VIEWCREATOR_H
#define VIEWCREATOR_H 

#include <iostream>
#include <string>

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
    
    void run ( void ) {};
    
private:
    
    /**
    * Name of component member.
    **/    
    ComponentInfo m_compInfo;
    
};


#endif 