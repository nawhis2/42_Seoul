/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:32:44 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/10 16:19:58 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <cmath>
# include <algorithm>
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <list>

class PmergeMe
{
private:
	PmergeMe();

public:
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &copy);
	~PmergeMe();

	static void PrintInputLine(int argc, char **argv);
	static void PrintSortedLine(std::vector<int> &v);
	static void PrintSortedLine(std::list<int> &lst);
	
	static size_t  Jacobsthal(int idx);
	
	static bool pushArgu(std::vector<int> &v, std::list<int> &lst, int argc, char **argv);
	
	static void sortMainChain(std::vector<int> &v, unsigned long &pairNum);
	static void mergeInsertionSort(std::vector<int> &v, unsigned long pairNum);
	static void binarySearch(std::vector<std::pair<int, int> > &v, std::pair<int, int> &val, int begin, int end);
	static int  findEndIndex(std::vector<std::pair<int, int> > &v, int val);
	

	static std::list<int>::iterator  accessListElem(std::list<int> &lst, int idx);
	static std::list<std::pair<int, int> >::iterator accessListElem(std::list<std::pair<int, int> > &lst, int idx);
	static void sortMainChain(std::list<int> &lst, unsigned long &pairNum);
	static void mergeInsertionSort(std::list<int> &lst, unsigned long pairNum);
	static void binarySearch(std::list<std::pair<int, int> > &lst, std::pair<int, int> &val, int begin, int end);
	static int  findEndIndex(std::list<std::pair<int, int> > &lst, int val);

	static void updateContainer(std::vector<int> &v, std::vector<std::pair<int, int> > &main, unsigned long pairNum);
	static void updateContainer(std::list<int> &lst, std::list<std::pair<int, int> > &main, unsigned long pairNum);
};

#endif