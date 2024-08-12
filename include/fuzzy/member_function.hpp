#ifndef MENBER_FUNCTION_HPP
#define MEMBER_FUNCTION_HPP

#include <iostream>
#include <algorithm>
#include <cmath>

enum MEMBERFUNCTION
{
    TRIANGLE = 0,
    TRAPEXOIDAL = 1,
    GAUSSIAN = 2,
    BELL = 3,
    SIGMOIDAL = 4
};

enum NORMOPERATOR
{
    MAX_MIN = 0,
    ALGEBRAIC = 1,
    BOUNDED = 2,
    DRASTIC = 3,
    YAGER = 4,
    DUBOIS_PRADE = 5,
    HAMACHER = 6,
    FRANK = 7,
    SUGENO = 8,
    DOMBI = 9
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
        return std::max(std::min(std::min((x-a)/(b-a), (d-x)/(d-c)), 1.0f), 0.0f);
    }
protected:
    float a, b, c, d;
};

template<>
class memberFunction<GAUSSIAN> : public base
{
public:
    memberFunction(float _c, float _alpha)
    : c(_c), alpha(_alpha){}

    float activate(float x) override
    {
        return exp(pow((x-c)/alpha, 2.0f)/-2.0f);
    }
protected:
    float c, alpha;
};

template<>
class memberFunction<BELL> : public base
{
public:
    memberFunction(float _a, float _b, float _c)
    :a(_a), b(_b), c(_c)
    {}

    float activate(float x) override
    {
        return 1 / (1 + fabs(pow((x-c)/a, 2*b)));
    }
protected:
    float a, b, c;
};

template<>
class memberFunction<SIGMOIDAL> : public base
{
public:
    memberFunction(float _a, float _c)
    : a(_a), c(_c){}

    float activate(float x) override
    {
        return 1 / (1 + exp(-a * (x-c)));
    }
protected:
    float a, c;
};










#endif //MEMBER_FUNCTION_HPP