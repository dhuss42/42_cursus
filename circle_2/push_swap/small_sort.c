/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:23:18 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/21 14:34:17 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*tmp;
	int		a;
	int		b;
	int		c;

	tmp = *stack_a;
	a = (*(int *)tmp->content);
	b = (*(int *)tmp->next->content);
	c = (*(int *)tmp->next->next->content);
	if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > c && c > b)
		rotate_a(stack_a);
	else if (b > a && a > c)
		reverse_rotate_a(stack_a);
	else if (b > c && c > a)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (c > a && a > b)
		swap_a(stack_a);
}

void	find_min(t_list **stack_a, int *smallest_index)
{
	int		smallest;
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	smallest = (*(int *)tmp->content);
	*smallest_index = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (*(int *)tmp->content < smallest)
		{
			smallest = (*(int *)tmp->content);
			*smallest_index = i;
		}
		tmp = tmp->next;
		i++;
	}
}

void	move_min_to_top(t_list **stack_a, int smallest_index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	if (smallest_index <= size / 2)
	{
		while (i < smallest_index)
		{
			rotate_a(stack_a);
			i++;
		}
	}
	else
	{
		while (i < size - smallest_index)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
}

void	sort_up_to_five(t_list **stack_a, t_list **stack_b)
{
	int	smallest_index;
	int	count;

	smallest_index = 0;
	count = 0;
	while (ft_lstsize(*stack_a) > 3)
	{
		find_min(stack_a, &smallest_index);
		move_min_to_top(stack_a, smallest_index);
		push_b(stack_a, stack_b);
		count++;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
		push_a(stack_b, stack_a);
}

void	small_sort(int size, t_list **stack_a, t_list **stack_b)
{
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size >= 4 && size <= 5)
		sort_up_to_five(stack_a, stack_b);
}
