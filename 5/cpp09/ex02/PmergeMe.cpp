/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:32:43 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/15 12:18:31 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::pushArgu(std::vector<int> &v, std::list<int> &lst, int argc, char **argv)
{
	std::stringstream ss;
	int elem;
	for (int i = 1 ; i < argc; i++)
	{
		ss << argv[i];
		ss >> elem;
		if (elem < 1)
		{
			std::cout << "Error" << std::endl;
			return (false);
		}
		v.push_back(elem);
		lst.push_back(elem);
		ss.str("");
		ss.clear();
	}
	return (true);
}

void PmergeMe::PrintInputLine(int argc, char **argv)
{
	std::cout << "Before:\t  ";
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
}

// std::vector JF Implementation
void PmergeMe::PrintSortedLine(std::vector<int> &v)
{
	std::cout << "std::vector After:\t";
	for (unsigned long i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
}

void PmergeMe::sortMainChain(std::vector<int> &v, unsigned long &pairNum)
{
	if (pairNum > v.size() / 2)
	{
		pairNum /= 2;
		return ;
	}
	for (unsigned long i = 0; i + pairNum * 2 <= v.size(); i += pairNum * 2)
	{
		if (v[i] < v[i + pairNum])
			for (unsigned long j = 0; j < pairNum; j++)
				std::swap(v[i + j], v[i + j + pairNum]);
	}
	pairNum *= 2;
	PmergeMe::sortMainChain(v, pairNum);
}

void PmergeMe::binarySearch(std::vector<std::pair<int, int> > &v, std::pair<int, int> &val, int begin, int end)
{
	if (begin >= end)
	{
		if (v[begin].first > val.first)
			v.insert(v.begin() + begin, val);
		else
			v.insert(v.begin() + begin + 1, val);
		return ;
	}
	int center = (begin + end) / 2;
	if (v[center].first > val.first)
		PmergeMe::binarySearch(v, val, begin, center - 1);
	else
		PmergeMe::binarySearch(v, val, center + 1, end);
}

int PmergeMe::findEndIndex(std::vector<std::pair<int, int> > &v, int val)
{
	size_t i = 0;
	while (i < v.size() && v[i].first < val)
	{
		i++;
	}
	return (i);
}

void PmergeMe::updateContainer(std::vector<int> &v, std::vector<std::pair<int, int> > &main, unsigned long pairNum)
{
	std::vector<int> sorted_v;
	for (unsigned long i = 0; i < main.size(); i++)
		sorted_v.insert(sorted_v.begin() + i * pairNum, v.begin() + main[i].second, v.begin() + main[i].second + pairNum);
	for (unsigned long i = 0 ; i < sorted_v.size(); i++)
		v[i] = sorted_v[i];
}

void PmergeMe::mergeInsertionSort(std::vector<int> &v, unsigned long pairNum)
{
	if (pairNum == 0)
	{
		return ;
	}
	std::vector<std::pair<int, int> > main, pend;
	
	unsigned long idx;
	for (idx = 0; idx + 2 * pairNum <= v.size(); idx += pairNum * 2)
	{
		main.push_back(std::pair<int, int>(v[idx], idx));
		pend.push_back(std::pair<int, int>(v[idx + pairNum], idx + pairNum));
	}
	if (idx + pairNum <= v.size())
	{
		pend.push_back(std::pair<int, int>(v[idx], idx));
		idx += pairNum;
	}

	size_t m_size = main.size();
	main.insert(main.begin(), pend[0]);
	for (size_t i = 2; PmergeMe::Jacobsthal(i - 1) <= m_size; i++)
	{
		int range = std::min(Jacobsthal(i) + Jacobsthal(i - 1), main.size());
		for (size_t j = std::min(PmergeMe::Jacobsthal(i), pend.size()); j > PmergeMe::Jacobsthal(i - 1); j--)
		{
			PmergeMe::binarySearch(main, pend[j - 1], 0, range - 1);
		}
	}
	updateContainer(v, main, pairNum);
	mergeInsertionSort(v, pairNum / 2);
}

size_t PmergeMe::Jacobsthal(int idx)
{
	return ((pow(2, idx + 1) + pow(-1, idx)) / 3);
}

// std::list FJ Implementation

int PmergeMe::findEndIndex(std::list<std::pair<int, int> > &lst, int val)
{
	int i = 0;
	for (std::list<std::pair<int, int> >::iterator it = lst.begin(); it != lst.end(); ++it)
		if ((*it).first < val)
			i++;
	return (i);
}

void PmergeMe::updateContainer(std::list<int> &lst, std::list<std::pair<int, int> > &main, unsigned long pairNum)
{
	std::list<int> sorted_lst;
	for (unsigned long i = 0; i < main.size(); i++)
		sorted_lst.insert(accessListElem(sorted_lst, i * pairNum), accessListElem(lst, (*accessListElem(main, i)).second), accessListElem(lst, (*accessListElem(main, i)).second + pairNum));
	
	for (unsigned long i = 0 ; i < sorted_lst.size(); i++)
		lst.pop_front();
	for (std::list<int>::iterator it = --(sorted_lst.end());; --it)
	{
		lst.push_front(*it);
		if (it == sorted_lst.begin())
			break;
	}
}

void PmergeMe::PrintSortedLine(std::list<int> &lst)
{
	std::cout << "std::list   After:\t";
	for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

std::list<int>::iterator PmergeMe::accessListElem(std::list<int> &lst, int idx)
{	
	std::list<int>::iterator iter = lst.begin();
	while (idx)
	{
		++iter;
		--idx;
	}
	return (iter);
}

std::list<std::pair<int, int> >::iterator PmergeMe::accessListElem(std::list<std::pair<int, int> > &lst, int idx)
{	
	std::list<std::pair<int,int> >::iterator iter = lst.begin();
	while (idx)
	{
		++iter;
		--idx;
	}
	return (iter);
}

void PmergeMe::sortMainChain(std::list<int> &lst, unsigned long &pairNum)
{
	if (pairNum > lst.size() / 2)
	{
		pairNum /= 2;
		return ;
	}
	for (unsigned long i = 0; i + pairNum * 2 <= lst.size(); i += pairNum * 2)
	{
		if (*accessListElem(lst, i) < *accessListElem(lst, i + pairNum))
			for (unsigned long j = 0; j < pairNum; j++)
				std::iter_swap(accessListElem(lst, i + j), accessListElem(lst, i + j + pairNum));
	}
	pairNum *= 2;
	PmergeMe::sortMainChain(lst, pairNum);
}

void PmergeMe::binarySearch(std::list<std::pair<int, int> > &lst, std::pair<int, int> &val, int begin, int end)
{
	if (begin >= end)
	{
		if ((*accessListElem(lst, begin)).first > val.first)
			lst.insert(accessListElem(lst, begin), val);
		else
			lst.insert(accessListElem(lst, begin + 1), val);
		return ;
	}
	int center = (begin + end) / 2;
	if ((*accessListElem(lst, center)).first > val.first)
		PmergeMe::binarySearch(lst, val, begin, center - 1);
	else
		PmergeMe::binarySearch(lst, val, center + 1, end);
}

void PmergeMe::mergeInsertionSort(std::list<int> &lst, unsigned long pairNum)
{
	if (pairNum == 0)
	{
		return ;
	}
	
	std::list<std::pair<int, int> > main, pend;
	unsigned long idx;
	for (idx = 0; idx + 2 * pairNum <= lst.size(); idx += pairNum * 2)
	{
		main.push_back(std::pair<int, int>(*accessListElem(lst, idx), idx));
		pend.push_back(std::pair<int, int>(*accessListElem(lst, idx + pairNum), idx + pairNum));
	}
	if (idx + pairNum <= lst.size())
	{
		pend.push_back(std::pair<int, int>(*accessListElem(lst, idx), idx));
		idx += pairNum;
	}

	size_t m_size = main.size();
	main.insert(main.begin(), *accessListElem(pend, 0));
	for (size_t i = 2; PmergeMe::Jacobsthal(i - 1) <= m_size; i++)
	{
		int range = std::min(Jacobsthal(i) + Jacobsthal(i - 1), main.size());
		for (size_t j = std::min(PmergeMe::Jacobsthal(i), pend.size()); j > PmergeMe::Jacobsthal(i - 1); j--)
		{
			PmergeMe::binarySearch(main, *accessListElem(pend, j - 1), 0, range - 1);
		}
	}
	updateContainer(lst, main, pairNum);
	mergeInsertionSort(lst, pairNum / 2);
}
