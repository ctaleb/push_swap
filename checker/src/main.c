/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 11:28:57 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 13:51:59 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_result(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	value;

	if (stack_b->size)
	{
		write(1, "KO\n", 3);
		return ;
	}
	i = 0;
	while (i < stack_a->size)
	{
		if (i == 0)
			value = stack_a->list->value;
		else if (value > stack_a->list->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		else
			value = stack_a->list->value;
		stack_a->list = stack_a->list->next;
		i++;
	}
	write(1, "OK\n", 3);
}

void	do_two(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(line, "sa", 2))
		swap_a(stack_a);
	else if (!ft_strncmp(line, "sb", 2))
		swap_b(stack_b);
	else if (!ft_strncmp(line, "ss", 2))
		swap_ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa", 2))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb", 2))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra", 2))
		rotate_a(stack_a);
	else if (!ft_strncmp(line, "rb", 2))
		rotate_b(stack_b);
	else if (!ft_strncmp(line, "rr", 2))
		rotate_rr(stack_a, stack_b);
	else
		error(9, stack_a, stack_b);
}

void	do_three(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(line, "rra", 3))
		reverse_rotate_a(stack_a);
	else if (!ft_strncmp(line, "rrb", 3))
		reverse_rotate_b(stack_b);
	else if (!ft_strncmp(line, "rrr", 3))
		reverse_rotate_rrr(stack_a, stack_b);
	else
		error(9, stack_a, stack_b);
}

void	get_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(0, 5, &line))
	{
		if (!line)
			return ;
		else if (ft_strlen(line) == 2)
			do_two(line, stack_a, stack_b);
		else if (ft_strlen(line) == 3)
			do_three(line, stack_a, stack_b);
		else
			error(9, stack_a, stack_b);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac <= 1)
		exit(0);
	stack_a = stack_init();
	stack_b = stack_init();
	parser(ac, av, &stack_a, &stack_b);
	stack_check(&stack_a, &stack_b);
	get_input(&stack_a, &stack_b);
	check_result(&stack_a, &stack_b);
	list_clear(&stack_a);
	list_clear(&stack_b);
	return (0);
}
