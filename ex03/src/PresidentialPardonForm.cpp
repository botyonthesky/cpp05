/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:49 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/28 06:34:52 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("default", 25, 5)
{
    std::cout << "Presidential default constructor" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{
    std::cout << "Presidential constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
Form(other)
{
    std::cout << "Presidential copy" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "Presidential copy assignment" << std::endl;
    if (this != &other)
    {
        Form::operator=(other);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential destructor" << std::endl;
}

void       PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    Form::execute(executor);
    if (executor.getGrade() <= this->getExeGrade())
    {
        std::cout << "We inform you, that : " << this->getName()
        << "has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

std::ostream&   operator<<(std::ostream& out, PresidentialPardonForm& src)
{
    out << "Presidential Pardon Form, name : " << src.getName() << std::endl;
    std::cout << "have a required grade of : "<< src.getSignedGrade() << " to be signed," << std::endl;
    std::cout << "have a required grade of : "<< src.getExeGrade() << " to be executed" << std::endl;
    std::cout << "actually the Aform is : ";
    if (src.getSigned() == true)
        std::cout << " signed";
    else
        std::cout << " not signed";
    return (out);
}