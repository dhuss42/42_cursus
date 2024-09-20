/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:31:21 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/24 16:07:03 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(char **split_values)
{
	int	count;

	count = 0;
	while (split_values[count] != NULL)
	{
		if (!is_integer(split_values[count])
			|| is_in_range(split_values[count]))
		{
			ft_printf("ERROR\n");
			clear_split_values(split_values);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	if (is_duplicate(split_values, count))
	{
		ft_printf("ERROR\n");
		clear_split_values(split_values);
		exit(EXIT_FAILURE);
	}
}
