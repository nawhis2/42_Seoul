/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:22 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/07 12:28:03 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

#define RRF_SIGN 72
#define RRF_EXEC 45

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;
	RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	virtual ~RobotomyRequestForm();

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};


#endif