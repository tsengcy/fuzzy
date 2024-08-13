#ifndef RULE_HPP
#define RULE_HPP

#include <vector>
#include <iostream>
#include <functional>

#include <fuzzy/operator.hpp>
#include <fuzzy/member_function.hpp>

template<NORMOPERATOR op>
class rule
{
public:
    rule(base* mf)
    {
        mvMF.push_back(mf);
    };

    ~rule()
    {
        for(int i=0; i<mvMF.size(); i++)
        {
            delete mvMF.at(i);
            mvMF.at(i) = nullptr;
        }
    }

    void insert(base* mf, std::function<float(float, float)> func)
    {
        mvMF.push_back(mf);
        mvFunc.push_back(func);
    }   

    float activate(float x)
    {
        if(mvMF.size() == 0)
        {
            throw std::runtime_error("no member function exits");
        }

        float value;
        value = mvMF.at(0)->activate(x);
        
        for(int i=0; i<mvMF.size(); i++)
        {
            value = mvFunc.at(i)(x, value);
        }
        return value;
    }

private:
    std::vector<base*> mvMF;
    std::vector<std::function<float(float, float)>> mvFunc;
};

#endif //RULE_HPP