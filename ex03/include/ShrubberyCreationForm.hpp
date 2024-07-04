/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:47 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/04 11:19:04 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <ostream>
#include <fstream>
#include <stdexcept>
#include "AForm.hpp"
#include "Form.hpp"


class ShrubberyCreationForm : virtual public Form
{
    private:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void    execute(const Bureaucrat& executor) const;
        bool    checkOutfile(std::ofstream& outfileStreeam, std::string outfile) const;


};

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm& src);


#endif