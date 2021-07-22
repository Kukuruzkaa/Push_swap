/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:47:29 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 19:23:39 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(int argc, char **argv, t_list **stack_a)
{
	t_list	*new;
	int		i;

	i = 1;
	new = NULL;
	while (i <= argc - 1)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		new->content = malloc(sizeof(int));
		if (!new->content)
			return ;
		ft_lstadd_back(stack_a, new);
		new->next = NULL;
		*(int *)new->content = ft_atoi(argv[i]);
		i++;
	}
}

void	lstdelone(t_list **stack_a)
{
	if (*stack_a)
	{
		free((int *)(*stack_a)->content);
		free(*stack_a);
		*stack_a = NULL;
	}
}

void	ft_listclear(t_list **stack_a)
{
	t_list	*t;

	if (!*stack_a)
		return ;
	while (*stack_a)
	{
		t = (*stack_a)->next;
		lstdelone(stack_a);
		*stack_a = t;
	}
	*stack_a = NULL;
}
