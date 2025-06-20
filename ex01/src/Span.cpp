/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:30:17 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/20 14:49:55 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

Span::Span() {}

Span::Span(unsigned int max): max(max) {}
Span::Span(const Span &other): std::vector<int>(other), max(other.max) {}

/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */

Span	&Span::operator=(const Span &other)
{
	*static_cast<std::vector<int> *>(this) = other;
	max = other.max;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

Span::~Span() {}

/* -------------------------------------------------------------------------- */
/*                                   Methods                                  */
/* -------------------------------------------------------------------------- */

void	Span::addNumber(int n)
{
	if (this->max <= this->size())
		throw (std::out_of_range(ERR_SPACE));
	this->push_back(n);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

unsigned int	Span::shortestSpan()
{
	unsigned int	minSpan;
	unsigned int	i;

	minSpan = UINT_MAX;
	if (this->size() < 2)
		throw (std::domain_error(ERR_FIND_SPAN));
	vector<int> tmp(this->begin(), this->end());
	std::sort(tmp.begin(), tmp.end());
	for (i = 1; i < this->size(); i++)
		minSpan = std::min(minSpan, static_cast<unsigned int>(std::abs((*this)[i] - (*this)[i - 1])));
	return (minSpan);
}

unsigned int	Span::longestSpan()
{
	if (this->size() < 2)
		throw (std::domain_error(ERR_FIND_SPAN));
	return (*std::max_element(this->begin(), this->end()) - *std::min_element(this->begin(), this->end()));
}
