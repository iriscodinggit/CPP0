#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T1> //typename means that it accepts any type

void swap(T1& fishBowl, T1& pot)
{
    T1   glass;
    glass = fishBowl;
    fishBowl = pot;
    pot = glass;
}

template<typename T2>
T2& min(T2& fishBowl, T2& pot)
{
    if (fishBowl > pot)
        return (pot);
    else if (fishBowl < pot)
        return (fishBowl);
    else
        return (pot);
}

template<typename T3>
T3& max(T3& fishBowl, T3& pot)
{
    if (fishBowl > pot)
        return (fishBowl);
    else if (fishBowl < pot)
        return (pot);
    else
        return (pot);
}

#endif