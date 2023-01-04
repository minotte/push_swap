/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:43:34 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/22 19:17:39 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

t_stack	*creat_stack(t_stack *stack, char **tab)
{
	int		i;
	long	elmt;

	i = 0;
	while (tab[i])
	{
		elmt = ft_atoi(tab[i]);
		if (elmt < -2147483648 || elmt > 2147483647)
			ft_error_clear(tab, stack, i);
		if (ft_stackfind(stack, elmt))
			ft_error_clear(tab, stack, i);
		ft_putstack(&stack, elmt);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (stack);
}

void	ft_algorithm(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		size;

	if (!stack_a)
	{
		ft_putendl_fd("Error", 2);
		free (stack_a);
		exit (0);
	}
	stack_b = NULL;
	size = ft_stacksize(stack_a);
	ft_normalize(stack_a, size);
	if (ft_issort_stack(stack_a))
		return ;
	if (size == 2)
		ft_sort_two(stack_a);
	if (size == 3)
		ft_sort_three(&stack_a);
	if (size == 4)
		ft_sort_four(stack_a, stack_b);
	if (size == 5)
		ft_sort_five(stack_a, stack_b);
	if (size > 5)
		ft_sort(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tab;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		check_error(argv[i], stack_a);
		tab = ft_split(&argv[i][0], ' ');
		stack_a = creat_stack(stack_a, tab);
		i++;
	}
	ft_algorithm(stack_a);
	ft_stackclear(&stack_a);
	return (0);
}
