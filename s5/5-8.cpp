#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array = {0, 5, 10, 15, 20};

    for (int e = 0; e < array.size(); e++)
    {
        std::cout << "array[" << e << "] = " << array[e] << std::endl;
    }
}