/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:49:10 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/28 09:56:36 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_cost(t_list **stack_a, t_list **stack_b, t_cost *cost)
{
	int	i;

	i = 0;
	while ((cost->tmp_b->above == 0 && cost->tmp_b->target->above == 0)
		&& (cost->tmp_b->index + i < ft_lstsize(*stack_b)
			&& cost->tmp_b->target->index + i < ft_lstsize(*stack_a)))
		i++;
	if (cost->tmp_b->index + i < ft_lstsize(*stack_b))
		i += ft_lstsize(*stack_b) - cost->tmp_b->index + i;
	if (cost->tmp_b->target->index + i < ft_lstsize(*stack_a))
		i += ft_lstsize(*stack_a) - cost->tmp_b->target->index + i;
	cost->c_cost = i + 1;
	cheapest(&cost->c_cost, &cost->l_cost, &cost->tmp_b, stack_b);
}

void	below_median(t_list **stack_a, t_list **stack_b, t_cost *cost)
{
	cost->c_cost += (ft_lstsize(*stack_b) - cost->tmp_b->index);
	if (cost->tmp_b->target->above == 0)
	{
		rrr_cost(stack_a, stack_b, cost);
	}
	else
	{
		cost->c_cost += cost->tmp_b->target->index;
		cheapest(&cost->c_cost, &cost->l_cost, &cost->tmp_b, stack_b);
	}
}

void	rr_cost(t_list **stack_b, t_cost *cost)
{
	int	i;

	i = 0;
	while ((cost->tmp_b->above == 1 && cost->tmp_b->target->above == 1)
		&& (cost->tmp_b->index - i > 0 && cost->tmp_b->target->index - i > 0))
		i++;
	if (cost->tmp_b->index - i >= 0)
		i += cost->tmp_b->index - i;
	if (cost->tmp_b->target->index - i >= 0)
		i += cost->tmp_b->target->index - i;
	cost->c_cost = i + 1;
	cheapest(&cost->c_cost, &cost->l_cost, &cost->tmp_b, stack_b);
}

void	above(t_list **stack_a, t_list **stack_b, t_cost *cost)
{
	cost->c_cost += cost->tmp_b->index;
	if (cost->tmp_b->target->above == 0)
	{
		cost->c_cost += ft_lstsize(*stack_a) - cost->tmp_b->target->index;
		cheapest(&cost->c_cost, &cost->l_cost, &cost->tmp_b, stack_b);
	}
	else
	{
		rr_cost(stack_b, cost);
	}
}

void	calculate_price(t_list **stack_a, t_list **stack_b)
{
	t_cost	cost;

	cost.l_cost = INT_MAX;
	cost.tmp_b = *stack_b;
	while (cost.tmp_b != NULL)
	{
		cost.tmp_b->move = 0;
		cost.c_cost = 1;
		if (cost.tmp_b->above == 0)
			below_median(stack_a, stack_b, &cost);
		else
			above(stack_a, stack_b, &cost);
		cost.tmp_b = cost.tmp_b->next;
	}
}
