/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:50 by kiteixei          #+#    #+#             */
/*   Updated: 2025/07/16 14:39:23 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_files(char *infile, char *outfile, t_fd *fd)
{
	fd->fd_in = open(infile, O_RDONLY);
	if (fd->fd_in == -1)
		perror(infile);
	fd->fd_out = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd->fd_out == -1)
		perror(outfile);
}

void	first_child(char **av, char **envp, t_fd *fd)
{
	if (fd->fd_in != -1)
	{
		if (fork() == 0)
		{
			dup2(fd->fd_in, 0);
			dup2(fd->pipefd[1], 1);
			close2(fd->fd_in);
			close2(fd->fd_out);
			close2(fd->pipefd[0]);
			close2(fd->pipefd[1]);
			execute_cmd(av[2], envp);
			exit(1);
		}
		else
		{
			close2(fd->fd_in);
			close2(fd->pipefd[1]);
		}
	}
}

void	second_child(char **av, char **envp, t_fd *fd)
{
	if (fork() == 0)
	{
		if (fd->fd_out == -1)
		{
			close2(fd->fd_out);
			close2(fd->fd_in);
			close2(fd->pipefd[0]);
			close2(fd->pipefd[1]);
			exit(1);
		}
		else
		{
			dup2(fd->pipefd[0], 0);
			dup2(fd->fd_out, 1);
			close2(fd->pipefd[0]);
			close2(fd->fd_out);
			close2(fd->fd_in);
			close2(fd->pipefd[1]);
			execute_cmd(av[3], envp);
		}
	}
}

int	is_abs_path(char *cmd)
{
	return ((ft_strncmp(&cmd[0], "/", 1)) == 0);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmdargs;
	char	**paths;

	cmdargs = ft_split(cmd, ' ');
	if (!cmdargs || !cmdargs[0])
	{
		free(cmdargs);
		exit((perror("Error"), 126));
	}
	if (is_abs_path(cmdargs[0]))
	{
		if (access(cmdargs[0], X_OK) == 0)
			execve(cmdargs[0], cmdargs, envp);
	}
	paths = get_path(envp);
	if (!paths)
		exit((write(2, "Error\n", 6), 1));
	second_exec(paths, cmdargs, envp);
}
