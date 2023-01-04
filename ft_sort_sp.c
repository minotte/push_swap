/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:58 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/20 13:23:34 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack *stack)
{
	if (stack->content > stack->next->content)
		ft_stackswap_a(stack);
}

static void	ft_sort_three_b(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	if (stack->content > stack->next->next->content)
		ft_stackrrot_a(stack_a);
	else if (stack->content < stack->next->next->content)
	{
		ft_stackswap_a(stack);
		ft_stackrot_a(stack_a);
	}
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	if (stack->content > stack->next->content
		&& stack->next->content > stack->next->next->content)
	{
		ft_stackswap_a(stack);
		ft_stackrrot_a(stack_a);
	}
	else if (stack->content > stack->next->content
		&& stack->next->content < stack->next->next->content)
	{
		if (stack->content < stack->next->next->content)
			ft_stackswap_a(stack);
		else if (stack->content > stack->next->next->content)
			ft_stackrot_a(&stack);
	}
	else if (stack->content < stack->next->content
		&& stack->next->content > stack->next->next->content)
	{
		ft_sort_three_b(&stack);
	}
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	a = 1;
	while (!(stack_a->content <= a))
		ft_stackrot_a(&stack_a);
	stack_b = ft_push_b(&stack_a, &stack_b);
	while (!(stack_a->content <= a))
		ft_stackrot_a(&stack_a);
	stack_b = ft_push_b(&stack_a, &stack_b);
	if (stack_a->content > stack_a->next->content
		&& stack_b->content < stack_b->next->content)
		ft_stackswap_ss(stack_a, stack_b);
	else if (stack_b->content < stack_b->next->content)
		ft_stackswap_b(stack_b);
	ft_sort_three(&stack_a);
	stack_b = ft_push_a(&stack_a, &stack_b);
	stack_a = ft_stackfirst(stack_a);
	stack_b = ft_push_a(&stack_a, &stack_b);
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	a = 0;
	while (!(stack_a->content <= a))
		ft_stackrot_a(&stack_a);
	stack_b = ft_push_b(&stack_a, &stack_b);
	ft_sort_three(&stack_a);
	stack_b = ft_push_a(&stack_a, &stack_b);
}
