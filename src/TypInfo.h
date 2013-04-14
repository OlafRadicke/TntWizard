#ifndef TYPEINFO_H
#define TYPEINFO_H 

#include <string>


/**
 * A helper class for store component member.
 **/
class  TypInfo {
    
public:
    
    /**
    * Name of component member.
    **/    
    std::string const Name() const {
        return this->n_Name;
    };
    
    /**
    * Typ of component member (as htnl form type).
    **/    
    std::string const Type() const{
        return this->n_Type;
    };
    
    TypInfo () {
        this->n_Name = "";
        this->n_Type = "";
    };
    
private:
    
    /**
    * Name of component member.
    **/    
    std::string n_Name;
    
    /**
    * Typ of component member (as htnl form type).
    **/    
    std::string n_Type;    
};


#endif 