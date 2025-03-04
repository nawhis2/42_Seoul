/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:54 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/09 18:54:42 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::push_data(std::stack<int> &st, int data)
{
	st.push(data);
}

int RPN::pop_data(std::stack<int> &st)
{
	int ret = st.top();
	st.pop();
	return (ret);
}
