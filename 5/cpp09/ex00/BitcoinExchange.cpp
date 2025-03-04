/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:37:32 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/10 10:58:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::readDB(std::map<int, double> &container)
{
	std::stringstream ss;
	std::string line;
	std::ifstream DB("data.csv");
	
	getline(DB, line);
	int lineNum = 1;
	while (DB.is_open() && getline(DB, line))
	{
		try
		{
			int		year = 0;
			int		month = 0;
			int		day = 0;
			int		date = 0;
			double	exRate = 0;
			
			lineNum++;
			ss << line;
			ss >> year;
			if (year < 2000 || year > 2025)
				throw invalidDateException();
			ss.ignore(1, '-');
			ss >> month;
			if (month < 1 || month > 12)
				throw invalidDateException();
			ss.ignore(1, '-');
			ss >> day;
			BitcoinExchange::checkValidDay(year, month, day);
			date = year * 10000 + month * 100 + day;
			ss.ignore(1, ',');
			ss >> exRate;
			container[date] = exRate;
			ss.str("");
			ss.clear();
		}
		catch(const std::exception& e)
		{
			ss.str("");
			ss.clear();
			std::cout << e.what();
		}
	}
}

bool BitcoinExchange::checkLunarYear(int year)
{
	int y = year / 10000;
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
				return true;
		}
		else
			return true;
	}
	return false;
}

std::string BitcoinExchange::stringDate(int date)
{
	std::string ret;
	std::stringstream ss;

	int year = date / 10000;
	
	ss << year << '-';
	date %= 10000;
	
	int month = date / 100;
	if (month < 10)
		ss << '0' << month << '-';
	else
		ss << month << '-';
	date %= 100;

	if (date < 10)
		ss << '0' << date;
	else 
		ss << date;
		
	ret = ss.str();
	return ret;
}

void BitcoinExchange::checkValidDay(int year, int month, int day)
{
	int max_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((month == 2 && checkLunarYear(year)))
	{
		if (day > 29 || day < 0)
			throw invalidDateException();
	}
	else
	{
		if (day > max_day[month - 1] || day < 0)
			throw invalidDateException();
	}
}

void BitcoinExchange::readInput(std::map<int, double> &DB, std::string file)
{
	std::stringstream ss;
	std::string line;
	std::ifstream f(file);
	int lineNum = 1;

	if (f.is_open() && getline(f, line) && line == "date | value")
	{
		while (getline(f, line))
		{
			try
			{
				lineNum++;
				std::string beforecomma, aftercomma;
				int		year = 0;
				int		month = 0;
				int		day = 0;
				int		date = 0;
				char	sep = 0;
				double	value = 0;

				if (line.find(" | ") == std::string::npos)
					throw invalidFormException();
				else
				{
					beforecomma = line.substr(0, line.find(" | "));
					aftercomma = line.substr(line.find(" | ") + 3);
				}

				if (aftercomma.size() < 1)
					throw invalidFormException();

				ss << line;
				ss >> year;
				if (year < 0)
					throw invalidDateException();
				ss.ignore(1, '-');
				ss >> month;
				if (month < 0 || month > 12)
					throw invalidDateException();
				ss.ignore(1, '-');
				ss >> day;
				BitcoinExchange::checkValidDay(year, month, day);
				ss >> sep;
				if (sep != '|')
					throw invalidFormException();
				ss >> value;
				if (value < 0)
					throw negativeValException();
				else if (value > 1000)				
					throw largeValException();
				date = year * 10000 + month * 100 + day;
				
				if (DB.find(date) != DB.end())
					std::cout << stringDate(date) << " => " << value << " = " << DB[date] * value << std::endl;
				else if (DB.upper_bound(date) != DB.begin())
					std::cout << stringDate(date) << " => " << value << " = " << (--(DB.upper_bound(date)))->second * value << std::endl;
				else
					throw noDataException();
				ss.str("");
				ss.clear();
			}
			catch(const std::exception& e)
			{
				ss.str("");
				ss.clear();
				std::cout << e.what();
			}
		}
	}
	else
		std::cout << "Error: Check the file again" << std::endl;
}

const char * BitcoinExchange::noDataException::what() const throw()
{
	return ("Error: There is no data of the date\n");
}

const char * BitcoinExchange::invalidDateException::what() const throw()
{
	return ("Error: bad input date\n");
}

const char * BitcoinExchange::negativeValException::what() const throw()
{
	return ("Error: not a positive value\n");
}
	
const char * BitcoinExchange::largeValException::what() const throw()
{
	return ("Error: too large a value\n");
}

const char * BitcoinExchange::invalidFormException::what() const throw()
{
	return ("Error: invalid input form\n");
}