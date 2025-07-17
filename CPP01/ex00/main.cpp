#include "Zombie.hpp"

int main(void)
{
    Zombie *McBrain;
    
    McBrain = newZombie("McBrain"); //new is like malloc, but it automatically casts type and sizeof
    McBrain->announce(); //we use -> instead of . because *Mcbrain is a pointer. We could do . with Mcbrain but not *Mcbrain
    delete McBrain; //delete is like free, it triggers the destructor and manages leaks

    randomChump("Brainlover"); //stack
    return (0);
}