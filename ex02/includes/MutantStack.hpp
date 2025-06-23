/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:45:04 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/23 12:46:07 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template	<class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;

		iterator begin();
		iterator end();
};
