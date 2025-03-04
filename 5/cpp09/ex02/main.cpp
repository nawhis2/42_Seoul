/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:32:41 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/15 12:16:35 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	clock_t start_v, finish_v;
	clock_t start_lst, finish_lst;
	std::vector<int> v;
	std::list<int> lst;
	if (!PmergeMe::pushArgu(v, lst, argc, argv))
		return (1);
	PmergeMe::PrintInputLine(argc, argv);


	/* check FJ with std::vector */
	unsigned long pairNum = 1;
	start_v = clock();
	PmergeMe::sortMainChain(v, pairNum);
	PmergeMe::mergeInsertionSort(v, pairNum);
	finish_v = clock();

	/* check FJ with std::list */
	pairNum = 1;
	start_lst = clock();
	PmergeMe::sortMainChain(lst, pairNum);
	PmergeMe::mergeInsertionSort(lst, pairNum);
	finish_lst = clock();

	/* Print sorting numbers */
	PmergeMe::PrintSortedLine(v);
	PmergeMe::PrintSortedLine(lst);

	// /* Print Sorted or not : std::is_sorted is c++11 function. */
	std::cout << std::boolalpha << "* std::vector sorting result: "<< std::is_sorted(v.begin(), v.end()) <<" *" << std::endl;
	std::cout << std::boolalpha << "* std::list   sorting result: "<< std::is_sorted(lst.begin(), lst.end()) <<" *" << std::endl;

	// /* Print the operating time */
	std::cout << "Time to process a range of " << argc - 1 << " elements with [std::vector] : " << finish_v - start_v << " ms.\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with [std::list]   : " << finish_lst - start_lst << " ms.\n";

	return (0);
}