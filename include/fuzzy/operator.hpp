#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>
#include <algorithm>
#include <cmath>

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
    DOMBI = 9,
    SCHWEIZER_SKLAR = 10,
};

enum OPERATOR
{
    AND = 0,
    OR = 1,
};

class baseOperator
{
public:
    baseOperator(){};
    virtual float norm(float x, float y) = 0;
};

template<NORMOPERATOR nop, OPERATOR op>
class fuzzyOperator;

template<>
class fuzzyOperator<MAX_MIN, AND> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        return std::min(x, y);
    }
};

template<>
class fuzzyOperator<MAX_MIN, OR> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        return std::max(x, y);
    }
};

template<>
class fuzzyOperator<ALGEBRAIC, AND> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        return x * y;
    }
};

template<>
class fuzzyOperator<ALGEBRAIC, OR> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        return x + y - x * y;
    }
};

template<>
class fuzzyOperator<BOUNDED, AND> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        return std::max(0.0f, x + y - 1);
    }
};

template<>
class fuzzyOperator<BOUNDED, OR> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        return std::min(1.0f, x + y);
    }
};

template<>
class fuzzyOperator<DRASTIC, AND> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        if(x == 1)
            return y;
        else if(y == 1)
            return x;
        else
            return 0; 
    }
};

template<>
class fuzzyOperator<DRASTIC, OR> : public baseOperator
{
public:
    fuzzyOperator(){}

    float norm(float x, float y) override
    {
        if(x == 0)
            return y;
        else if(y == 0)
            return x;
        else
            return 1; 
    }
};

template<>
class fuzzyOperator<YAGER, AND> : public baseOperator
{
public:
    fuzzyOperator(float _q)
    : q(_q){}

    float norm(float x, float y) override
    {
        return 1.0 - std::min(1.0, pow((pow(1-x, q) + pow(1-y, q)), 1/q));
    }
private:
    float q;
};

template<>
class fuzzyOperator<YAGER, OR> : public baseOperator
{
public:
    fuzzyOperator(float _q)
    : q(_q){}

    float norm(float x, float y) override
    {
        return std::min(1.0, pow((pow(x, q) + pow(y, q)), 1/q));
    }
private:
    float q;
};

template<>
class fuzzyOperator<SCHWEIZER_SKLAR, AND> : public baseOperator
{
public:
    fuzzyOperator(float _p)
    : p(_p){}

    float norm(float x, float y) override
    {
        return pow(std::max(0.0, pow(x, -p) + pow(y, -p) - 1.0f), -1/p);
    }
private:
    float p;
};

template<>
class fuzzyOperator<SCHWEIZER_SKLAR, OR> : public baseOperator
{
public:
    fuzzyOperator(float _p)
    : p(_p){}

    float norm(float x, float y) override
    {
        return 1 - pow(std::max(0.0, pow(1-x, -p) + pow(1-y, -p) - 1.0f), -1/p);
    }
private:
    float p;
};




#endif //OPERATOR_HPP
