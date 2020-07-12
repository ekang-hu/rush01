/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 10:23:24 by ayeon             #+#    #+#             */
/*   Updated: 2020/07/12 16:17:38 by ayeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_input[16];
extern int	g_board[5][5];
extern int	g_move[4][2];
extern int	*g_start_point[4];

int		is_valid_sub(int *p, int move, int input)
{
	int i;
	int cnt;
	int max;

	i = 1;
	cnt = 0;
	max = 0;
	while (i < 5)
	{
		if (*p > max)
		{
			max = *p;
			cnt++;
		}
		p += move;
		i++;
	}
	if (cnt == input)
		return (1);
	else
		return (0);
}

int		is_valid_board(void)
{
	int input;
	int i;
	int j;
	int *p;

	input = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		p = g_start_point[i];
		while (j < 4)
		{
			if (!is_valid_sub(p, g_move[i][0], g_input[input]))
				return (0);
			p += g_move[i][1];
			j++;
			input++;
		}
		i++;
	}
	return (1);
}

int		is_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int		is_valid_input(char *input)
{
	int pos;

	pos = 0;
	while (*input)
	{
		while (*input && is_space(*input))
			input++;
		if (*input)
		{
			if ('1' <= *input && *input <= '4')
			{
				if (pos == 16)
					return (0);
				else if (*(input + 1) && !is_space(*(input + 1)))
					return (0);
				g_input[pos++] = *input - '0';
			}
			else
				return (0);
			input++;
		}
	}
	return (1);
}
