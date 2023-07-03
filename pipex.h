/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydimitro <ydimitro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:13:40 by ydimitro          #+#    #+#             */
/*   Updated: 2022/08/19 16:28:01 by ydimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_cmd
{
	char	*cmd;
	char	**path;
	char	*arg[100];
	int		f;
}	t_cmd;

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define PATH 5
# define START 6

void	pipex(int f1, int f2, char **ag, char **ep);
void	exec_cmd(t_cmd *cmd1, t_cmd *cmd2, char **envp);
void	error_msg(char *c);
int		check_cmd(t_cmd *c);
int		check_empty(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		ft_putstr(char *s, char *t);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_splitpath(char *s, char c);
int		free_arr(char **path);
void	free_struct(t_cmd *c);

#endif
