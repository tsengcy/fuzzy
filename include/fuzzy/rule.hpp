#ifndef RULE_HPP
#define RULE_HPP

#include <vector>
#include <iostream>
#include <functional>

#include <fuzzy/operator.hpp>
#include <fuzzy/member_function.hpp>

// template<NORMOPERATOR op>
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

    void insert(base* mf, baseOperator* func)
    {
        mvMF.push_back(mf);
        mvFunc.push_back(func);
    }

    float activate(int id, float x)
    {
        return mvMF.at(id)->activate(x);
    }

    float activate(float x)
    {
        return mvMF.back()->activate(x);;
    }

    template<typename... Args>
    float activate(float x, Args... args)
    {
        float value = activate(args...);
        int id = sizeof...(args);
        // std::cout << "id: " << id << std::endl;
        float y = mvMF.at(mvFunc.size() - id)->activate(x);

        value = mvFunc.at(mvFunc.size() - id)->norm(value, y);
        
        return value;
    }

private:
    std::vector<base*> mvMF;
    std::vector<baseOperator*> mvFunc;
};

#endif //RULE_HPP