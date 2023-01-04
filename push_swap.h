/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:17:45 by nminotte          #+#    #+#             */
/*   Updated: 2022/12/20 19:39:48 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	ft_error_clear(char **tab, t_stack *stack, int i);
void	check_error(char *str, t_stack *stack);
void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void	ft_normalize(t_stack *stack, int size);
void	ft_sort(t_stack *stack_a, t_stack *stack_b, int size);
int		ft_issort_stack(t_stack *stack);
int		main(int argc, char **argv);

#endif
