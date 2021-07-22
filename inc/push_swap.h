/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:33:51 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/22 19:34:05 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../Libft/libft.h"

//PARSING
void	put_error_and_exit(void);
void	check_maxint(long int maxint);
int		ft_check_number(const char *str);
void	ft_check_errors(int argc, char **argv);

//STACK
void	ft_create_stack(int argc, char **argv, t_list **stack_a);
void	ft_listclear(t_list **stack_a);

//PRESORT
int		is_sorted(int *tab, int length);
int		*sortarr(int *tab, int length);
int		ft_chunks(int length);
int		*ft_lsttotab_getkeys(t_list *stack_a);
int		*extract_keys(int *tab, int length);

//INSTRUCTIONS
void	ft_rot(t_list **stack, char name);
void	ft_revrot(t_list **stack, char name);
void	ft_push(t_list **stack_from, t_list **stack_to, char name);
void	ft_swap(t_list **stack, char name);
void	ft_swap_rra(t_list **stack_a);
void	ft_swap_ra(t_list **stack_a);
void	ft_sw(int *a, int *b);

//SORT
int		find_max(t_list *stack_a, int *index);
int		find_min(t_list *stack_a, int *index);
int		ft_list_sorted(t_list **stack_a);
int		check_elements(t_list *stack_a, int key);
void	ft_rotataions(t_list **stack, char name, int index);
void	ft_merge_stacks(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_simple_sort(t_list **stack_a, char name);
void	ft_middle_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_middle_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_big_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort_a(t_list **stack_a, t_list **stack_b);
void	ft_max_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_b(t_list **stack_a, t_list **stack_b);

#endif
