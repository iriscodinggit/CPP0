#include "../headers/Animal.hpp"
#include "../headers/Dog.hpp"
#include "../headers/Cat.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include "../headers/Brain.hpp"

int main()
{
    Dog Beethoven;
    Beethoven.GetBrain()->SetIdea(0, "can't stop thinking about sausages! 🌭");
    std::cout << std::endl << "🐶 Beethoven's thought: The first thing that comes to my mind -> " << Beethoven.GetBrain()->GetIdea(0) << std::endl << std::endl;
    std::cout << "TESTING DEEP COPY" << std::endl;
    Dog Bolt(Beethoven); //we create a deep copy, if the next outputs are different, they were deep copied, if not, the output is the same which would mean that only the pointer was copied
    Beethoven.GetBrain()->SetIdea(0, "Let's chase some cats! 🐱");
    std::cout << std::endl << "🐶 Beethoven's thought: The first thing that comes to my mind -> " << Beethoven.GetBrain()->GetIdea(0) << std::endl;
    std::cout << std::endl << "🐶 Bolt's thought: The first thing that comes to my mind -> " << Bolt.GetBrain()->GetIdea(0) << std::endl << std::endl;
    Animal *Herd[4];
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            Herd[i] = new Dog();
        else
            Herd[i] = new Cat();
    }
    for (int i = 0; i < 4; i++)
    {
        delete Herd[i];
    }
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return (0);
}