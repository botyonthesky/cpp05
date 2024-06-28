/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:51 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/28 06:35:59 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
Form("Default", 72, 45)
{
    std::cout << "Robotomy default constructor" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form(target, 72, 45)
{
    std::cout << "Robotomy constructor" << std::endl;   
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
Form(other)
{
    std::cout << "Robotomy copy" << std::endl;  
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        Form::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor" << std::endl;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    Form::execute(executor);
    int	success;
	srand((unsigned) time(NULL));
	success = rand() % 2;
    if (executor.getGrade() <= this->getExeGrade())
    {
        std::cout << "Drill ! Drill ! !" << std::endl;
        if (success)
        {
            std::cout << "We inform you that " << getName()
            << " has been robotomized successfully 50% of the time" << std::endl;
        }
        else
            std::cout << "The robotomy has failed !" << std::endl;        
    }
}


std::ostream&   operator<<(std::ostream& out, RobotomyRequestForm& src)
{
    out << "Roboty Request Form, name : " << src.getName() << std::endl;
    std::cout << "have a required grade of : "<< src.getSignedGrade() << " to be signed," << std::endl;
    std::cout << "have a required grade of : "<< src.getExeGrade() << " to be executed" << std::endl;
    std::cout << "actually the Aform is : ";
    if (src.getSigned() == true)
        std::cout << " signed";
    else
        std::cout << " not signed";
    return (out);
}
