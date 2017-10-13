#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist]() -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}
int main()
{
    std::cout << " Enter vector size " << std::endl;
    int a = 0;
    std::cin >> a;
    std::vector<int> v = generate_random_vector<int>(a, -100, 100);
    std::cout << " Vector 0: " << std::endl;
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << " New vector: " << std::endl;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[i] > v[j])
            {
                int temp = 0;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    ///
    std::cout << " Enter vector size " << std::endl;
    int b = 0;
    std::cin >> b;
    std::vector<int> v1 = generate_random_vector<int>(b, -100, 100);
    std::cout << " Vector 1: " << std::endl;
    for (int i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << " New vector: " << std::endl;
    int temp2 = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = i + 1; j < v1.size(); ++j)
        {
            if (v1[i] > v1[j])
            {
                temp2 = v1[i];
                v1[i] = v1[j];
                v1[j] = temp2;
            }
        }
    }
    for (int i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << " New vector (v + v1) " << std::endl;
    return 0;
}
