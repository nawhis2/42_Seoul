/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:41:41 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/07 12:27:50 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string 	name;
	bool				isSigned;
	const int			grade_toSign;
	const int			grade_toExec;
	AForm &operator=(const AForm &copy);

public:
	AForm();
	AForm(std::string name, int grade_toSign, int grade_toExec);
	AForm(const AForm &copy);
	virtual ~AForm();

	std::string getName() const;
	bool		getisSigned() const;
	int			get_grade_toSign() const;
	int			get_grade_toExec() const;
	
	void	beSigned(Bureaucrat &b);
		
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	virtual void execute(Bureaucrat const & executor) const = 0;
};


#endif