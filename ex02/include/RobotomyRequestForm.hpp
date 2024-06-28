/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:44 by tmaillar          #+#    #+#             */
/*   Updated: 2024/06/27 11:06:08 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <ostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
    private:
        
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        
        void    execute(const Bureaucrat& executor) const;
};


std::ostream&   operator<<(std::ostream& out, RobotomyRequestForm& src);


#endif