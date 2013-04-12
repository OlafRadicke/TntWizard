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
        m_cTypeMatching["text"] = "string";
        m_cTypeMatching["textarea"] = "string";
        m_cTypeMatching["password"] = "string";
        m_cTypeMatching["select"] = "string";
        m_cTypeMatching["number"] = "long";
        m_cTypeMatching["checkbox"] = "bool";
        
        m_sqlTypeMatching["text"] = "TEXT";
        m_sqlTypeMatching["textarea"] = "TEXT";
        m_sqlTypeMatching["password"] = "TEXT";
        m_sqlTypeMatching["select"] = "TEXT";
        m_sqlTypeMatching["number"] = "BIGINT";
        m_sqlTypeMatching["checkbox"] = "BOOLEAN";
    }
    
    /**
     * @arg htmltype A html form type as string.
     * @return the type keyword in c for this type.
     **/
    string htmlToCType ( string htmltype ) {
        return m_cTypeMatching[ htmltype ];
    }
    
    /**
     * @arg namberOfMember namber of component member.
     * @return the type keyword in c for this type.
     **/    
    string htmlToCType ( int namberOfMember ) {
        return m_cTypeMatching[ this->ComponentMembers[namberOfMember].Type ];
    }    
    
    
    /**
     * Do the same as function htmlToCType. But better function name.
     * @arg namberOfMember namber of component member.
     * @return the type keyword in c for this type.
     **/    
    string getMemberCType ( int namberOfMember ) {
        return m_cTypeMatching[ this->ComponentMembers[namberOfMember].Type ];
    }
    
    /**
     * @arg namberOfMember namber of component member.
     * @return the type keyword in sql for this type.
     **/    
    string getMemberSQLType ( int namberOfMember ) {
        return m_sqlTypeMatching[ this->ComponentMembers[namberOfMember].Type ];
    }
    
private:
    
    /**
    * A map list vor matching c++ types with html form types.
    **/      
    map<string, string> m_cTypeMatching; 
    
    /**
    * A map list vor matching sql types with html form types.
    **/      
    map<string, string> m_sqlTypeMatching; 
};


#endif 