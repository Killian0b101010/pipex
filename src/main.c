/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:54 by kiteixei          #+#    #+#             */
/*   Updated: 2025/07/15 15:42:57 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close2(int fd)
{
	if (fd > 2)
		close(fd);
}

int	main(int ac, char **av, char **envp)
{
	t_fd	fd;

	if (ac != 5)
		exit((write(2, "Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 44),
				1));
	pipe(fd.pipefd);
	open_files(av[1], av[4], &fd);
	first_child(av, envp, &fd);
	second_child(av, envp, &fd);
	close2(fd.pipefd[0]);
	close2(fd.pipefd[1]);
	close2(fd.fd_in);
	close2(fd.fd_out);
	wait(NULL);
	wait(NULL);
}
