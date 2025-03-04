/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:55 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/09 18:56:45 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <algorithm>
# include <iostream>
# include <sstream>

class RPN
{
private:
	RPN();

public:
	RPN(const RPN &copy);
	RPN& operator=(const RPN &copy);
	~RPN();

	static void push_data(std::stack<int> &st, int data);
	static int pop_data(std::stack<int> &st);
};

#endif