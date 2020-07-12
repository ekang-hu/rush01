/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 09:56:44 by ekang             #+#    #+#             */
/*   Updated: 2020/07/12 18:03:44 by ayeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		rush(void);
int		is_valid_input(char *input);

int		main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "Error\n", 6);
	else if (!(is_valid_input(argv[1]) && rush()))
		write(1, "Error\n", 6);
	return (0);
}
