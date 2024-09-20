/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:46:22 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/21 13:54:08 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_content(void *content)
{
	free(content);
}

void	clear_split_values(char **split_values)
{
	int	i;

	i = 0;
	while (split_values[i] != NULL)
	{
		free(split_values[i]);
		i++;
	}
	free(split_values);
}

void	clear_all(t_list **stack_a, t_list **stack_b, char **split_values)
{
	ft_lstclear(stack_a, delete_content);
	ft_lstclear(stack_b, delete_content);
	clear_split_values(split_values);
}
