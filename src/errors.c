/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:47:17 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/12 18:55:07 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_maxint(long int n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

int	ft_check_number(const char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' && !ft_isdigit(str[1]))
		return (0);
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_errors(int argc, char **argv)
{
	int			i;
	int			j;
	long int	number;

	i = 1;
	if (argc < 2)
		exit(1);
	while (i < argc)
	{
		if (!ft_check_number(argv[i]))
			put_error_and_exit();
		number = ft_atoi(argv[i]);
		check_maxint(number);
		j = 1;
		while (j < argc)
		{
			if (j != i && ft_atoi(argv[j]) == number)
				put_error_and_exit();
			j++;
		}
		i++;
	}
}

int	check_elements(t_list *stack_a, int key)
{
	while (stack_a)
	{
		if (*(int *)stack_a->content < key)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
