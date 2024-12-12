#include <iostream>
#include <vector>

int main()
{
    std::vector<float> vec;
    vec.push_back(42.2f);
    vec.push_back(10.1f);
    vec.push_back(11.3f);


    for (auto a : vec)
    {
        std::cout << a << "\n";
    }
    return 0;
}