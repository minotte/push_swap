/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:27:37 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/21 13:53:54 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_sortint_index(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if ((tab[i] > tab[i + 1]))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab);
}

static void	ft_replace_b(t_stack *stack, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->content == tab[i])
		{
			stack->content = i;
			i = 0;
			break ;
		}
		i++;
	}
}

static void	ft_replace(t_stack *stack, int *tab, int size)
{
	int	i;

	i = 0;
	while (stack->prev)
	{
		while (i < size)
		{
			if (stack->content == tab[i])
			{
				stack->content = i;
				stack = stack->prev;
				i = 0;
				break ;
			}
			i++;
		}
	}
	ft_replace_b(stack, tab, size);
}

void	ft_normalize(t_stack *stack, int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	i = 0;
	while (i < size)
	{
		tab[i] = stack->content;
		if (stack->next)
			stack = stack->next;
		i++;
	}
	tab = ft_sortint_index(tab, size);
	ft_replace(stack, tab, size);
	free(tab);
}
