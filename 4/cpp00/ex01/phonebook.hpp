/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:06:05 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/09 16:22:38 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <limits>

typedef struct s_contact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
}	t_contact;

class PhoneBook
{
private:
	t_contact	contact[8];
	int			head;
	int			nums;

public:
	PhoneBook();
	void	add(void);
	void	search(void);
	void	PrintContact(std::string data);
	void	PrintContact(t_contact &contact);
	bool	getInput(std::string prompt, std::string &input);
	
};

#endif