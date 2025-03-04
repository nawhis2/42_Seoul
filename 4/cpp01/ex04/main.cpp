/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:37:19 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 11:16:00 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ex04.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	std::string	filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::size_t s1_len = s1.size();
	std::size_t s2_len = s2.size();
	{
		std::ifstream infile(argv[1]);
		std::ofstream outfile((filename + ".replace").c_str());
		{
			std::string line;
			while (getline(infile, line))
			{
				std::size_t pos = 0;
				while (1)
				{
					if (std::string::npos != (pos = line.find(argv[2], pos)))
					{
						line.erase(pos, s1_len);
						line.insert(pos, s2);
						pos += s2_len;
					}
					else
						break;
				}
				outfile << line << '\n';
			}
		}
		infile.close();
		outfile.close();
	}
	return 0;
}