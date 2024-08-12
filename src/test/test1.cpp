#include <fuzzy/member_function.hpp>
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    // base* ptr = new memberFunction<TRIANGLE>(20.0f, 60.0f, 80.0f);
    // base* ptr = new memberFunction<TRAPEXOIDAL>(10.0f, 20.0f, 60.0f, 95.0f);
    base* ptr = new memberFunction<GAUSSIAN>(50.0f, 20.0f);
    // base* ptr = new memberFunction<BELL>(20.0f, 4.0f, 50.0f);

    // float delta = 0.1f;

    std::vector<float> value(101);
    for(float i=0; i<=100; i++)
    {
        value.at(i) = ptr->activate(i);
    }

    std::ofstream out;
    out.open("./data/test1.txt", std::ios::out | std::ios::trunc);

    if(!out.is_open())
    {
        throw std::runtime_error("can not open file");
    }

    for(int i=0; i<value.size(); i++)
    {
        out << value.at(i) << "\n";
    }

    out.close();
    delete ptr;
}