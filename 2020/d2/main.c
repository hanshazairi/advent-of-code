/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:04:54 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/02 18:53:01 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	first(char **argv)
{
	int	i;
	int	j;
	int	range[2];
	int	ret;
	int	tmp;

	i = 0;
	ret = 0;
	while (argv[i + 3])
	{
		j = 0;
		tmp = 0;
		range[0] = atoi(argv[i]);
		range[1] = atoi(strchr(argv[i], '-') + 1);
		while (argv[i + 2][j])
			if (argv[i + 2][j++] == *argv[i + 1])
				++tmp;
		if (tmp >= range[0] && tmp <= range[1])
			++ret;
		i += 3;
	}
	printf("%d\n", ret);
}

static void	second(char **argv)
{
	int	i;
	int	range[2];
	int	ret;

	i = 0;
	ret = 0;
	while (argv[i])
	{
		range[0] = atoi(argv[i]);
		range[1] = atoi(strchr(argv[i], '-') + 1);
		if ((argv[i + 2][range[0] - 1] == *argv[i + 1]) \
				^ (argv[i + 2][range[1] - 1] == *argv[i + 1]))
			++ret;
		i += 3;
	}
	printf("%d\n", ret);
}

/* --- Day 2: Password Philosophy --- */
int	main(int argc, char **argv)
{
	(void)argc;
	first(argv + 1);
	second(argv + 1);
	return (0);
}
