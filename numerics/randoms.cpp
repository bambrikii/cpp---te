#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/**
 * @brief
 *
 * Distributions:
 * - uniform
 * - Bernoulli
 * - Poisson
 * - Normal
 * - Sampling
 *
 */

void random_int()
{
    std::cout << "random_int:" << std::endl;

    std::default_random_engine dre;

    std::uniform_int_distribution<int> di(10, 20);
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << di(dre) << std::endl;
    }
}

void random_real()
{
    std::cout << "random_real:" << std::endl;

    std::default_random_engine dre;

    std::uniform_real_distribution<double> dr(10, 20);
    for (int i = 0; i < 8; i++)
    {
        std::cout << dr(dre) << std::endl;
    }
}

void random_shuffle()
{
    std::cout << "random_shuffle:" << std::endl;

    std::vector vec = {1, 2, 3, 4, 5};
    std::default_random_engine dre;
    std::shuffle(vec.begin(), vec.end(), dre);
    std::for_each(
        vec.begin(), vec.end(), [](int &elem)
        { std::cout << elem << std::endl; });
}

int main(int argc, char const *argv[])
{
    random_int();
    random_real();
    random_shuffle();

    return 0;
}
