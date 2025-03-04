/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:53:06 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/09 16:22:11 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	head = 0;
	nums = 0;
	memset(contact, 0, sizeof(t_contact) * 8);
}

bool	PhoneBook::getInput(std::string prompt, std::string &input)
{
	while (true)
	{
		std::cout << prompt ;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (true);
		if (input.size() == 0) 
			std::cout << "CAN'T HAVE EMPTY FIELDS. TRY AGAIN" << std::endl;
		else
			break;
	}
	return (false);
}

void	PhoneBook::add(void)
{
	if (head >= 8)
		head = 0;
	if (getInput("FIRST NAME : ", contact[head].first_name) ||
	getInput("LAST NAME : ", contact[head].last_name) ||
	getInput("NICK NAME : ", contact[head].nick_name) ||
	getInput("PHONE NUMER : ", contact[head].phone_number) ||
	getInput("DARKEST SECRET : ", contact[head].darkest_secret))
	{
		memset(&contact[head], 0, sizeof(t_contact));
		return ;
	}
	head++;
	if (nums < 8)
		nums++;
}

void	PhoneBook::PrintContact(std::string data)
{
	if (data.size() > 10)
	{
		for (int j = 0; j < 9; j++)
			std::cout << data[j];
		std::cout << ".|";
	}
	else
	{
		std::cout << std::string(10 - data.size(), ' ') 
				<< data << '|' ;
	}
}

void	PhoneBook::PrintContact(t_contact &contact)
{
	std::cout << "* FRIST NAME\t : " << contact.first_name << " *\n"
			<< "* LAST NAME\t : " << contact.last_name << " *\n"
			<< "* NICK NAME\t : " << contact.nick_name << " *\n"
			<< "* PHONE NUMBER\t : " << contact.phone_number << " *\n"
			<< "* DARKEST SECRET : " << contact.darkest_secret << " *" << std::endl;
}

void	PhoneBook::search(void)
{
	int i;

	for (i = 0; i < nums; i++)
	{
		std::cout << std::string(9, ' ') << i << '|' ;
		PrintContact(contact[i].first_name);
		PrintContact(contact[i].last_name);
		PrintContact(contact[i].nick_name);
		std::cout << std::endl;
	}
	if (nums == 0)
		return ;
	while (true)
	{
		std::string num;
		std::cout << "PLEASE TYPE THE INDEX : ";
		std::getline(std::cin, num);
		if (std::cin.eof())
			return ;
		else
		{
			if (!(num.size() == 1 && (num[0] >= '0' && num[0] <= '9')))
				continue;
			i = std::atoi(num.c_str());
			if (i > nums - 1 || i < 0)
			{
				std::cin.clear();
				continue ;
			}
		}
		std::cin.clear();
		PrintContact(contact[i]);
		return ;
	}
}
