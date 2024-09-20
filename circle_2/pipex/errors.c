/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:28:57 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/19 12:03:01 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_argc(void)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd("invalid argc number\n", 2);
}

void	error_strlen(void)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd("invalid filename length\n", 2);
}

void	error_cmd_not_found(char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	error_custom(int err_num, char *str)
{
	if (err_num <= 106)
		perror("pipex: input");
	else
	{
		if (err_num == E_CUSTOM_ARGC)
			error_argc();
		else if (err_num == E_CUSTOM_STRLEN)
			error_strlen();
		else if (err_num == 127)
			error_cmd_not_found(str);
	}
	exit(err_num);
}
