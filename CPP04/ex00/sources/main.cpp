#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* Beethoven = new Dog();
    const Animal* Pearl = new Cat();
    std::cout << std::endl;
    std::cout << Beethoven->getType() << " " << std::endl;
    std::cout << Pearl->getType() << " " << std::endl;
    Pearl->makeSound(); //will output the cat sound!
    Beethoven->makeSound();
    meta->makeSound();

    std::cout << std::endl << "TESTING WRONG ANIMAL" << std::endl << std::endl;
    const WrongAnimal* MutantMeta = new WrongAnimal();
    const WrongAnimal* MutantCat = new WrongCat();
    std::cout << MutantCat->getType() << " " << std::endl;
    MutantCat->makeSound();

    std::cout << std::endl;
    delete meta;
    delete MutantMeta;
    delete MutantCat;
    delete Beethoven;
    delete Pearl;
    return (0);
}