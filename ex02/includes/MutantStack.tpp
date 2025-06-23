/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:43:21 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/23 12:52:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template	<class T, class Container>
typename	MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template	<class T, class Container>
typename	MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}
