/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:31:56 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/17 21:03:47 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(char **argv, t_node **head, char not_argv, char erase)
{
	int		index;

	if (not_argv)
	{
		index = 0;
		while (argv[index])
			free(argv[index++]);
		free (argv);
	}
	if (erase)
		lst_erase(head);
}

void	ft_error_number(char **argv, t_node **head, char c, int n)
{
	if (n == 1)
		ft_putstr_fd("Error digit\n", 2);
	if (n == 2)
		write(2, "Error, int is not in range\n", 28);
	error_free(argv, head, c, 1);
	exit(0);
}

void	error_malloc(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}