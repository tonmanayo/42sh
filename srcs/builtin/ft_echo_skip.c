/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 11:26:08 by kgani             #+#    #+#             */
/*   Updated: 2016/09/11 10:43:18 by kgani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int	ft_echo_skip(char *str)
{
	int	new_line;
	int	flag;

	if (ft_echo_isflag(str, &flag, &new_line))
		return (1);
	if (str[0] && str[0] == '$')
		return (1);
	return (0);
}
