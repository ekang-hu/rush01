/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeekim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 13:05:10 by jaeekim           #+#    #+#             */
/*   Updated: 2020/07/12 18:05:18 by ayeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_check_row[5][5];
int	g_check_col[5][5];
int	*g_start_point[4];
int	g_move[4][2];
extern int	g_board[5][5];

void	init_check_arr(void)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			g_check_row[i][j] = 0;
			g_check_col[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_start_arr(void)
{
	g_start_point[0] = &g_board[1][1];
	g_start_point[1] = &g_board[4][1];
	g_start_point[2] = &g_board[1][1];
	g_start_point[3] = &g_board[1][4];
}

void	init_move_arr(void)
{
	g_move[0][0] = 5;
	g_move[0][1] = 1;
	g_move[1][0] = -5;
	g_move[1][1] = 1;
	g_move[2][0] = 1;
	g_move[2][1] = 5;
	g_move[3][0] = -1;
	g_move[3][1] = 5;
}
