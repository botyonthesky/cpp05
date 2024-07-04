/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:37:52 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 13:05:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : _name("Default"), _signedGrade(150), _exeGrade(150)
{
    _signed = false;
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string name, const int signedGrade, const int exeGrade) :
_name(name), _signedGrade(signedGrade), _exeGrade(exeGrade)
{
    std::cout << "Form, name : " << _name << " constructor" << std::endl;
    if (signedGrade < 1 || exeGrade < 1)
        throw GradeTooHighException();
    if (signedGrade > 150 || exeGrade > 150)
        throw GradeTooLowException();
    _signed = false;
}
Form::Form(const Form& other) :
_name(other._name), _signedGrade(other._signedGrade), _exeGrade(other._exeGrade)
{
    std::cout << "Form copy" << std::endl;
    _signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form copy assignment" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form, name : " << _name << " destructor" << std::endl;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}

const std::string       Form::getName(void) const
{
    return (_name);
}
bool                    Form::getSigned(void) const
{
    return (_signed);
}
int               Form::getSignedGrade(void) const
{
    return (_signedGrade);
}
int               Form::getExeGrade(void) const
{
    return (_exeGrade);
}

void                Form::beSigned(const Bureaucrat& staff)
{
    if (staff.getGrade() < 1)
        throw GradeTooHighException();
    if (staff.getGrade() > 150)
        throw GradeTooLowException();
    else
    {
        if (staff.getGrade() > this->getSignedGrade())
            throw GradeTooLowException();
        else
        {
            _signed = true;
        }            
    }
}


std::ostream&   operator<<(std::ostream& out, Form const & src)
{
    out << "Form, name : " << src.getName() << std::endl;
    std::cout << "have a required grade of : "<< src.getSignedGrade() << " to be signed," << std::endl;
    std::cout << "have a required grade of : "<< src.getExeGrade() << " to be executed" << std::endl;
    std::cout << "actually the form is : ";
    if (src.getSigned() == true)
        std::cout << " signed";
    else
        std::cout << " not signed";
    return (out);
}