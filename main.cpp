#include <iostream>
#include <vector>

int main(int argc, char * argv[])
{
    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);

    for (size_t i=0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }

    for (int a : vec)
    {
        std::cout << a << "\n";
    }

    return 0;
}
