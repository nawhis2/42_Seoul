/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:55:11 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/15 20:22:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// #include "Array.hpp"

// int main()
// {
// 	Array<int> int_arr;
// 	Array<double> double_arr(3);
	
// 	try
// 	{
// 		for (int i = 0 ; i < 10; i++)
// 		{
// 			double_arr.setElem(i, i + 1);
// 		}
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;	
// 	}	

// 	try
// 	{
// 		for (int i = 0 ; i < 3; i++)
// 			std::cout << double_arr[i] << std::endl;
			
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;	
// 	}	
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {

        std::cout << "------------------------------------------------------------------------" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "------------------------------------------------------------------------" << std::endl;
    try
    {
        Array<double> dbarray;
        std::cout << dbarray.getElem(0) <<std::endl;
        std::cout << dbarray.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "------------------------------------------------------------------------" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "------------------------------------------------------------------------" << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
