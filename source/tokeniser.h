//
//  tokeniser.h
//  Calculator
//
//  Created by sierra on 18/02/2021.
//
#pragma once

#ifndef tokeniser_h
#define tokeniser_h

class Tokeniser
{
public:
    
    enum class Type
    {
        add,
        subtract,
        multiply,
        
        unknown,
    };
    
    struct TokenList
    {
        double lhs;
        double rhs;
        Type type;
    };
    
    std::optional <TokenList> tokenise (std::string input) const
    {
        auto type = findType (input);
        if (type == Type::unknown)
            return {};
        
        auto lhs = findLHS (input);
        if (! lhs.has_value ())
            return {};
        
        auto rhs = findRHS (input);
        if (! rhs.has_value ())
            return {};
        
        TokenList tokens;
        tokens.lhs = *lhs;
        tokens.rhs = *rhs;
        tokens.type = type;
        return tokens;
    }
    
private:
    
    bool find (std::string input, std::string character) const
    {
        return input.find (character) != std::string::npos;
    }
    
    std::optional <double> findAndExtractLHS (std::string input, std::string character) const
    {
        if (auto pos = input.find (character); pos != std::string::npos)
            return std::stod (input.substr (0, pos));
        
        return {};
    }
    
    std::optional <double> findAndExtractRHS (std::string input, std::string character) const
    {
        if (auto pos = input.find (character); pos != std::string::npos)
            return std::stod (input.substr (pos + 1));
        
        return {};
    }
    
    Type findType (std::string input) const
    {
        if (find (input, "+")) return Type::add;
        if (find (input, "-")) return Type::subtract;
        if (find (input, "*")) return Type::multiply;
        
        return Type::unknown;
    }
    
    std::optional <double> findLHS (std::string input) const
    {
        if (auto result = findAndExtractLHS (input, "+"))
            return result;
        
        if (auto result = findAndExtractLHS (input, "-"))
            return result;
        
        if (auto result = findAndExtractLHS (input, "*"))
            return result;
        
        return {};
    }
    
    std::optional <double> findRHS (std::string input) const
    {
        if (auto result = findAndExtractRHS (input, "+"))
            return result;
        
        if (auto result = findAndExtractRHS (input, "-"))
            return result;
        
        if (auto result = findAndExtractRHS (input, "*"))
            return result;
        
        return {};
    }
};

#endif /* tokeniser_h */
