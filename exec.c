/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:16:23 by ydimitro          #+#    #+#             */
/*   Updated: 2022/08/19 16:30:18 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **ag, char **envp)
{
	int	fdin;
	int	fdout;

	if (ac != 5)
		return (ft_putstr("The number of arguments is not 5.", 0));
	if (check_empty(ag[2]) || check_empty(ag[3]))
		return (1);
	fdin = open(ag[1], O_RDONLY);
	fdout = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fdin < 0)
		return (ft_putstr(strerror(errno), ag[1]));
	if (fdout < 0)
		return (ft_putstr(strerror(errno), ag[4]));
	pipex(fdin, fdout, ag, envp);
	if (close(fdin) < 0 || close(fdout) < 0)
		return (ft_putstr(strerror(errno), 0));
	return (0);
}
