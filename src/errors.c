/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:40:29 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 13:39:04 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int id, t_stack *stack_a, t_stack *stack_b)
{
	write(1, "Error\n", 6);
	list_clear(stack_a);
	list_clear(stack_b);
	exit(id);
}

void	mem_check(void *ptr, t_stack *stack_a, t_stack *stack_b)
{
	if (!ptr)
		error(2, stack_a, stack_b);
}
