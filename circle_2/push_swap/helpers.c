/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:22 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/24 14:29:20 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_white_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	lstsorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (*((int *)tmp->content) > *((int *)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	cheapest(int *c_cost, int *l_cost, t_list **pos, t_list **stack_b)
{
	t_list	*tmp_b;
	t_list	*reset_cheapest;

	tmp_b = *pos;
	reset_cheapest = *stack_b;
	if (*c_cost < *l_cost)
	{
		*l_cost = *c_cost;
		while (reset_cheapest != NULL)
		{
			reset_cheapest->move = 0;
			reset_cheapest = reset_cheapest->next;
		}
		tmp_b->move = 1;
	}
}
