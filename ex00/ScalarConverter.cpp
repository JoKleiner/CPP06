/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:34:30 by joklein           #+#    #+#             */
/*   Updated: 2025/07/01 08:34:30 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &){
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &){
    return (*this);
}

void spez_case(const std::string &input, bool wrong_input) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if(wrong_input == false)
    {
        if(input == "+inf" || input == "-inf" || input == "nan"){
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }else {
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        }
    }
    else
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan" << std::endl;
    }
}

void char_handling(double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if(std::isprint(static_cast<int>(d)))
    {
        char c = static_cast<char>(d);
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;
}

void int_handling(double d)
{
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        int i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }
}

void float_handling(double d)
{
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        float f = static_cast<float>(d);
        std::cout << "float: " << f << "f" << std::endl;

    }
}

void ScalarConverter::convert(const std::string &input) {
    
    if (input == "+inf" || input == "-inf" || input == "nan" ||
        input == "+inff" || input == "-inff" || input == "nanf")
    {
        spez_case(input, false);
        return;
    }
    
    char *end;
    double d = std::strtod(input.c_str(), &end);
    if(*end != '\0'){
        spez_case(input, true);
        return;
    }

    char_handling(d);
    int_handling(d);
    float_handling(d);
    std::cout << "double: " << d << std::endl;
    
}
