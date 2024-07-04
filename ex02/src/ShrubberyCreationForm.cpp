/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:54 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 11:06:54 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("unnamed", 145, 137)
{
    std::cout << "Shrubberry default constructor" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
AForm(target, 145, 137)
{
    std::cout << "Shrubbery constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm(other)
{
    std::cout << "Shrubbery copy" << std::endl;        
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "Shrubbery copy assignment" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor" << std::endl;
}
bool    ShrubberyCreationForm::checkOutfile(std::ofstream& outfileStream, std::string outfile) const
{
    if (!outfileStream)
    {
        std::cerr << "Error on creating file : " << outfile << std::endl;
        return (false);
    }
    return (true);
}



void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    if (executor.getGrade() <= this->getExeGrade())
    {
        std::string outfile = this->getName() + "_shrubbery";
        std::ofstream outfileStream(outfile.c_str());
        if (!checkOutfile(outfileStream, outfile))
            return ;
        else 
        {
            outfileStream << "ex02/" << std::endl;
            outfileStream << "├─ .vscode/" << std::endl;
            outfileStream << "├─ include/" << std::endl;
            outfileStream << "│  ├─ AForm.hpp" << std::endl;
            outfileStream << "│  ├─ Bureaucrat.hpp" << std::endl;
            outfileStream << "│  ├─ PresidentialPardonForm.hpp" << std::endl;
            outfileStream << "│  ├─ RobotomyRequestForm.hpp" << std::endl;
            outfileStream << "│  ├─ ShrubberyCreationForm.hpp" << std::endl;
            outfileStream << "├─ obj/" << std::endl;
            outfileStream << "├─ src/" << std::endl;
            outfileStream << "│  ├─ AForm.cpp" << std::endl;
            outfileStream << "│  ├─ Bureaucrat.cpp" << std::endl;
            outfileStream << "│  ├─ PresidentialPardonForm.cpp" << std::endl;
            outfileStream << "│  ├─ RobotomyRequestForm.cpp" << std::endl;
            outfileStream << "│  ├─ ShrubberyCreationForm.cpp" << std::endl;
            outfileStream << "├─ Makefile" << std::endl;
        }
        outfileStream.close();
    }
}

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm& src)
{
      out << "Shrubbery Creation Form, name : " << src.getName() << std::endl;
    std::cout << "have a required grade of : "<< src.getSignedGrade() << " to be signed," << std::endl;
    std::cout << "have a required grade of : "<< src.getExeGrade() << " to be executed" << std::endl;
    std::cout << "actually the form is : ";
    if (src.getSigned() == true)
        std::cout << " signed";
    else
        std::cout << " not signed";
    return (out);
}