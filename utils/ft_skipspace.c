/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenchi <mabenchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:36:47 by zboudair          #+#    #+#             */
/*   Updated: 2022/06/06 13:53:22 by mabenchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	skipspace(int *n, char *s)
{
	int	i;

	i = *n;
	while (s[i] && s[i] == ' ')
		i++;
	*n = i;
}
