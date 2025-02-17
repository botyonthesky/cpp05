/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 12:58:06 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

void        classicTest(void)
{
    std::cout << "[ CLASSIC TEST ]" << std::endl;
    try
    {
        Bureaucrat b1("Tyler Durden", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2(b1);
        std::cout << b2 << std::endl;

        Bureaucrat b3;
        std::cout << b3 << std::endl;
        b3 = b1;
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void        gradeTest(void)
{
    std::cout << "[ GRADE TEST ]" << std::endl;
    try
    {
        Bureaucrat b1("Tyler Durden", 0);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try 
    {
        Bureaucrat b2("Cornelius", 151);
        std::cout << b2 << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try 
    {
        Bureaucrat b3("Tyler Durden", 75);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}
void    incrementTest(void)
{
    std::cout << "[ INCREMENT TEST ]" << std::endl;
    try
    {
        Bureaucrat b1("Tyler Durden", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
}
void    decrementTest(void)
{
    std::cout << "[ DECREMENT TEST ]" << std::endl;
    try
    {
        Bureaucrat b1("Tyler Durden", 149);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    classicTest();
    gradeTest();
    incrementTest();
    decrementTest();
    return (0);
}