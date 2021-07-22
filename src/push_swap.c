/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:46:17 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 19:27:18 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	if (ft_list_sorted(stack_a) == 1)
		return ;
	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2 || stack_size == 3)
		ft_simple_sort(stack_a, 'a');
	else if (stack_size == 4)
		ft_middle_sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		ft_middle_sort_five(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_errors(argc, argv);
	ft_create_stack(argc, argv, &stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_listclear(&stack_a);
	return (0);
}
