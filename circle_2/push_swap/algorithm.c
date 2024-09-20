/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:04:10 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/21 15:29:12 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_list **stack_a, t_list **stack_b, t_list *node)
{
	int		i;

	i = 0;
	while (i < ft_lstsize(*stack_b) - node->index)
	{
		reverse_rotate_b(stack_b);
		i++;
	}
	i = 0;
	if (node->target->above == 0)
	{
		while (i < ft_lstsize(*stack_a) - node->target->index)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		while (i < node->target->index)
		{
			rotate_a(stack_a);
			i++;
		}
	}
}

void	algo_rrr(t_list **stack_a, t_list **stack_b, t_list *node)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (i < size_b - node->index && i < size_a - node->target->index)
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while (i < size_b - node->index)
	{
		reverse_rotate_b(stack_b);
		i++;
	}
	while (i < size_a - node->target->index)
	{
		reverse_rotate_a(stack_a);
		i++;
	}
}

void	rotate_up(t_list **stack_a, t_list **stack_b, t_list *node)
{
	int	i;

	i = 0;
	while (i < node->index)
	{
		rotate_b(stack_b);
		i++;
	}
	i = 0;
	if (node->target->above == 0)
	{
		while (i < ft_lstsize(*stack_a) - node->target->index)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		while (i < node->target->index)
		{
			rotate_a(stack_a);
			i++;
		}
	}
}

void	algo_rr(t_list **stack_a, t_list **stack_b, t_list *node)
{
	int	i;

	i = 0;
	while (i < node->index && i < node->target->index)
	{
		rr(stack_a, stack_b);
		i++;
	}
	while (i < node->index)
	{
		rotate_b(stack_b);
		i++;
	}
	while (i < node->target->index)
	{
		rotate_a(stack_a);
		i++;
	}
}
