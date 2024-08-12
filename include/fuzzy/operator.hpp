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


template<NORMOPERATOR op>
float Tnorm(float x, float y);

template<NORMOPERATOR op>
float Tnorm(float x, float y, float);

template<NORMOPERATOR op>
float Snorm(float x, float y);

template<NORMOPERATOR op>
float Snorm(float x, float y, float);

template<>
float Tnorm<MAX_MIN>(float x, float y)
{
    return std::min(x, y);
}

template<>
float Snorm<MAX_MIN>(float x, float y)
{
    return std::min(x, y);
}

template<>
float Tnorm<ALGEBRAIC>(float x, float y)
{
    return x * y;
}

template<>
float Snorm<ALGEBRAIC>(float x, float y)
{
    return x + y - x * y;
}

template<>
float Tnorm<BOUNDED>(float x, float y)
{
    return std::max(0.0f, x + y - 1);
}

template<>
float Snorm<BOUNDED>(float x, float y)
{
    return std::min(1.0f, x + y);
}

template<>
float Tnorm<DRASTIC>(float x, float y)
{
    if(x == 1)
        return y;
    else if(y == 1)
        return x;
    else
        return 0; 
}

template<>
float Snorm<DRASTIC>(float x, float y)
{
    if(x == 0)
        return y;
    else if(y == 0)
        return x;
    else
        return 1; 
}

template<>
float Tnorm<YAGER>(float x, float y, float q)
{
    return 1.0 - std::min(1.0, pow((pow(1-x, q) + pow(1-y, q)), 1/q));
}

template<>
float Snorm<YAGER>(float x, float y, float q)
{
    return std::min(1.0, pow((pow(x, q) + pow(y, q)), 1/q));
}





#endif //OPERATOR_HPP
