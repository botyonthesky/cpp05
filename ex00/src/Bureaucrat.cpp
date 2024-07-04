/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:29 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 07:31:15 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(150)
{
    std::cout << "Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor" << std::endl;

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy assignment" << std::endl;
    if (this != &other)
    {
        _grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}


void            Bureaucrat::incrementGrade(void)
{
    this->_grade--;
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

void            Bureaucrat::decrementGrade(void)
{
    this->_grade++;
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

std::string     Bureaucrat::getName(void) const
{
    return (_name);
}

int             Bureaucrat::getGrade(void) const
{
    return (_grade);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return (out);
}