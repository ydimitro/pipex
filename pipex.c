/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:34:47 by ydimitro          #+#    #+#             */
/*   Updated: 2022/08/19 16:16:13 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_cmd(t_cmd *c, int f)
{
	c->f = f;
	c->path = 0;
	c->cmd = 0;
	c->arg[0] = 0;
}

static void	free_all(t_cmd *c, t_cmd *d)
{
	free_struct(c);
	free_struct(d);
}

static char	**get_path(char **ep)
{
	char	**ret;
	char	*env;
	int		i;

	i = -1;
	while (ep[++i])
	{
		if (!ft_strncmp(ep[i], "PATH=", PATH))
		{
			env = ft_substr(ep[i], START, ft_strlen(ep[i]));
			if (!env)
				return (NULL);
			ret = ft_splitpath(env, ':');
			if (!ret)
			{
				free(env);
				return (NULL);
			}
			free (env);
			return (ret);
		}
	}
	return (NULL);
}

static int	get_cmd(char **ep, t_cmd *c, char *cmd)
{
	int		i;
	char	**tmp;

	i = -1;
	c->path = get_path(ep);
	if (!c->path)
		return (0);
	tmp = ft_splitpath(cmd, ' ');
	if (!tmp)
		return (0);
	c->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1]) - 1);
	if (!c->cmd)
		return (free_arr(tmp));
	while (tmp[++i])
	{
		c->arg[i] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]) - 1);
		if (!c->arg[i])
		{
			free_arr(c->arg);
			return (free_arr(tmp));
		}
	}
	c->arg[i] = 0;
	free_arr(tmp);
	return (1);
}

void	pipex(int fdin, int fdout, char **ag, char **envp)
{
	t_cmd	cmd1;
	t_cmd	cmd2;

	init_cmd(&cmd1, fdin);
	init_cmd(&cmd2, fdout);
	if (!get_cmd(envp, &cmd1, ag[2]) || !get_cmd(envp, &cmd2, ag[3]))
		return (free_all(&cmd1, &cmd2));
	if (!check_cmd(&cmd1) || !check_cmd(&cmd2))
		return (free_all(&cmd1, &cmd2));
	exec_cmd(&cmd1, &cmd2, envp);
	free_struct(&cmd1);
	free_struct(&cmd2);
}
