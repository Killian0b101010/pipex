/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:37:45 by kiteixei          #+#    #+#             */
/*   Updated: 2025/07/16 14:35:58 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/libft.h"

char	**get_path(char **envp)
{
	ssize_t	i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			if (!path)
				return (NULL);
			return (path);
		}
		i++;
	}
	i = 0;
	return (NULL);
}

void	broken_free(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	while (res[i])
		free(res[i++]);
	free(res);
}

void	second_exec(char **path, char **cmdargss, char **envp)
{
	char	*temp;
	char	*cmd_path;
	int		i;
	int		flag;

	flag = 0;
	if (flag == 0)
	{
		i = 0;
		while (path[i])
		{
			temp = ft_strjoin(path[i], "/");
			cmd_path = ft_strjoin(temp, cmdargss[0]);
			free(temp);
			if (access(cmd_path, X_OK) == 0)
				execve(cmd_path, cmdargss, envp);
			free(cmd_path);
			i++;
		}
		write(2, "command not found : ", 20);
		write(2, cmdargss[0], ft_strlen(cmdargss[0]));
		write(2, "\n", 1);
		free((broken_free(path), broken_free(cmdargss), NULL));
		free((flag = 1, exit(127), NULL));
	}
}
