/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:02:32 by joklein           #+#    #+#             */
/*   Updated: 2025/07/10 10:15:47 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Base.hpp"
#include "inc/A.hpp"
#include "inc/B.hpp"
#include "inc/C.hpp"

#include <iostream>
# include <random>

Base* generate()
{
    std::random_device rand;
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    std::cout << "Type of the object pointed to: ";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Type of the object referenced: ";
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&) {}
}

int main()
{ 
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    std::cout << "Type 'A'" << std::endl;
    identify(a);
    identify(*a);
    std::cout << "\nType 'B'" << std::endl;
    identify(b);
    identify(*b);
    std::cout << "\nType 'C'" << std::endl;
    identify(c);
    identify(*c);

    delete a;
    delete b;
    delete c;

    Base *rdm1 = generate();
    Base *rdm2 = generate();
    Base *rdm3 = generate();

    std::cout << "\nRandomly generated objects:" << std::endl;
    identify(rdm1);
    identify(*rdm1);
    identify(rdm2);
    identify(*rdm2);
    identify(rdm3);
    identify(*rdm3);
    
    delete rdm1;
    delete rdm2;
    delete rdm3;
}
