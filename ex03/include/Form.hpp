/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:34:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 11:20:58 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
            const std::string   _name;
            bool                _signed;
            const int           _signedGrade;
            const int           _exeGrade;      

    public:
        
            Form();
            Form(const std::string name, const int signedGrade, const int exeGrade);
            Form(const Form& other);
            Form& operator=(const Form& other);
            virtual ~Form();

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

            class FormNotSigned : public std::exception
            {
                public:
                    virtual const char* what() const throw();
            };

            std::string         getName(void) const;
            bool                getSigned(void) const;
            int                 getSignedGrade(void) const;
            int                 getExeGrade(void) const;
            void                beSigned(const Bureaucrat& staff);
            virtual void                execute(const Bureaucrat& executor) const;
            
};

std::ostream&   operator<<(std::ostream& out, Form const & src);

#endif