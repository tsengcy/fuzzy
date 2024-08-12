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

template<typename T>
class base
{
public:
    base()
    {

    }

    virtual T activate(T x) = 0;
protected:
};

template<MEMBERFUNCTION mf, typename T = float>
class memberFunction;

template<typename T>
class memberFunction<TRIANGLE, T> : public base<T>
{
public:
    memberFunction(T _a, T _b, T _c)
    : a(_a), b(_b), c(_c){}

    T activate(T x) override
    {
        return std::max(std::min((x-a)/(b-a), (c-x)/(c-b)), 0.0);
    }
protected:
    T a, b, c;
};

template<typename T>
class memberFunction<TRAPEXOIDAL, T> : public base<T>
{
public:
    memberFunction(T _a, T _b, T _c, T _d)
    : a(_a), b(_b), c(_c), d(_d){}

    T activate(T x) override
    {
        return std::max(std::min((x-a)/(b-a), 1.0, (d-x)/(d-c)), 0.0);
    }
protected:
    T a, b, c, d;
};

template<typename T>
class memberFunction<GAUSSIAN, T> : public base<T>
{
public:
    memberFunction(T _c, T _alpha)
    : c(_c), alpha(_alpha){}

    T activate(T x) override
    {
        return exp(-1/2*pow((x-c)/alpha, 2.0));
    }
protected:
    T c, alpha;
};

template<typename T>
class memberFunction<BELL, T> : public base<T>
{
public:
    memberFunction(T _a, T _b, T _c)
    :a(_a), b(_b), c(_c)
    {}

    T activate(T x) override
    {
        return 1 / (1 + fabs(pow((x-c)/a, 2*b)));
    }
protected:
    T a, b, c;
};

template<typename T>
class memberFunction<SIGMOIDAL, T> : public base<T>
{
public:
    memberFunction(T _a, T _c)
    : a(_a), c(_c){}

    T activate(T x) override
    {
        return 1 / (1 + exp(-a * (x-c)));
    }
protected:
    T a, c;
};






#endif //MEMBER_FUNCTION_HPP