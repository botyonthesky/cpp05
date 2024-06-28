/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/27 12:46:49 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void    presidentialTest(void)
{
    std::cout << "[ PRESIDENTIAL TEST ]" << std::endl;
    
    PresidentialPardonForm p1;
    PresidentialPardonForm p2("Usual Propal");
    PresidentialPardonForm p3(p2);
    
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    try
    {
        Bureaucrat b1("Kaiser Soze", 1);
        p2.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {   
        Bureaucrat b1("Kaiser Soze", 1);
        b1.signForm(p2);
        p2.execute(b1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    robotomyTest(void)
{
    std::cout << "[ ROBOTOMY TEST ]" << std::endl;
    RobotomyRequestForm r1;
    RobotomyRequestForm r2("Keaton execution");
    RobotomyRequestForm r3(r2);

    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;
    
    try
    {
        Bureaucrat b1("Kaiser Soze", 44);
        b1.signForm(r2);
        r2.execute(b1);
        b1.executeForm(r2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    shrubberyTest(void)
{
    std::cout << "[ SHRUBBERY TEST ]" << std::endl;
    ShrubberyCreationForm s1;
    ShrubberyCreationForm s2("Kobayashi");
    ShrubberyCreationForm s3(s2);
    
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    try
    {
        Bureaucrat b1("Kaiser Soze", 50);
        b1.signForm(s2);
        s2.execute(b1);
        b1.executeForm(s2);
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