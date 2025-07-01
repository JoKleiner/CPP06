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

void spez_case(const std::string &input, bool wrong_input) {
    std::cout << "char: impossible\nint: impossible" << std::endl;
    if(wrong_input == false)
    {
        if(input == "+inf" || input == "-inf" || input == "nan"){
            std::cout << "float: " << input << "f\n";
            std::cout << "double: " << input << std::endl;
        }else {
            std::cout << "float: " << input << "\n";
            std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        }
    }
    else
        std::cout << "float: nanf\ndouble: nan" << std::endl;
}

void char_handling(double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if(!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

void int_handling(double d)
{
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void float_handling(double d, size_t precision)
{
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(precision) << "float: " << static_cast<float>(d) << "f" << std::endl;
}

size_t precision_calc(const std::string &input)
{
    size_t precision = 0;
    size_t pos = input.find('.');
    if (pos != std::string::npos) {
        pos++;
        while(pos + precision < input.length())
            precision++;
    }
    if(precision == 0)
        precision++;
    return(precision);
}

void ScalarConverter::convert(const std::string &input)
{
    
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

    size_t precision = precision_calc(input);
    
    char_handling(d);
    int_handling(d);
    float_handling(d, precision);
    std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
}
