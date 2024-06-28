/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:54 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/27 11:40:22 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("default", 145, 137)
{
    std::cout << "Shrubberry default constructor" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
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
bool    ShrubberyCreationForm::checkOutfile(std::ofstream& outfileStream, std::string outfile)
{
    if (!outfileStream)
    {
        std::cerr << "Error on creating file : " << outfile << std::endl;
        return (false);
    }
    return (true);
}



void    ShrubberyCreationForm::execute(const Bureaucrat& executor)
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
    out << "Shrubbery creation form, name : " << src.getName()
    << " is signed : " << src.getSigned() << ", the signed grade is : "
    << src.getSignedGrade() << ", the executed grade is : "
    << src.getExeGrade() << std::endl;
    return (out);
}