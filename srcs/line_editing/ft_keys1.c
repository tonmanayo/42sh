/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:12:20 by tmack             #+#    #+#             */
/*   Updated: 2016/09/11 16:55:18 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	ft_move_left(t_shell *s, char *buff)
{
	int		i;

	i = -1;
	if ((buff[0] == 27 && buff[1] == 91 && buff[2] == 68 && s->curs_pos > 0)
			|| s->on == 1)
	{
		if (((s->curs_pos + s->prompt_len) % s->width) == 0)
		{
			tputs(tgetstr("up", 0), 1, ft_putchar_re);
			while (++i <= s->width)
				tputs(tgetstr("nd", 0), 1, ft_putchar_re);
			s->curs_pos--;
		}
		else
		{
			s->curs_pos--;
			tputs(tgetstr("le", 0), 1, ft_putchar_re);
		}
	}
}

void	ft_move_right(t_shell *s, char *buff)
{
	if ((buff[0] == 27 && buff[1] == 91 && buff[2] == 67 &&
				s->curs_pos < s->str_len) || s->on == 1)
	{
		if (((s->curs_pos + s->prompt_len + 1) % s->width) == 0)
		{
			tputs(tgetstr("do", 0), 1, ft_putchar_re);
			tputs(tgetstr("cr", 0), 1, ft_putchar_re);
			s->curs_pos++;
		}
		else
		{
			s->curs_pos++;
			tputs(tgetstr("nd", 0), 1, ft_putchar_re);
		}
	}
}

void	ft_move_cur(char *buff, t_shell *s)
{
	ft_move_down(s, buff);
	ft_move_up(s, buff);
	ft_left_word(s, buff);
	ft_right_word(s, buff);
	ft_move_left(s, buff);
	ft_move_right(s, buff);
	ft_backspace(s, buff);
	ft_ctrl_l(buff, s);
	ft_history_up(s, buff);
	ft_history_down(s, buff);
	ft_end_right(s, buff);
	ft_end_left(s, buff);
	ft_autocomplete(s, buff);
	ft_enter(buff, s);
	ft_high_right(s, buff);
	ft_cut(s, buff);
	ft_cpy(s, buff);
	ft_paste(s, buff);
}

void	ft_key_exit(char *buff, t_shell *s)
{
	if (buff[0] == 4 && buff[1] == 0 && buff[2] == 0)
	{
		if (s->fork_pid == 0)
		{
			free_t_shell(s);
			tputs(tgetstr("ve", 0), 1, ft_putchar_re);
			tputs(tgetstr("te", 0), 1, ft_putchar_re);
			tcsetattr(STDIN_FILENO, TCSADRAIN, &s->default_term);
			exit(EXIT_SUCCESS);
		}
		else
			kill(s->fork_pid, SIGKILL);
	}
}

void	buffer(t_shell *s)
{
	char	*temp;

	s->width = tgetnum("co");
	temp = (char *)malloc(sizeof(char) * 4096);
	ft_bzero(temp, 4096);
	read(0, temp, 4096);
	ft_key_exit(temp, s);
	ft_move_cur(temp, s);
	ft_print_char(temp, s);
	free(temp);
}
