#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1;i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> v = { 5, 2, 1, 9, -2 };
    bubble_sort(v);

    for (auto& e : v)
    {
        std::cout << e << " ";
    }

    std::cout << "\n";
    return 0;
}