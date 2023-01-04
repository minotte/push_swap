/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:15:28 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/21 12:07:39 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_issort_stack(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_maxbits(int size, int *j)
{
	int	i;

	i = 0;
	(*j) = -1;
	size--;
	while (size >> i)
		i++;
	return (i);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	bits;
	int	i;
	int	j;

	bits = ft_maxbits(size, &j);
	while (++j < bits)
	{
		i = -1;
		while (++i < size)
		{
			if ((stack_a->content >> j) & 1)
				ft_stackrot_a(&stack_a);
			else
			{
				if (ft_issort_stack(stack_a))
					break ;
				stack_b = ft_push_b(&stack_a, &stack_b);
			}
		}
		while (stack_b)
		{
			stack_b = ft_push_a(&stack_a, &stack_b);
			stack_a = ft_stackfirst(stack_a);
		}
	}
}
