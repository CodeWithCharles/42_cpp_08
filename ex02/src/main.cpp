/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:50:42 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/23 12:56:35 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include "../includes/MutantStack.tpp"
#include <iostream>
#include <list>

void	mStack(void)
{
	std::cout << "===== Testing MutantStack =====" << std::endl;

	MutantStack<int>			mstack;
	MutantStack<int>::iterator	it;

	std::cout << "[PUSH] 5" << std::endl;
	mstack.push(5);
	std::cout << "[PUSH] 17" << std::endl;
	mstack.push(17);

	std::cout << "[TOP] " << mstack.top() << std::endl;

	std::cout << "[POP] (removes top element)" << std::endl;
	mstack.pop();

	std::cout << "[SIZE] " << mstack.size() << std::endl;

	std::cout << "[PUSH] 3, 5, 737, 42, 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);

	std::cout << "\n[ITERATING FORWARD]" << std::endl;
	it = mstack.begin();
	++it;
	--it;
	while (it != mstack.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "\n[ITERATING BACKWARD]" << std::endl;
	while (it != mstack.begin())
	{
		it--;
		std::cout << *it << std::endl;
	}

	std::cout << "[COPY] std::stack<int> s(mstack)" << std::endl;
	std::stack<int> s(mstack);
}

void	mList(void)
{
	std::cout << "\n===== Testing std::list =====" << std::endl;

	std::list<int>				mlist;
	std::list<int>::iterator	it;

	std::cout << "[PUSH_BACK] 5" << std::endl;
	mlist.push_back(5);
	std::cout << "[PUSH_BACK] 17" << std::endl;
	mlist.push_back(17);

	std::cout << "[BACK] " << mlist.back() << std::endl;

	std::cout << "[POP_BACK] (removes back element)" << std::endl;
	mlist.pop_back();

	std::cout << "[SIZE] " << mlist.size() << std::endl;

	std::cout << "[PUSH_BACK] 3, 5, 737, 42, 0" << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(42);
	mlist.push_back(0);

	std::cout << "\n[ITERATING FORWARD]" << std::endl;
	it = mlist.begin();
	++it;
	--it;
	while (it != mlist.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "\n[ITERATING BACKWARD]" << std::endl;
	while (it != mlist.begin())
	{
		it--;
		std::cout << *it << std::endl;
	}

	std::cout << "[COPY] std::list<int> s(mlist)" << std::endl;
	std::list<int> s(mlist);
}

int main()
{
	mStack();
	std::cout << std::endl << std::endl;
	mList();
	return 0;
}

