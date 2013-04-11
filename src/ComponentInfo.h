#ifndef COMPONENTINFO_H
#define COMPONENTINFO_H 

#include <vector>
#include <string>
#include <map>

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
        m_typeMatching["text"] = "string";
        m_typeMatching["textarea"] = "string";
        m_typeMatching["password"] = "string";
        m_typeMatching["select"] = "string";
        m_typeMatching["number"] = "long";
        m_typeMatching["checkbox"] = "bool";
    }
    
    /**
     * @arg htmltype A html form type as string.
     * @return the type keyword in c for this type.
     **/
    string htmlToCType ( string htmltype ) {
        return m_typeMatching[ htmltype ];
    }
    
    /**
     * @arg namberOfMember namber of component member.
     * @return the type keyword in c for this type.
     **/    
    string htmlToCType ( int namberOfMember ) {
        return m_typeMatching[ this->ComponentMembers[namberOfMember].Type ];
    }    
    
private:
    /**
    * A map list vor matching c++ types with html form types.
    **/      
    map<string, string> m_typeMatching; 
};


#endif 