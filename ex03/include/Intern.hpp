/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:52:27 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/28 07:22:39 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <ostream>
#include <stdexcept>
#include <fstream>
#include "Form.hpp"

class Form;

class Intern
{
    private:
        
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        class InvalidTarget : public std::exception
        {
            public:
                virtual const char* what() const throw();
                
        };

        Form*  newPresidential(const std::string& target);
        Form*  newRobotomy(const std::string& target);
        Form*  newShrubbery(const std::string& target);
        
        Form*  makeForm(std::string name, std::string target);
};




#endif