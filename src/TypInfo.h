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
    std::string const getName() const {
        return this->n_Name;
    };
    
    
    /**
    * Set name of component member.
    * @arg newValue new value;
    **/    
    void setName( std::string newValue ) {
        this->n_Name = newValue;
    };    
    
    /**
    * Set typ of component member (as htnl form type).
    * @arg newValue new value;
    **/    
    void setType( std::string newValue ) {
        this->n_Type = newValue;
    };    
    
    /**
    * Typ of component member (as htnl form type).
    **/    
    std::string const getType() const{
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