/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:53 by joklein           #+#    #+#             */
/*   Updated: 2025/07/11 15:25:06 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void char_handling(char cha)
{
    std::cout << "char: '" << cha << "'";
    std::cout << "\nint: " << static_cast<int>(cha);
    std::cout << "\nfloat: " << static_cast<float>(cha) << "f";
    std::cout << "\ndouble: " << static_cast<double>(cha) << std::endl;
}

void int_handling(int i)
{
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if(!std::isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void float_handling(float f)
{
    if (f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if(!std::isprint(f))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    if(f < std::numeric_limits<int>::max() && f > std::numeric_limits<int>::min())
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void double_handling(double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if(!std::isprint(d))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    if(d < std::numeric_limits<int>::max() && d > std::numeric_limits<int>::min())
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if(d < std::numeric_limits<float>::max() && d > std::numeric_limits<float>::lowest())
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << d << std::endl;
}
