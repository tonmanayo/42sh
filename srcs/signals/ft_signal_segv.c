/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_segv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:59:42 by kgani             #+#    #+#             */
/*   Updated: 2016/09/11 10:29:12 by kgani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	ft_signal_segv(void)
{
	t_shell *s;

	s = ft_get_shell();
	free_t_shell(s);
	exit(EXIT_SUCCESS);
}
