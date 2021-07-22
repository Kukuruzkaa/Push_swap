/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:00:33 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 19:10:35 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_merge_stacks(t_list **stack_a, t_list **stack_b)
{
	int	rotation_nb;

	rotation_nb = 0;
	while (ft_lstsize(*stack_b) > 0 || !(ft_list_sorted(stack_a)))
	{
		if (ft_lstsize(*stack_b) > 0
			&& (*(int *)(*stack_b)->content < *(int *)(*stack_a)->content
			|| rotation_nb == ft_lstsize(*stack_a)))
			ft_push(stack_b, stack_a, 'a');
		else
		{
			ft_rot(stack_a, 'a');
			rotation_nb++;
		}
	}
}

void	ft_middle_sort_four(t_list **stack_a, t_list **stack_b)
{
	int		index;

	while (*(int *)(*stack_a)->content != find_min(*stack_a, &index))
		ft_rot(stack_a, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_simple_sort(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
}

void	ft_middle_sort_five(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	ft_simple_sort(stack_a, 'a');
	ft_simple_sort(stack_b, 'b');
	ft_merge_stacks(stack_a, stack_b);
}
