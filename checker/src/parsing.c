/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:03:49 by ctaleb            #+#    #+#             */
/*   Updated: 2021/10/07 14:34:38 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	symbol_set(char symbol)
{
	if (symbol == '-')
		return (-1);
	else
		return (1);
}

int	get_value(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int		nb;
	char	*nbr;

	nb = ft_atoi(str);
	nbr = ft_itoa(nb);
	if (ft_strncmp(str, nbr, ft_strlen(str)))
	{
		free (nbr);
		error(3, stack_a, stack_b);
		return (-1);
	}
	else
	{
		free (nbr);
		list_addback(stack_a, list_new(nb, stack_a, stack_b));
		return (nb);
	}
}

void	parser(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		get_value(av[i], stack_a, stack_b);
		i++;
	}
}
