/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:27:30 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/16 19:02:38 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

void	create_stack(t_node **head, int argc, char **argv, int index);
void	check_order(t_node	**head);
void	check_duplicate(t_node *head, int number, char **argv, char not_argv);
void	lst_erase(t_node **head);
void	ft_lstadd_back01(t_node **alst, t_node *new);
t_node	*ft_lstnew01(int content);
int		my_abs(int nb);
int		lowest_n(t_node *head);
void	point_head_to_min(t_node **head, int val);
int		is_sorted(t_node **head);
void	sorting(t_node **a, t_node **b);
int		ft_lstsize01(t_node *lst);
int		is_number(char *argv);
int		is_digit(char c);
int		is_sign(char c);
int		*list_to_arr(t_node **a, int size);
void	error_free(char **argv, t_node **head, char not_argv, char erase);
void	ft_error_number(char **argv, t_node **head, char c, int n);
void	sort_lis(t_node **a, t_node **b, int size);
int		*lis(int arr[], int n, int *len_lis);
void	error_malloc(void);
int		*cpy_arr(int *arr, int size);
int		max_nbr(int a, int b);

//instructions

void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);
void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);
void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);
void	ft_pa(t_node **b, t_node **a);
void	ft_pb(t_node **a, t_node **b);

#endif