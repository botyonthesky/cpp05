/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:34:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/26 14:02:40 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
            const std::string   _name;
            bool                _signed;
            const int           _signedGrade;
            const int           _exeGrade;      

    public:
        
            AForm();
            AForm(const std::string name, const int signedGrade, const int exeGrade);
            AForm(const AForm& other);
            AForm& operator=(const AForm& other);
            virtual ~AForm() = 0;

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
            void        execute(const Bureaucrat& executor) const;
    
};

std::ostream&   operator<<(std::ostream& out, AForm const & src);

#endif