/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:53:24 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/27 12:58:20 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Form.hpp"


Intern::Intern()
{
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
    std::cout << "Intern copy" << std::endl;
}

Intern&  Intern::operator=(const Intern& other)
{
    std::cout << "Intern copy assignment" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor" << std::endl;
}
Form*  Intern::newPresidential(const std::string& target)
{
    Form *doc;

    try
    {
        doc = new PresidentialPardonForm(target);
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << "Memory allocation failed : " << e.what() << std::endl;
    }
    return (doc);

}

Form*  Intern::newRobotomy(const std::string& target)
{
    Form *doc;

    try
    {
        doc = new RobotomyRequestForm(target);
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << "Memory alloction failed : " << e.what() << std::endl;
    }
    return (doc);

}

Form*  Intern::newShrubbery(const std::string& target)
{
    Form* doc;

    try
    {
        doc = new ShrubberyCreationForm(target);
    }
    catch(const std::bad_alloc & e)
    {
        std::cerr << "Memory allocation failed : " << e.what() << std::endl;
    }
    return (doc);
    
}
const char* Intern::InvalidTarget::what() const throw()
{
    return ("The parameter is not valid, expected : \npresidential pardon, robotomy request, or shrubbery creation");
}

Form*  Intern::makeForm(std::string name, std::string target)
{
    Form* newForm = NULL;

    std::string call[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

    Form* (Intern::*ptr[])(const std::string&) =
    {
        &Intern::newPresidential,
        &Intern::newRobotomy,
        &Intern::newShrubbery
    };

    try
    {
        for (int i = 0; i < 3; i++)
        {
            if (name == call[i])
            {
                newForm = (this->*ptr[i])(target);
                std::cout << "Intern creates : " << call[i] << std::endl;
                return (newForm);
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    throw InvalidTarget();
   return (NULL);
}
