/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:04 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 18:52:59 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		chunks;
	int		length;
	int		*keys;

	i = 0;
	length = ft_lstsize(*stack_a);
	keys = ft_lsttotab_getkeys(*stack_a);
	chunks = ft_chunks(length);
	if (stack_a == NULL)
		return ;
	while (i < chunks && (*stack_a)->next)
	{
		if (*(int *)(*stack_a)->content < keys[i])
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rot(stack_a, 'a');
		if (!(check_elements(*stack_a, keys[i])))
			i++;
	}
	free(keys);
}

void	ft_max_a(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		index;

	index = -1;
	max = find_max(*stack_a, &index);
	while (ft_lstsize(*stack_a) > 1)
	{
		while (*(int *)(*stack_a)->content == max)
			ft_rotataions(stack_a, 'a', index);
		ft_push(stack_a, stack_b, 'b');
	}
}

void	ft_sort_b(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		index;

	index = -1;
	while (ft_lstsize(*stack_b) > 0)
	{
		max = find_max(*stack_b, &index);
		while (*(int *)(*stack_b)->content != max)
			ft_rotataions(stack_b, 'b', index);
		ft_push(stack_b, stack_a, 'a');
	}
}

void	ft_big_sort(t_list **stack_a, t_list **stack_b)
{
	ft_sort_a(stack_a, stack_b);
	ft_max_a(stack_a, stack_b);
	ft_sort_b(stack_a, stack_b);
}
