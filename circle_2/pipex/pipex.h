/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:04:40 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/19 12:02:43 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"
#include "ft_printf.h"
#include <errno.h>

#define E_CUSTOM_ARGC	110
#define E_CUSTOM_STRLEN	111

typedef struct s_process
{
	int		exit_code;
	int		w1;
	int		w2;
	pid_t	pid1;
	pid_t	pid2;

}	t_process;

typedef struct s_get_path
{
	int		i;
	char	**split_paths;
	char	**append;
	char	*move;
	char	*path;
}	t_get_path;

//---<>---pipex---<>---//
int		main(int argc, char *argv[], char *envp[]);
int		fork_it(int fd[2], char *argv[], char *envp[]);
int		finish_it(pid_t pid1, pid_t pid2);
void	command_two(int fd[2], char *argv[], char *envp[]);
void	command_one(int fd[2], char *argv[], char *envp[]);

//---<>---get_path---<>---//
char	*get_path(char *cmd, char *envp[]);
char	*check_cmd(char **cmd);
char	**add_slash_cmd(char **split_paths, char *cmd);
char	*concatenate_path_cmd(char *path, char *cmd);
int		find_path(char *envp[]);

//--<>---check_file---<>---//
void	check_outfile(int argc, char *argv[]);
void	create_file(int fd, char *filename);

//--<>---error---<>---//
void	error_custom( int err_num, char *str);
void	error_argc(void);
void	error_cmd_not_found(char *str);
void	error_strlen(void);

//---<>---helper_and_free---<>---//
void	clear_all(char **to_clear);
void	clear_all_double(char **first, char **second);
void	close_it(int fd, int in_out_fd);
char	**split_cmd_and_para(char *cmd);
char	**allocate_append_array(char **split_paths);
