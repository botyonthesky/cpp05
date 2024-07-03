/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 06:53:31 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/03 13:55:39 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "AForm.hpp"
#include "Form.hpp"


class Form;

class Bureaucrat
{
    private:
    
        const std::string     _name;
        int             _grade;
        
    public:

        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
    
        std::string     getName(void) const;
        int             getGrade(void) const;
        void            incrementGrade();
        void            decrementGrade();   
        void            signForm(Form& doc);
        void            executeForm(Form const & form);
        
};

std::ostream&  operator<<(std::ostream& out, Bureaucrat const &src);


#endif