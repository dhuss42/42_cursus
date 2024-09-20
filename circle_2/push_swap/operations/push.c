/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:03:33 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/21 11:25:43 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a != NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		if (*stack_b == NULL)
			*stack_b = tmp;
		else
		{
			tmp->next = *stack_b;
			*stack_b = tmp;
		}
	}
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
