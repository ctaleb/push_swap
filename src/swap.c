/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:16:13 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/12 15:35:08 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp_val;
	int	tmp_rnk;

	if (stack->size <= 1)
		return (0);
	tmp_val = stack->list->value;
	tmp_rnk = stack->list->rank;
	stack->list->value = stack->list->next->value;
	stack->list->rank = stack->list->next->rank;
	stack->list->next->value = tmp_val;
	stack->list->next->rank = tmp_rnk;
	return (1);
}

void	swap_a(t_stack *stack)
{
	if (swap(stack))
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	if (swap(stack))
		write(1, "sb\n", 3);
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		write(1, "ss\n", 3);
	else
	{
		swap(stack_a);
		swap(stack_b);
	}
}
