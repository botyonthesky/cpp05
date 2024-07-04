/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:37:52 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/26 13:59:49 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : _name("unnamed"), _signedGrade(150), _exeGrade(150)
{
    std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string name, const int signedGrade, const int exeGrade) :
_name(name), _signedGrade(signedGrade), _exeGrade(exeGrade)
{
    _signed = false;
    std::cout << "AForm constructor" << std::endl;
    if (signedGrade < 1 || exeGrade < 1)
        throw GradeTooHighException();
    if (signedGrade > 150 || exeGrade > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other) :
_name(other._name), _signedGrade(other._signedGrade), _exeGrade(other._exeGrade)
{
    std::cout << "AForm copy" << std::endl;
    _signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy assignment" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor" << std::endl;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}
const char* AForm::FormNotSigned::what() const throw()
{
    return ("The form is not signed");
}

std::string         AForm::getName(void) const
{
    return (_name);
}

bool                AForm::getSigned(void) const
{
    return (_signed);
}
int                 AForm::getSignedGrade(void) const
{
    return (_signedGrade);
}
int                 AForm::getExeGrade(void) const
{
    return (_exeGrade);
}

void                AForm::beSigned(const Bureaucrat& staff)
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
void        AForm::execute(Bureaucrat const & executor) const
{
    if (this->_signed == false)
        throw FormNotSigned();
    if (executor.getGrade() > this->_exeGrade)
        throw GradeTooLowException();
}



std::ostream&   operator<<(std::ostream& out, AForm const & src)
{
    out << "AForm, name : " << src.getName() << std::endl;
    std::cout << "have a required grade of : "<< src.getSignedGrade() << " to be signed," << std::endl;
    std::cout << "have a required grade of : "<< src.getExeGrade() << " to be executed" << std::endl;
    std::cout << "actually the Aform is : ";
    if (src.getSigned() == true)
        std::cout << " signed";
    else
        std::cout << " not signed";
    return (out);
}