/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:18:05 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 12:19:10 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	stack->list = stack->list->next;
	return (1);
}

void	rotate_a(t_stack *stack)
{
	rotate(stack);
}

void	rotate_b(t_stack *stack)
{
	rotate(stack);
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		return ;
	else
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}
