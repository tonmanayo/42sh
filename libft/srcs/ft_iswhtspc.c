/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhtspc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:26:20 by kbamping          #+#    #+#             */
/*   Updated: 2016/08/10 14:27:35 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhtspc(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}
