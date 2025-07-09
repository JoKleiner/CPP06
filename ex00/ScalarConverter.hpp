/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:34:37 by joklein           #+#    #+#             */
/*   Updated: 2025/07/01 08:34:37 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <iomanip>
#include <cctype>

class ScalarConverter
{
    public:
        static int convert(const std::string &input);
    
    private:
        ScalarConverter();
	    ScalarConverter(const ScalarConverter &other);
	    ScalarConverter &operator=(const ScalarConverter &other);
	    ~ScalarConverter() = default;
};

void char_handling(char cha);
void int_handling(int i);
void float_handling(float f);
void double_handling(double d);
