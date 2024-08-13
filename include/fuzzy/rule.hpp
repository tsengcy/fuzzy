#ifndef RULE_HPP
#define RULE_HPP

#include <vector>
#include <iostream>

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

    void insert(base* mf)
    {

    }   

    float activate(float x)
    {
        if(mvMF.size() == 0)
        {
            throw std::runtime_error("no member function exits");
        }
        float value;
        value = mvMF.at(0)->activate(x);

        for



    }

private:
    std::vector<base*> mvMF;

};

#endif //RULE_HPP