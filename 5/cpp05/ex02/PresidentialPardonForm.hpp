/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:19:39 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/07 12:28:08 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#define PPF_SIGN 25
#define PPF_EXEC 5

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm();
	
	std::string getTarget() const;
	virtual void execute(Bureaucrat const & executor) const;
};


#endif