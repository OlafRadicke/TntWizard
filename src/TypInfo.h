#ifndef TYPEINFO_H
#define TYPEINFO_H 

#include <string>

using namespace std; 

/**
 * A helper class for store component member.
 **/
class  TypInfo {
    
public:
    /**
    * Name of component member.
    **/    
    string Name;
    
    /**
    * Typ of component member.
    **/    
    string Type;
    
    TypInfo () {
        this->Name = "";
        this->Type = "";
    };
};


#endif 