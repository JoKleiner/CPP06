/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:56:07 by joklein           #+#    #+#             */
/*   Updated: 2025/07/09 17:12:26 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
    public:
        virtual ~Base() = default;
    
    private:
        Base();
	    Base(const Base &other);
	    Base &operator=(const Base &other);
};
