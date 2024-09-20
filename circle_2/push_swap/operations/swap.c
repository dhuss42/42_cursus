/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:54:46 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/21 11:25:44 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	int	*top_n;
	int	*second_n;
	int	tmp_n;

	if (ft_lstsize(*head) > 1)
	{
		top_n = (*head)->content;
		second_n = (*head)->next->content;
		tmp_n = *top_n;
		*top_n = *second_n;
		*second_n = tmp_n;
	}
}

void	swap_a(t_list **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
