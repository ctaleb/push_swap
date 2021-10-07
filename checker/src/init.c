/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:00:49 by ctaleb            #+#    #+#             */
/*   Updated: 2021/10/07 14:33:20 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	stack_init(void)
{
	t_stack	stack;

	stack.list = NULL;
	stack.size = 0;
	return (stack);
}

void	rank_assigner(t_stack *stack, int rank, int lower)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->list->value == lower)
			stack->list->rank = rank;
		stack->list = stack->list->next;
		i++;
	}
}

void	order_check(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a->list;
	while (i < stack_a->size - 1)
	{
		if (tmp->value < tmp->next->value)
		{
			tmp = tmp->next;
			i++;
			if (i == stack_a->size - 1)
			{
				list_clear(stack_a);
				list_clear(stack_b);
				exit(0);
			}
		}
		else
			return ;
	}
}

void	clone_check(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		value;
	t_list	*tmp;

	i = 0;
	while (i < stack_a->size)
	{
		tmp = stack_a->list;
		j = 0;
		while (j < i + 1)
		{
			tmp = tmp->next;
			value = tmp->prev->value;
			j++;
		}
		while (j < stack_a->size)
		{
			if (value == tmp->value)
				error(6, stack_a, stack_b);
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}

void	stack_check(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stack_a->list;
	tmp2 = stack_a->list;
	i = 0;
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (tmp->value > tmp2->value)
				tmp->rank++;
			tmp2 = tmp2->next;
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	if (i == 0)
		exit(7);
	clone_check(stack_a, stack_b);
	order_check(stack_a, stack_b);
}
