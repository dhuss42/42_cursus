/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:30:13 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/19 12:01:09 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*concatenate_path_cmd(char *path, char *cmd)
{
	char	*slash;
	char	*full_path;

	slash = ft_strjoin(path, "/");
	if (!slash)
		return (NULL);
	full_path = ft_strjoin(slash, cmd);
	free(slash);
	return (full_path);
}

char	**add_slash_cmd(char **split_paths, char *cmd)
{
	int		i;
	char	**append;

	i = 0;
	append = allocate_append_array(split_paths);
	if (!append)
	{
		clear_all(split_paths);
		return (NULL);
	}
	while (split_paths[i] != NULL)
	{
		append[i] = concatenate_path_cmd(split_paths[i], cmd);
		if (!append[i])
		{
			clear_all_double(split_paths, append);
			return (NULL);
		}
		i++;
	}
	append[i] = NULL;
	return (append);
}

char	*check_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		if ((access(cmd[i], F_OK) == 0) && (access(cmd[i], X_OK) == 0))
			return (cmd[i]);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char *envp[])
{
	t_get_path	gp;

	gp.append = NULL;
	if (envp[0] == NULL)
		return (NULL);
	gp.i = find_path(envp);
	if (gp.i == -1)
		return (NULL);
	if (envp[gp.i] == NULL)
		error_custom(E_CUSTOM_ARGC, NULL);
	gp.move = ft_strchr(envp[gp.i], '/');
	gp.split_paths = ft_split(gp.move, ':');
	if (!gp.split_paths)
		return (NULL);
	gp.append = add_slash_cmd(gp.split_paths, cmd);
	if (gp.split_paths)
		clear_all(gp.split_paths);
	gp.path = check_cmd(gp.append);
	if (gp.path == NULL)
	{
		clear_all(gp.append);
		return (cmd);
	}
	return (gp.path);
}
