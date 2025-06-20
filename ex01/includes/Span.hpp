/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:23:26 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/20 14:49:59 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

const std::string	ERR_INPUT_SIZE	= "Input size bigger than max";
const std::string	ERR_FIND_SPAN	= "No span can be found";
const std::string	ERR_SPACE		= "No space left";

class Span: protected std::vector<int>
{
	protected:
		unsigned int	max;
		Span();
	public:
/* ------------------------------ Constructors ------------------------------ */
		Span(unsigned int max = 1);
		Span(const Span &other);
		template	<class InputIterator>
		Span(InputIterator begin, InputIterator end)
		{
			this->max = std::distance(begin, end);
			this->insert(this->end(), begin, end);
		}
/* ---------------------------- Operator overload --------------------------- */
		Span	&operator=(const Span &other);
/* ------------------------------- Destructors ------------------------------ */
		~Span();
/* --------------------------------- Methods -------------------------------- */
		void	addNumber(int n);

		template	<class InputIterator>
		void		addRange(InputIterator begin, InputIterator end)
		{
			if (this->max < this->size() + (end - begin))
				throw (std::out_of_range(ERR_INPUT_SIZE));
			this->insert(this->end(), begin, end);
		}
/* -------------------------------- Functions ------------------------------- */
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};
