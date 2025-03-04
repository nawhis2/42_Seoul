/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:37:31 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/09 19:48:05 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>
# include <map>
# include <exception>

class BitcoinExchange
{
private:
	BitcoinExchange();
	int lastDate;

public:
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	int getlastDate() const;
	static void readDB(std::map<int, double> &container);
	static void readInput(std::map<int, double> &DB, std::string file);
	static bool checkLunarYear(int year);
	static std::string stringDate(int date);
	static void checkValidDay(int year, int month, int day);
	static void splitComma(std::string line);


	class noDataException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class invalidDateException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class negativeValException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
	
	class largeValException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class invalidFormException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};


#endif