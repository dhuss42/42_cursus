/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:54:26 by dhuss             #+#    #+#             */
/*   Updated: 2024/09/18 10:12:06 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_array(char **to_free)
{
	size_t	y;

	y = 0;
	while (to_free[y] != NULL)
	{
		free(to_free[y]);
		y++;
	}
	free(to_free);
}

void	free_double_exit(char **to_free)
{
	size_t	y;

	y = 0;
	while (to_free[y] != NULL)
	{
		free(to_free[y]);
		y++;
	}
	free(to_free);
	exit(EXIT_FAILURE);
}
