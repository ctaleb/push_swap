/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 09:47:22 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 13:39:59 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_clear(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->list)
		return ;
	while (stack->size)
	{
		tmp = stack->list->next;
		free(stack->list);
		stack->list = tmp;
		stack->size--;
	}
	stack->list = NULL;
}

t_list	*list_new(int value, t_stack *stack_a, t_stack *stack_b)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	mem_check(list, stack_a, stack_b);
	list->rank = 0;
	list->value = value;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

t_list	*list_last(t_stack *stack)
{
	t_list	*lst;
	int		i;

	lst = stack->list;
	i = 0;
	while (i < stack->size - 1)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}

void	list_addback(t_stack *stack, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!stack->size)
	{
		stack->list = new;
		stack->list->next = stack->list;
		stack->list->prev = stack->list;
		stack->size += 1;
		return ;
	}
	last = stack->list->prev;
	last->next = new;
	new->prev = last;
	new->next = stack->list;
	stack->list->prev = new;
	stack->size += 1;
}

void	list_addfront(t_stack *stack, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!stack->size)
	{
		stack->list = new;
		stack->list->next = stack->list;
		stack->list->prev = stack->list;
		stack->size += 1;
		return ;
	}
	last = stack->list->prev;
	stack->list->prev = new;
	new->next = stack->list;
	stack->list = new;
	last->next = stack->list;
	stack->list->prev = last;
	stack->size += 1;
}
