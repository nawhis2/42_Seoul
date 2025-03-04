/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:41:41 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/07 12:41:54 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string 	name;
	bool				isSigned;
	const int			grade_toSign;
	const int			grade_toExec;
	Form &operator=(const Form &copy);

public:
	Form();
	Form(std::string name, int grade_toSign, int grade_toExec);
	Form(const Form &copy);
	~Form();

	std::string getName() const;
	bool		getisSigned() const;
	int			get_grade_toSign() const;
	int			get_grade_toExec() const;
	
	void	beSigned(Bureaucrat &b);
	void	signForm();

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
};


#endif