/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:25:58 by ayeon             #+#    #+#             */
/*   Updated: 2020/07/12 17:42:32 by ayeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_check_row[5][5];
extern int	g_check_col[5][5];
int	g_board[5][5];

void	init_check_arr(void);
void	init_start_arr(void);
void	init_move_arr(void);
int		is_valid_board(void);
int		fill_board(int r, int c);

void	print_board(void)
{
	int		r;
	int		c;
	char	num;

	r = 1;
	while (r < 5)
	{
		c = 1;
		while (c < 4)
		{
			num = g_board[r][c] + '0';
			write(1, &num, 1);
			write(1, " ", 1);
			c++;
		}
		num = g_board[r][c] + '0';
		write(1, &num, 1);
		write(1, "\n", 1);
		r++;
	}
}

int		fill_sub(int r, int c)
{
	int num;

	num = 0;
	while (++num < 5)
	{
		if (g_check_row[r][num] || g_check_col[c][num])
			continue ;
		g_check_row[r][num] = 1;
		g_check_col[c][num] = 1;
		g_board[r][c] = num;
		print_board();
		write(1, "\n", 1);
		if (fill_board(r, c + 1))
			return (1);
		g_check_row[r][num] = 0;
		g_check_col[c][num] = 0;
	}
	return (0);
}

int		fill_board(int r, int c)
{
	if (r == 5)
	{
		if (is_valid_board())
		{
			print_board();
			return (1);
		}
		return (0);
	}
	if (c == 5)
		return (fill_board(r + 1, 1));
	else
	{
		return (fill_sub(r, c));
	}
}

int		rush(void)
{
	init_check_arr();
	init_start_arr();
	init_move_arr();
	return (fill_board(1, 1));
}
