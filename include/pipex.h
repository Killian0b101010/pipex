/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:42 by kiteixei          #+#    #+#             */
/*   Updated: 2025/07/16 14:36:16 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct t_fd
{
	int	fd_out;
	int	fd_in;
	int	pipefd[2];

}		t_fd;
void	open_files(char *infile, char *outfile, t_fd *fd);
void	first_child(char **av, char **envp, t_fd *fd);
void	second_child(char **av, char **envp, t_fd *fd);
void	execute_cmd(char *cmd, char **envp);
char	**get_path(char **envp);
void	broken_free(char **res);
void	second_exec(char **path, char **cmdargss, char **envp);
void	close2(int fd);

#endif