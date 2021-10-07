/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:19:22 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 12:20:02 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	swap(stack);
}

void	swap_b(t_stack *stack)
{
	swap(stack);
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		return ;
	else
	{
		swap(stack_a);
		swap(stack_b);
	}
}
