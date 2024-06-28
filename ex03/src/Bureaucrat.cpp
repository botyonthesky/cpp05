/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:29 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/28 07:02:29 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Form.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :
_name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor" << std::endl;

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

}
Bureaucrat::Bureaucrat(const Bureaucrat& other) :
_name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy assignment" << std::endl;
    if (this != &other)
    {
        _name = other._name;
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
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    this->_grade--;

}

void            Bureaucrat::decrementGrade(void)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    this->_grade++;

}

std::string     Bureaucrat::getName(void) const
{
    return (_name);
}

int             Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void            Bureaucrat::signForm(Form& doc)
{
    try
    {
        doc.beSigned(*this);
        std::cout << "Bureaucrat, name : " << this->_name
        << " signed : " << doc.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Bureaucrat, name : " << this->_name
        << " couldn't sign form : " << doc.getName()
        << " because is grade is too low" << std::endl;
    }
}
void        Bureaucrat::executeForm(Form const & form) 
{
    try
    {
        form.execute(*this);
        std::cout << "The form : " << form.getName()
        << " have been successfully executed" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "The form : " << form.getName()
        << " couldn't be execute because : "
        << e.what() << std::endl;
    }
    
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return (out);
}