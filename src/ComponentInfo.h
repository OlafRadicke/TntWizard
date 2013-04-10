#ifndef COMPONENTINFO_H
#define COMPONENTINFO_H 

#include <vector>
#include <string>

#include "TypInfo.h"

using namespace std;

/**
 * A helper class for store component info.
 **/
class  ComponentInfo {
    
public:
    /**
    * Name of keyword.
    **/    
    string Name;
    
    /**
    * Component member.
    **/    
    vector<TypInfo> ComponentMembers;
    
    ComponentInfo () {
        this->Name = "";
    }
};


#endif 