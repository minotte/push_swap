/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:56:03 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/20 11:42:36 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_error(t_stack *stack)
{
	ft_putendl_fd("Error", 2);
	ft_stackclear(&stack);
	exit(0);
}

void	check_error(char *str, t_stack *stack)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 0)
			if ((str[i] == '-' && !(str[i - 1] == ' '))
				|| (str[i] == '+' && !(str[i - 1] == ' ')))
				write_error(stack);
		if ((str[i] == '-' && !(ft_isdigit(str[i +1])))
			|| (str[i] == '+' && !(ft_isdigit(str[i +1]))))
			write_error(stack);
		if (!(ft_isdigit(str[i]) || str[i] == '-'
				|| str[i] == ' ' || str[i] == '+'))
			write_error(stack);
		i++;
	}
	i = 0;
	if (str[i] == '\0')
		write_error(stack);
	while (str[i++] == ' ' && str[i])
	{
		if (str[i] == '\0')
			write_error(stack);
	}
}

void	ft_error_clear(char **tab, t_stack *stack, int i)
{
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	write_error(stack);
}
