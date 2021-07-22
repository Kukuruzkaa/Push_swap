/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:47:29 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 19:23:39 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sw(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_max(t_list *stack_a, int *index)
{
	int	max;
	int	i;

	i = 0;
	if (stack_a == NULL)
		return (0);
	max = *(int *)stack_a->content;
	while (stack_a)
	{
		if (max < *(int *)stack_a->content)
		{
			max = *(int *)stack_a->content;
			*index = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (max);
}

int	find_min(t_list *stack_a, int *index)
{
	int	min;
	int	i;

	i = 0;
	if (stack_a == NULL)
		return (0);
	min = *(int *)stack_a->content;
	while (stack_a)
	{
		if (min > *(int *)stack_a->content)
		{
			min = *(int *)stack_a->content;
			*index = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (min);
}

void	ft_rotataions(t_list **stack, char name, int index)
{
	int	length;

	length = ft_lstsize(*stack);
	if (index < length / 2)
		ft_rot(stack, name);
	else
		ft_revrot(stack, name);
}
