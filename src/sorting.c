#include "push_swap.h"

int	ft_chunks(int length)
{
	int	nb;

	nb = 0;
	if (length > 5 && length <= 100)
		nb = 5;
	else if (length >= 100 && length <= 500)
		nb = 11;
	return (nb);
}

int	is_sorted(int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (!(tab[i] <= tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	*sortarr(int *tab, int length)
{
	int	i;
	int	temp;

	while (!(is_sorted(tab, length)))
	{
		i = 0;
		while (i < length - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
	}
	return (tab);
}

int	*extract_keys(int *tab, int length)
{
	int	i;
	int	chunk_nb;
	int	*keys;

	i = 0;
	chunk_nb = ft_chunks(length);
	if (chunk_nb == 0)
		return (0);
	keys = ft_calloc(sizeof(int), chunk_nb);
	if (!keys)
		return (0);
	while (i < chunk_nb)
	{
		if (chunk_nb == 1)
			keys[i] = tab[length / 2];
		else
			keys[i] = tab[i * (length / chunk_nb)];
		i++;
	}
	free(tab);
	return (keys);
}

int	*ft_lsttotab_getkeys(t_list *stack_a)
{
	int	i;
	int	length;
	int	*tab;

	i = 0;
	length = ft_lstsize(stack_a);
	tab = ft_calloc(sizeof(int), length);
	if (!tab)
		return (0);
	while (i < length)
	{
		tab[i] = *(int *)stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	tab = sortarr(tab, length);
	tab = extract_keys(tab, length);
	return (tab);
}
