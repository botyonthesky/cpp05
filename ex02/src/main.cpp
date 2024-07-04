/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 11:11:02 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void    presidentialTest(void)
{
    std::cout << "[ PRESIDENTIAL FORM TEST ]" << std::endl;
    
    PresidentialPardonForm p1("Usual Propal");
    std::cout << p1 << std::endl << std::endl;
    
    PresidentialPardonForm p2(p1);
    std::cout << p2 << std::endl << std::endl;
    
    PresidentialPardonForm p3;
    p3 = p1;
    std::cout << p3 << std::endl << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO EXECUTE PRESIDENTIAL FORM ]" << std::endl;
    try
    {
        std::cout << p1 << std::endl << std::endl;
        Bureaucrat b1("Kaiser Soze", 1);
        std::cout << b1 << std::endl;
        b1.executeForm(p1);
        std::cout << std::endl;
        
        Bureaucrat b2("Tyler Durden", 5);
        std::cout << b2 << std::endl;
        b2.executeForm(p1);
        std::cout << std::endl;
        
        Bureaucrat b3("Reggie Ledoux", 30);
        std::cout << b3 << std::endl;
        b2.executeForm(p1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "[BUREAUCRAT TRY TO SIGNE PRESIDENTIAL FORM ]" << std::endl;
    try
    {
        std::cout << p1 << std::endl << std::endl;
        Bureaucrat b1("Kaiser Soze", 1);
        std::cout << b1 << std::endl;
        b1.signForm(p1);
        std::cout << std::endl;
        
        Bureaucrat b2("Tyler Durden", 5);
        std::cout << b2 << std::endl;
        b2.signForm(p1);
        std::cout << std::endl;
        
        Bureaucrat b3("Reggie Ledoux", 30);
        std::cout << b3 << std::endl;
        b3.signForm(p1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT RETRY TO EXECUTE PRESIDENTIAL FORM ]" << std::endl;
    try
    {   
        std::cout << p1 << std::endl << std::endl;
        Bureaucrat b1("Kaiser Soze", 1);
        std::cout << b1 << std::endl;
        b1.executeForm(p1);
        std::cout << std::endl;

        Bureaucrat b2("Tyler Durden", 5);
        std::cout << b2 << std::endl;
        b2.executeForm(p1);
        std::cout << std::endl;

        Bureaucrat b3("Reggie Ledoux", 30);
        std::cout << b3 << std::endl;
        b3.executeForm(p1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    robotomyTest(void)
{
    std::cout << "[ ROBOTOMY FORM TEST ]" << std::endl;
    
    RobotomyRequestForm r1("Surgical incision");
    std::cout << r1 << std::endl << std::endl;

    RobotomyRequestForm r2(r1);
    std::cout << r1 << std::endl << std::endl;

    RobotomyRequestForm r3;
    r3 = r1;
    std::cout << r3 << std::endl << std::endl;
    
    std::cout << "[ BUREAUCRAT TRY TO EXECUTE ROBOTOMY FORM ]" << std::endl;
    try
    {
        std::cout << r1 << std::endl << std::endl;
        Bureaucrat b1("R2D2", 1);
        std::cout << b1 << std::endl;
        b1.executeForm(r1);
        std::cout << std::endl;

        Bureaucrat b2("Replicant", 45);
        std::cout << b2 << std::endl;
        b2.executeForm(r1);
        std::cout << std::endl;

        Bureaucrat b3("T1000", 75);
        std::cout << b3 << std::endl;
        b3.executeForm(r1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO SIGN ROBOTOMY FORM ]" << std::endl;
    try
    {
        std::cout << r1 << std::endl << std::endl;
        Bureaucrat b1("R2D2", 1);
        std::cout << b1 << std::endl;
        b1.signForm(r1);
        std::cout << std::endl;

        Bureaucrat b2("Replicant", 45);
        std::cout << b2 << std::endl;
        b2.signForm(r1);
        std::cout << std::endl;

        Bureaucrat b3("T1000", 75);
        std::cout << b3 << std::endl;
        b3.signForm(r1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT RETRY TO EXECUTE ROBOTOMY FORM ]" << std::endl;
    try
    {
        std::cout << r1 << std::endl << std::endl;
        Bureaucrat b1("R2D2", 1);
        std::cout << b1 << std::endl;
        b1.executeForm(r1);
        std::cout << std::endl;

        Bureaucrat b2("Replicant", 45);
        std::cout << b2 << std::endl;
        b2.executeForm(r1);
        std::cout << std::endl;

        Bureaucrat b3("T1000", 75);
        std::cout << b3 << std::endl;
        b3.executeForm(r1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    shrubberyTest(void)
{
    std::cout << "[ SHRUBBERY FORM TEST ]" << std::endl;
    ShrubberyCreationForm s1("Candyland");
    std::cout << s1 << std::endl << std::endl;

    ShrubberyCreationForm s2(s1);
    std::cout << s2 << std::endl << std::endl;

    ShrubberyCreationForm s3;
    s3 = s1;    
    std::cout << s3 << std::endl << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO EXECUTE SHRUBBERY FORM ]" << std::endl;
    try
    {
        std::cout << s1 << std::endl << std::endl;
        Bureaucrat b1("Calvin Candie", 100);
        std::cout << b1 << std::endl;
        b1.executeForm(s1);
        std::cout << std::endl;

        Bureaucrat b2("Django Freeman", 138);
        std::cout << b2 << std::endl;
        b2.executeForm(s1);
        std::cout << std::endl;

        Bureaucrat b3("King Schultz", 150);
        std::cout << b3 << std::endl;
        b3.executeForm(s1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT TRY TO SIGN THE SHRUBBERY FORM ]" << std::endl;
    try
    {
        std::cout << s1 << std::endl << std::endl;
        Bureaucrat b1("Calvin Candie", 100);
        std::cout << b1 << std::endl;
        b1.signForm(s1);
        std::cout << std::endl;

        Bureaucrat b2("Django Freeman", 138);
        std::cout << b2 << std::endl;
        b2.signForm(s1);
        std::cout << std::endl;

        Bureaucrat b3("King Schultz", 150);
        std::cout << b3 << std::endl;
        b3.signForm(s1);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "[ BUREAUCRAT RETRY TO EXECUTE THE SHRUBBERY FORM ]" << std::endl;
    try
    {
        std::cout << s1 << std::endl << std::endl;
        Bureaucrat b1("Calvin Candie", 100);
        std::cout << b1 << std::endl;
        b1.executeForm(s1);
        std::cout << std::endl;

        Bureaucrat b2("Django Freeman", 138);
        std::cout << b2 << std::endl;
        b2.executeForm(s1);
        std::cout << std::endl;

        Bureaucrat b3("King Schultz", 150);
        std::cout << b3 << std::endl;
        b3.executeForm(s1);
        std::cout << std::endl;
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
    return (0);
}