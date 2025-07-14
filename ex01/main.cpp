#include "Zombie.hpp"

int main(void)
{
    int N = 500000;
    std::string name = "🧟 Minion";
    Zombie *zombie_gang;

    if (N <= 0 || N >= 1000000)
    {
        std::cout << "🧟 The number of zombies must be higher than 0 and smaller than 1000000." << std::endl;
        return (0);
    }
    zombie_gang = zombieHorde(N, name);
    for(int i = 0; i < 5; i++)
        zombie_gang[i].announce();
    delete[] zombie_gang;
    return (0);
}