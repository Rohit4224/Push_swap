/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:27:30 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/14 19:52:36 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

void	create_stack(t_node **head, int argc, char **argv, int index);
void	check_order(t_node	**head);
void	lst_check(t_node *head, int number);
void	lst_erase(t_node **head);
void	ft_lstadd_back01(t_node **alst, t_node *new);
t_node	*ft_lstnew01(int content);
int		my_abs(int nb);

#endif