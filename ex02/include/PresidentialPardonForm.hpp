/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:41 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 08:17:20 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
    
        void        execute(const Bureaucrat& executor) const;
        
};

std::ostream&   operator<<(std::ostream& out, PresidentialPardonForm& src);

#endif