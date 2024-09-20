/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:27:53 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/24 14:30:59 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_in_a(t_list **stack_a, int *j)
{
	int		i;
	int		pos;
	t_list	*tmp_a;

	tmp_a = *stack_a;
	i = 0;
	pos = *j;
	while (pos > i)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	return (tmp_a);
}

void	final_rotate(t_list **stack_a)
{
	int		pos;
	t_list	*tmp_a;

	pos = 0;
	tmp_a = *stack_a;
	find_min(stack_a, &pos);
	tmp_a = find_in_a(stack_a, &pos);
	if (tmp_a->above == 0)
	{
		while (0 < (ft_lstsize(*stack_a) - pos))
		{
			reverse_rotate_a(stack_a);
			pos++;
		}
	}
	else
	{
		while (0 < pos)
		{
			rotate_a(stack_a);
			pos--;
		}
	}
}

void	execute(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b != NULL)
	{
		if (tmp_b->move == 1)
			break ;
		tmp_b = tmp_b->next;
	}
	if (tmp_b->above == 0)
	{
		if (tmp_b->target->above == 0)
			algo_rrr(stack_a, stack_b, tmp_b);
		else
			rotate_down(stack_a, stack_b, tmp_b);
	}
	else
	{
		if (tmp_b->target->above == 1)
			algo_rr(stack_a, stack_b, tmp_b);
		else
			rotate_up(stack_a, stack_b, tmp_b);
	}
	push_a(stack_b, stack_a);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while ((ft_lstsize(*stack_a) != 3))
		push_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		current_pos(stack_b);
		current_pos(stack_a);
		targets(stack_a, stack_b);
		calculate_price(stack_a, stack_b);
		execute(stack_a, stack_b);
		i++;
	}
	if (lstsorted(stack_a) == 0)
		final_rotate(stack_a);
}
