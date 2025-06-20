/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:28:29 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/20 13:46:59 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "../includes/easyfind.hpp"

int	main()
{
	int					n = 100;
	std::vector<int>	vec(n, 0);
	std::deque<int>		deck(n, 0);
	std::list<int>		list;

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		vec[i] = i;
		deck[i] = i;
		list.push_back(i);
	}

	for (int i = 0; i < n / 4; i++)
	{
		int	t = rand() % n;
		std::cout << std::endl << i << "th : Finding : " << t << std::endl;
		std::cout << "Vector : " << *easyfind(vec, t) << std::endl;
		std::cout << "Deck : " << *easyfind(deck, t) << std::endl;
		std::cout << "List : " << *easyfind(list, t) << std::endl;

	}
}
