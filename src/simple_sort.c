/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:25:46 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 19:13:01 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_rra(t_list **stack_a)
{
	ft_swap(stack_a, 'a');
	ft_revrot(stack_a, 'a');
}

void	ft_swap_ra(t_list **stack_a)
{
	ft_swap(stack_a, 'a');
	ft_rot(stack_a, 'a');
}

void	ft_simple_sort(t_list **stack, char name)
{
	int	nb1;
	int	nb2;
	int	nb3;

	if ((ft_lstsize(*stack)) == 2
		&& *(int *)(*stack)->next->content < *(int *)(*stack)->content)
		ft_swap(stack, name);
	else if (ft_lstsize(*stack) == 3)
	{
		nb1 = *(int *)(*stack)->content;
		nb2 = *(int *)(*stack)->next->content;
		nb3 = *(int *)(*stack)->next->next->content;
		if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
			ft_swap(stack, name);
		else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
			ft_swap_rra(stack);
		else if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3)
			ft_rot(stack, name);
		else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
			ft_swap_ra(stack);
		else if (nb1 < nb2 && nb2 > nb3 && nb1 > nb3)
			ft_revrot(stack, name);
	}
}
