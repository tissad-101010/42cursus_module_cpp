/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tissad <tissad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:50:43 by tissad            #+#    #+#             */
/*   Updated: 2025/01/09 22:55:22 by tissad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main(int ac, char **av)
{
    (void)ac;(void)av;
    Base *arr[10];
    srand(time(NULL));
    for (int i = 0; i < MAX_INSTANCE; i++)
    {
        arr[i] = generate();
    }
    std::cout << "Identify the type of each instance using pointers" << std::endl;
    for (int i = 0; i < MAX_INSTANCE; i++)
    {
        std::cout << i << ": ";
        identify(arr[i]);
    }
    std::cout << "Identify the type of each instance using references" << std::endl;
    for (int i = 0; i < MAX_INSTANCE; i++)
    {
        //identify(arr[i]);
        std::cout << i << ": ";
        identify(*arr[i]);
    }
    for (int i = 0; i < MAX_INSTANCE; i++)
    {
        delete arr[i];
    }
}

//It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
//to use anything you like for the random choice implementation.
Base * generate(void)
{
    
    int r = rand() % 3;
    
    switch (r)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}
//function that prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
    // use try catch
    if (dynamic_cast<A*>(p))
        std::cout << "A " << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B " << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C " << std::endl;
    else
        std::cout << "Unknown type\n";
}

// Function to identify the type of the object referenced by p (without using pointers or typeinfo)
void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A " << std::endl;
        (void)a;
        return;
    }  catch (std::exception& e) {
        //std::cerr << "Bad cast exception ";
    }

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B "  <<std::endl;
        (void)b;
        return;
    } catch (std::exception& e) {
        //std::cerr << "Bad cast exception ";
    }

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C " << std::endl;
        (void)c;
        return;
    }catch (std::exception& e) {
        //std::cerr << "Bad cast exception\n";
    }
}