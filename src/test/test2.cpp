#include <iostream>
#include <vector>
#include <fstream>
#include <fuzzy/rule.hpp>
#include <fuzzy/operator.hpp>

int main()
{
    rule* r1 = new rule(new memberFunction<BELL>(7.5f, 2.0f, -5.0f));
    r1->insert(new memberFunction<BELL>(5.0f, 1.0f, 5.0f), new fuzzyOperator<ALGEBRAIC, AND>());

    std::vector<std::vector<float>> value(101);
    for(float i=0; i<=100; i++)
    {
        std::vector<float> vec;
        float v = i / 100.0f * 30 - 15;
        vec.push_back(v);
        vec.push_back(r1->activate(0, v));
        vec.push_back(r1->activate(1, v));
        vec.push_back(r1->activate(v, v));

        value.at(i) = vec;
    }

    std::ofstream out;
    out.open("./data/test2.txt", std::ios::out | std::ios::trunc);

    if(!out.is_open())
    {
        throw std::runtime_error("can not open file");
    }

    for(int i=0; i<value.size(); i++)
    {
        for(int j=0; j<value.at(i).size(); j++)
        {
            out << value.at(i).at(j) << "\t";
        }
        out << "\n";
    }

    out.close();
    delete r1;

}


