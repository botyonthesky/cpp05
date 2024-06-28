/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/26 14:02:03 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void        classicTest(void)
{
    std::cout << "[ CLASSIC TEST ]" << std::endl;
    try
    {
        Form f1("CDI", 1, 150);
        Form f2(f1);
        Form f3;
        f3 = f1;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}


void    formTest(void)
{
    std::cout << "[ FORM TEST ]" << std::endl;
    try
    {
        Form f1("CDI", 0, 150);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form f1("CDI", 1, 151);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form f1("CDI", 1, 150);
        std::cout << f1 << std::endl;
        Bureaucrat b1("John Doe", 2);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form f1("CDD", 1, 150);
        std::cout << f1 << std::endl;
        Bureaucrat b1("John Doe", 1);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

int main()
{
    classicTest();
    formTest();
    return (0);
}