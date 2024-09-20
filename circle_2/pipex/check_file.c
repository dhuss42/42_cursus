/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:52:40 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/19 12:00:29 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_file(int fd, char *filename)
{
	if (ft_strlen(filename) == 0)
		error_custom(E_CUSTOM_STRLEN, NULL);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_custom(errno, NULL);
	if (close(fd) == -1)
		error_custom(errno, NULL);
}

void	check_outfile(int argc, char *argv[])
{
	char	*filename;
	int		fd;

	fd = 0;
	filename = argv[argc -1];
	if (access(filename, F_OK) == -1)
		create_file(fd, filename);
	else
	{
		if (access(argv[argc -1], W_OK) != 0)
			error_custom(errno, NULL);
		else
		{
			fd = open(filename, O_WRONLY | O_TRUNC, 0644);
			if (fd == -1)
				error_custom(errno, NULL);
			if (close(fd) == -1)
				error_custom(errno, NULL);
		}
	}
}
