/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 11:55:29 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

void    presidentialTest(void)
{
    std::cout << "[ PRESIDENTIAL INTERN TEST ]" << std::endl;

    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *rrf << std::endl;
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO EXECUTE INTER FORM ]" << std::endl;
    try
    {
        Bureaucrat b1("John Doe", 1);
        std::cout << b1 << std::endl;
        b1.executeForm(*rrf);
        std::cout << std::endl;
        
        Bureaucrat b2("Rustin Cohle", 20);
        std::cout << b2 << std::endl;
        b2.executeForm(*rrf);
        std::cout << std::endl;

        Bureaucrat b3("Tyler Durden", 30);
        std::cout << b3 << std::endl;
        b3.executeForm(*rrf);
        std::cout << std::endl;
        
        std::cout << std::endl;
        std::cout << "[ BUREAUCRAT TRY TO SIGN INTER FORM ]" << std::endl;
        b1.signForm(*rrf);
        b2.signForm(*rrf);
        b3.signForm(*rrf);
        std::cout << std::endl;
        std::cout << "[ BUREAUCRAT RETRY TO EXECUTE INTER FORM ]" << std::endl;
        b1.executeForm(*rrf);
        b2.executeForm(*rrf);
        b3.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void    robotomyTest(void)
{
    std::cout << "[ ROBOTOMY INTERN TEST ]" << std::endl;
    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO EXECUTE INTER FORM ]" << std::endl;
    try
    {
        Bureaucrat b1("R2D2", 30);
        std::cout << b1 << std::endl;
        b1.executeForm(*rrf);
        std::cout << std::endl;
        
        Bureaucrat b2("Replicant", 45);
        std::cout << b2 << std::endl;
        b2.executeForm(*rrf);
        std::cout << std::endl;

        Bureaucrat b3("T1000", 80);
        std::cout << b3 << std::endl;
        b3.executeForm(*rrf);
        std::cout << std::endl;

        std::cout << "[ BUREAUCRAT TRY TO SIGN THE INTER FORM ]" << std::endl;
        b1.signForm(*rrf);
        b2.signForm(*rrf);
        b3.signForm(*rrf);
        std::cout << std::endl;

        std::cout << "[ BUREAUCRAT RETRY TO EXECUTE INTER FORM ]" << std::endl;
        b1.executeForm(*rrf);
        b2.executeForm(*rrf);
        b3.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    shrubberyTest(void)
{
    std::cout << "[ SHRUBBERY INTERN TEST ]" << std::endl;
    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << *rrf << std::endl;
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO EXECUTE THE INTER FORM ]" << std::endl;
    try
    {
        Bureaucrat b1("Cliff Booth", 1);
        std::cout << b1 << std::endl;
        b1.executeForm(*rrf);
        std::cout << std::endl;

        Bureaucrat b2("Vincent Vega", 120);
        std::cout << b2 << std::endl;
        b2.executeForm(*rrf);
        std::cout << std::endl;

        Bureaucrat b3("Calvin Candie", 137);
        std::cout << b3 << std::endl;
        b3.executeForm(*rrf);
        std::cout << std::endl;
        
        std::cout << "[ BUREAUCRAT TRY TO SIGN THE INTER FORM ]" << std::endl;
        b1.signForm(*rrf);
        b2.signForm(*rrf);
        b3.signForm(*rrf);
        std::cout << std::endl;

        std::cout << "[ BUREAUCRAT RETRY TO EXECUTE THE INTER FORM ]" << std::endl;
        b1.executeForm(*rrf);
        b2.executeForm(*rrf);
        b3.executeForm(*rrf);
        std::cout << std::endl;
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void    execeptionTest(void)
{
    std::cout << "[ EXCEPTION TEST ]" << std::endl;
    try
    {
        Bureaucrat b1("John Doe", 1);
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("Wrong name", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main()
{
    presidentialTest();
    std::cout << std::endl;
    robotomyTest();
    std::cout << std::endl;
    shrubberyTest();
    std::cout << std::endl;
    execeptionTest();
    return (0);
}