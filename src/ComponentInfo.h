#ifndef COMPONENTINFO_H
#define COMPONENTINFO_H 

#include <vector>
#include <string>
#include <map>
#include <stdexcept>

#include "TypInfo.h"

/**
 * A helper class for store component info.
 **/
class  ComponentInfo {
    
public:


    /**
    * Name of keyword.
    **/    
    std::string Name;
    
    /**
    * Component member.
    **/    
    std::vector<TypInfo> ComponentMembers;
    
    ComponentInfo () {
        this->Name = "";
        m_cTypeMatching["text"] = "std::string";
        m_cTypeMatching["textarea"] = "std::string";
        m_cTypeMatching["password"] = "std::string";
        m_cTypeMatching["select"] = "std::string";
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
    const std::string& htmlToCType ( const std::string& htmltype )const{
         std::map<std::string, std::string>::const_iterator it = 
              m_cTypeMatching.find(htmltype);
         // in C++11 kann man es kürzer schreiben:
         // auto it = m_cTypeMatching.find(htmltype);
         if (it == m_cTypeMatching.end())
             throw std::runtime_error("unknown htmltype " + htmltype);
         return it->second;
     }      
    
    
    /**
     * @arg namberOfMember namber of component member.
     * @return the type keyword in c for this type.
     **/    
    const std::string& getMemberCType ( const int namberOfMember ) const {
        std::string type = this->ComponentMembers[namberOfMember].Type();
        return this->m_cTypeMatching[ type ];
    }
    
    /**
     * @arg namberOfMember namber of component member.
     * @return the type keyword in sql for this type.
     **/    
    const std::string& getMemberSQLType ( const int namberOfMember ) const {
        return this->m_sqlTypeMatching[ this->ComponentMembers[namberOfMember].Type ];
    }
    
    
  
    
private:
    
    /**
    * A map list vor matching c++ types with html form types.
    **/      
    std::map<std::string, std::string> m_cTypeMatching; 
    
    /**
    * A map list vor matching sql types with html form types.
    **/      
    std::map<std::string, std::string> m_sqlTypeMatching; 
};


#endif 