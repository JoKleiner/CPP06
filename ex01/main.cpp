/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:36:57 by joklein           #+#    #+#             */
/*   Updated: 2025/07/01 14:36:57 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d;
    d.num = 42;

    uintptr_t raw = Serializer::serialize(&d);
    Data* d2 = Serializer::deserialize(raw);
    uintptr_t raw2 = Serializer::serialize(d2);

    std::cout << "Original Data address: " << &d << std::endl;
    std::cout << "Deserialized pointer:  " << d2 << std::endl;
    std::cout << "Serialized number:     " << raw << std::endl;
    std::cout << "Serialized number2:    " << raw2 << std::endl;
    std::cout << "Original number:       " << d.num << std::endl;
    std::cout << "Deserialized number:   " << d2->num << std::endl;

    if (d2 == &d)
        std::cout << "Success: Pointer matches!" << std::endl;
    else
        std::cout << "Error: Pointer does not match!" << std::endl;
}
