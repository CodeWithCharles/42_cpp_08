/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:46:01 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/20 14:56:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	std::cout << "--- Basic Span Test ---" << std::endl;
	try {
		Span sp(5);
		sp.addNumber(std::rand() % 50);
		sp.addNumber(std::rand() % 50);
		sp.addNumber(std::rand() % 50);
		sp.addNumber(std::rand() % 50);
		sp.addNumber(std::rand() % 50);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Exception with too few elements ---" << std::endl;
	try {
		Span sp(1);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl; // should throw
	} catch (const std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Massive Span Test (10000 numbers via addNumber) ---" << std::endl;
	try {
		Span sp(10000);
		int	seed = std::rand() % 1000000 + 375;
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(std::rand() % seed);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Iterator Constructor Test with 10000 values ---" << std::endl;
	try {
		std::vector<int> vec;
		int	seed = std::rand() % 1000000 + 954;
		for (int i = 0; i < 10000; ++i)
			vec.push_back(std::rand() % seed); // predictable pattern
		Span sp(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- addRange() Method Test with 10000 values ---" << std::endl;
	try {
		std::vector<int> vec;
		int	seed = std::rand() % 1000000 + 367;
		for (int i = 0; i < 10000; ++i)
			vec.push_back(std::rand() % seed);
		Span sp(10000);
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}

