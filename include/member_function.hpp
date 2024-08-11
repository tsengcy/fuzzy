#ifndef MENBER_FUNCTION_HPP
#define MEMBER_FUNCTION_HPP

#include <iostream>
#include <algorithm>

enum MEMBERFUNCTION
{
    TRIANGLE = 0,
    TRAPEXOIDAL = 1,
    GAUSSIAN = 2,
    BELL = 3,
    SIGMOIDAL = 4
};

class base
{
public:
    base()
    {

    }

    virtual float activate(float x) = 0;
protected:
};

template<MEMBERFUNCTION mf>
class memberFunction;

template<>
class memberFunction<TRIANGLE> : public base
{
public:
    memberFunction(float _a, float _b, float _c)
    : a(_a), b(_b), c(_c){}

    float activate(float x) override
    {
        return std::max(std::min((x-a)/(b-a), (c-x)/(c-b)), 0.0f);
    }
protected:
    float a, b, c;
};

template<>
class memberFunction<TRAPEXOIDAL> : public base
{
public:
    memberFunction(float _a, float _b, float _c, float _d)
    : a(_a), b(_b), c(_c), d(_d){}

    float activate(float x) override
    {
        return std::max(std::min((x-a)/(b-a), 1.0f, (d-x)/(d-c)), 0.0f);
    }
protected:
    float a, b, c, d;
};

template<>
class memberFunction<GAUSSIAN> : public base
{
public:
    memberFunction()
    {

    }
};

template<>
class memberFunction<BELL> : public base
{
public:
    memberFunction()
    {

    }
};

template<>
class memberFunction<SIGMOIDAL> : public base
{
public:
    memberFunction()
    {

    }
};






#endif //MEMBER_FUNCTION_HPP