/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:46:22 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/19 12:00:51 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_it(int fd, int in_out_fd)
{
	if (close(fd) == -1)
		error_custom(errno, NULL);
	if (close(in_out_fd) == -1)
		error_custom(errno, NULL);
}

void	clear_all(char **to_clear)
{
	int	j;

	j = 0;
	while (to_clear[j] != NULL)
	{
		if (to_clear[j])
			free(to_clear[j]);
		j++;
	}
	if (to_clear)
		free(to_clear);
}

void	clear_all_double(char **first, char **second)
{
	clear_all(first);
	clear_all(second);
}

char	**allocate_append_array(char **split_paths)
{
	int		j;
	char	**append;

	j = 0;
	while (split_paths[j] != NULL)
		j++;
	append = malloc(sizeof(char *) * (j + 1));
	return (append);
}

char	**split_cmd_and_para(char *cmd)
{
	char	**split_it;

	split_it = ft_split(cmd, ' ');
	if (!split_it)
		return (NULL);
	return (split_it);
}
