/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:05:42 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/19 12:28:21 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_one(int fd[2], char *argv[], char *envp[])
{
	char	*path;
	char	**cmd;
	int		infile_fd;

	if (access(argv[1], F_OK) != 0)
		error_custom(errno, argv[1]);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		error_custom(errno, NULL);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_custom(errno, NULL);
	if (close(fd[0]) == -1)
		error_custom(errno, NULL);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_custom(errno, NULL);
	close_it(fd[1], infile_fd);
	cmd = split_cmd_and_para(argv[2]);
	path = get_path(cmd[0], envp);
	if (path == NULL)
		path = cmd[0];
	if (execve(path, cmd, envp))
	{
		clear_all(cmd);
		error_custom(127, argv[2]);
	}
}

void	command_two(int fd[2], char *argv[], char *envp[])
{
	char	*path;
	char	**cmd;
	int		outfile_fd;

	check_outfile(5, argv);
	outfile_fd = open(argv[4], O_WRONLY);
	if (outfile_fd == -1)
		error_custom(errno, NULL);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		error_custom(errno, NULL);
	if (close(fd[1]) == -1)
		error_custom(errno, NULL);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_custom(errno, NULL);
	close_it(fd[0], outfile_fd);
	cmd = split_cmd_and_para(argv[3]);
	path = get_path(cmd[0], envp);
	if (path == NULL)
		path = cmd[0];
	if (execve(path, cmd, envp) == -1)
	{
		clear_all(cmd);
		error_custom(127, argv[3]);
	}
}

int	finish_it(pid_t pid1, pid_t pid2)
{
	t_process	exit;
	int			status1;
	int			status2;

	exit.exit_code = 0;
	exit.w1 = waitpid(pid1, &status1, 0);
	if (exit.w1 == pid1)
	{
		if (WIFEXITED(status1))
			exit.exit_code = WEXITSTATUS(status1);
	}
	exit.w2 = waitpid(pid2, &status2, 0);
	if (exit.w2 == pid2)
	{
		if (WIFEXITED(status2))
			exit.exit_code = WEXITSTATUS(status2);
	}
	return (exit.exit_code);
}

int	fork_it(int fd[2], char *argv[], char *envp[])
{
	t_process	process;

	process.pid1 = fork();
	if (process.pid1 < 0)
		error_custom(errno, NULL);
	else if (process.pid1 == 0)
		command_one(fd, argv, envp);
	else
	{
		process.pid2 = fork();
		if (process.pid2 == -1)
			error_custom(errno, NULL);
		else if (process.pid2 == 0)
			command_two(fd, argv, envp);
		else
		{
			if (close(fd[0]) == -1)
				error_custom(errno, NULL);
			if (close(fd[1]) == -1)
				error_custom(errno, NULL);
			return (finish_it(process.pid1, process.pid2));
		}
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	exit_code;

	exit_code = 0;
	if (argc != 5)
		error_custom(E_CUSTOM_ARGC, NULL);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_custom(errno, NULL);
		exit_code = fork_it(fd, argv, envp);
	}
	return (exit_code);
}
