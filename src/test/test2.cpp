#include <iostream>
#include <vector>
#include <fstream>
#include <fuzzy/rule.hpp>

int main()
{
    rule* r1 = new rule(new memberFunction<GAUSSIAN>(50.0f, 20.0f));

    std::vector<float> value(101);
    for(float i=0; i<=100; i++)
    {
        value.at(i) = r1->activate(i);
    }

    std::ofstream out;
    out.open("./data/test2.txt", std::ios::out | std::ios::trunc);

    if(!out.is_open())
    {
        throw std::runtime_error("can not open file");
    }

    for(int i=0; i<value.size(); i++)
    {
        out << value.at(i) << "\n";
    }

    out.close();
    delete r1;

}


