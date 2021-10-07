/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:34:33 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 11:13:22 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_chunk	chunk;

	chunk = chunk_init(stack_a);
	i = 0;
	while (i < 11)
	{
		chunk_size(&chunk, 11, i);
		chunk_set(&chunk);
		while (chunk.top >= 0 && chunk.bot >= 0)
		{
			top_check(stack_a, &chunk);
			bot_check(stack_a, &chunk);
			if (chunk.top >= 0 && chunk.top >= 0)
				push_closest(stack_a, stack_b, &chunk);
		}
		i++;
	}
	push_back(stack_a, stack_b, &chunk);
}
