/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 13:18:06 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void        bureaucratTest(void)
{
    std::cout << "[ BUREAUCRAT TEST ]" << std::endl;
    try
    {
        Bureaucrat b1("Tyler Durden", 1);
        std::cout << b1 << std::endl;
        std::cout << std::endl;
        Bureaucrat b2(b1);
        std::cout << b2 << std::endl;
        std::cout << std::endl;
        Bureaucrat b3;
        std::cout << b3 << std::endl;
        b3 = b1;
        std::cout << b3 << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


void    formTest(void)
{
    std::cout << "[ FORM TEST ]" << std::endl;
    try
    {
        Form f1("Project Mayhem", 0, 150);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form f1("Project Mayhem", 1, 151);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form f1("Project Mayhem", 1, 150);
        std::cout << f1 << std::endl;
        std::cout << std::endl;

        Bureaucrat b1("Cornelius", 2);
        std::cout << b1 << std::endl;
        b1.signForm(f1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form f1("Project Mayhem", 1, 150);
        std::cout << f1 << std::endl;
        std::cout << std::endl;

        Bureaucrat b1("Tyler Durden", 1);
        std::cout << b1 << std::endl;
        b1.signForm(f1);
        std::cout << std::endl;
        std::cout << f1 << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }   
}

int main()
{
    bureaucratTest();
    std::cout << std::endl;
    formTest();
    return (0);
}