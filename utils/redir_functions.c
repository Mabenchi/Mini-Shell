/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:49:20 by mabenchi          #+#    #+#             */
/*   Updated: 2022/06/29 15:29:32 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"
#include "../includes/libft.h"

void	redir_in_quote(char *line)
{
	int	i;
	int	opened;

	i = 0;
	opened = 0;
	while (line[i])
	{
		if (!opened && (line[i] == '"' || line[i] == '\''))
			opened = line[i];
		else if (opened && line[i] == opened)
			opened = 0;
		if (opened && (line[i] == '<' || line[i] == '>'))
			line[i] = -2;
		i++;
	}
}

int	two_redir(char **err, int *herdoc, int i, char cond)
{
	if (i == '<')
		*err = "syntax error near unexpected token `<'\n";
	else if (i == '>')
		*err = "syntax error near unexpected token `>'\n";
	if (cond == '<')
		*err = "syntax error near unexpected token `<<'\n";
	else if (cond == '>')
		*err = "syntax error near unexpected token `>>'\n";
	if (cond)
		*herdoc = i;
	g_util->status = 258;
	return (0);
}

void	re_init(int *nb, int *herdoc, int *space)
{
	*nb = 0;
	*herdoc = 0;
	*space = 0;
}

int	is_redir(int c, int nb, char var)
{
	if (var)
	{
		if (nb > 2 || (nb && var != ' '
				&& !is_redir(var, 0, 0) && !ft_isalnum(var)))
			return (1);
		else
			return (0);
	}
	else
	{
		if (c == '>' || c == '<')
			return (1);
		return (0);
	}
}

int	redir_while_loop(char *var, char **err, int *herdoc, int space)
{
	int		i;
	int		nb;
	char	last;

	i = -1;
	nb = 0;
	while (var[++i])
	{
		if (var[i] == '<' || var[i] == '>')
		{
			nb++;
			if (!*herdoc)
				*herdoc = i;
			if (space || !var[i + 1])
				return (two_redir(err, herdoc, space, 0));
			last = var[i];
		}
		if (is_redir(0, nb, var[i]))
			return (two_redir(err, herdoc, i, var[i]));
		if (ft_isalnum(var[i]))
			re_init(&nb, herdoc, &space);
		else if (!space && nb && var[i] == ' ')
			space = var[i - 1];
	}
	return (1);
}
