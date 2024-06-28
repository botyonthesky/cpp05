/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:41 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/28 06:32:33 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <ostream>
#include <fstream>
#include <stdexcept>
#include "AForm.hpp"
#include "Form.hpp"



class PresidentialPardonForm : virtual public Form
{
    private:
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
    
        void        execute(const Bureaucrat& executor) const;
        
};

std::ostream&   operator<<(std::ostream& out, PresidentialPardonForm& src);

#endif