/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:47 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 11:07:26 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void    execute(const Bureaucrat& executor) const;
        bool    checkOutfile(std::ofstream& outfileStreeam, std::string outfile) const;
        
};

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm& src);


#endif