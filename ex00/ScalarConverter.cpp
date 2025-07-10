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

int spez_case(const std::string &input)
{
    std::cout << "char: impossible\nint: impossible" << std::endl;

    if(input == "+inf" || input == "-inf" || input == "nan"){
        std::cout << "float: " << input << "f\n";
        std::cout << "double: " << input << std::endl;
    }
    else
    {
        std::cout << "float: " << input << "\n";
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
    }
    return(1);
}

int non_convertable()
{
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
    return(1);
}

int check_input(const std::string &input)
{
    size_t pos = 0;
    bool has_dot = false;

    if(input[0] == '+' || input[0] == '-')
        pos = 1;
        
    if(input.find('.') == pos)
        return(1);

    for (; pos < input.length(); pos++)
    {
        if(has_dot && input[pos] == '.')
            return (1);
        if(input[pos] == '.')
            has_dot = true;
        if(input[pos] == 'f' && pos == input.length() - 1)
            return (0);
        if(!std::isdigit(input[pos]) && pos == input.length() - 1)
            return (0);
        if(!std::isdigit(input[pos]) && input[pos] != '.')
            return (1);
    }
    return (0);
}

int ScalarConverter::convert(const std::string &input)
{
    
    if (input == "+inf" || input == "-inf" || input == "nan" ||
        input == "+inff" || input == "-inff" || input == "nanf")
        return(spez_case(input));
    
    if(check_input(input) != 0)
        return(non_convertable());
    
    if (input.find('.') == std::string::npos)
    {
        std::cout << std::fixed << std::setprecision(1);

        //char handling
        if(input.length() == 1 && std::isprint(input[0]))
            return(char_handling(input[0]), 0);

        //int handling
        try{
            return (int_handling(std::stoi(input)), 0);
        }catch(const std::exception &e){
            return(non_convertable());
        }
    }

    //precision handling
    size_t pos = input.find('.') + 1;
    size_t precision = 0;
    while(pos + precision < input.length() && std::isdigit(input[pos + precision]))
        precision++;
    std::cout << std::fixed << std::setprecision(precision);

    //float and double handling
    try{
        if(input[pos + precision] == 'f' && input[pos + precision + 1] == '\0' && precision != 0)
            float_handling(std::stof(input));
        else if(input[pos + precision] == '\0' && precision != 0)
            double_handling(std::stod(input));
        else
            return(non_convertable());
    }
    catch(const std::exception &e){
        return(non_convertable());
    }
    return(0);
}
