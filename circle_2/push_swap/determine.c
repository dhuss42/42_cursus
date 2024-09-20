/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:09:56 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/24 11:32:10 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_greater_than_all(t_list **stack_a, int value_b)
{
	t_list	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a != NULL)
	{
		if (value_b < *(int *)tmp_a->content)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}

t_list	*return_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*lowest;

	tmp = *stack;
	lowest = tmp;
	while (tmp != NULL)
	{
		if (*(int *)tmp->content < (*(int *)lowest->content))
		{
			lowest = tmp;
		}
		tmp = tmp->next;
	}
	return (lowest);
}

void	target_loop(t_list **stack_a, t_list **pos_b)
{
	t_list	*next_highest;
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *pos_b;
	next_highest = NULL;
	while (tmp_a != NULL)
	{
		if (*(int *)tmp_a->content > *(int *)tmp_b->content
			&& (next_highest == NULL || *(int *)tmp_a->content
				< *(int *)next_highest->content))
			next_highest = tmp_a;
		{
			tmp_a = tmp_a->next;
		}
	}
	if (next_highest != NULL)
		tmp_b->target = next_highest;
}

void	targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		i;

	tmp_b = *stack_b;
	i = 1;
	while (tmp_b != NULL)
	{
		if (is_greater_than_all(stack_a, *(int *)tmp_b->content) == 1)
			tmp_b->target = return_min(stack_a);
		else
			target_loop(stack_a, &tmp_b);
		i++;
		tmp_b = tmp_b->next;
	}
}

void	current_pos(t_list **stack_a)
{
	int		position;
	int		top_half;
	t_list	*tmp;

	tmp = *stack_a;
	position = 0;
	top_half = ((ft_lstsize(*stack_a) + 1) / 2);
	while (tmp != NULL)
	{
		tmp->index = position;
		if (position < top_half)
			tmp->above = 1;
		else
			tmp->above = 0;
		position++;
		tmp = tmp->next;
	}
}
