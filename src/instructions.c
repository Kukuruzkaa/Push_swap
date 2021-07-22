/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:46:17 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 19:06:34 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char name)
{
	if (stack && (*stack)->next)
		ft_sw((int *)(*stack)->content, (int *)(*stack)->next->content);
	if (name == 'a')
		write(1, "sa\n", 3);
	else if (name == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **stack_from, t_list **stack_to, char name)
{
	t_list	*tmp;

	if (!stack_from)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (!stack_to)
	{
		*stack_to = tmp;
		(*stack_to)->next = NULL;
	}
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
	if (name == 'b')
		write(1, "pb\n", 3);
	else if (name == 'a')
		write(1, "pa\n", 3);
}	

void	ft_rot(t_list **stack, char name)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!(*stack && (*stack)->next))
		return ;
	tmp1 = *stack;
	*stack = (*stack)->next;
	tmp2 = *stack;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp1;
	tmp1->next = NULL;
	if (name == 'a')
		write(1, "ra\n", 3);
	if (name == 'b')
		write(1, "rb\n", 3);
}

void	ft_revrot(t_list **stack, char name)
{
	t_list	*last;
	t_list	*newlast;

	if (!(*stack && (*stack)->next))
		return ;
	last = *stack;
	while (last->next)
	{
		newlast = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	newlast->next = NULL;
	if (name == 'a')
		write(1, "rra\n", 4);
	if (name == 'b')
		write(1, "rrb\n", 4);
}
