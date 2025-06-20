/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:25:45 by cpoulain          #+#    #+#             */
/*   Updated: 2025/06/20 13:28:07 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

template				<typename T>
typename T::iterator	easyfind(T &container, int ref)
{
	return (std::find(container.begin(), container.end(), ref));
}
