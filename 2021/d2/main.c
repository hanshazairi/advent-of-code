/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:56:43 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/02 13:39:01 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	first(char **argv)
{
	int	i;
	int	x;
	int	y;
	int	len;

	i = 0;
	x = 0;
	y = 0;
	while (argv[i++])
	{
		len = strlen(argv[i]);
		if (!strncmp("forward", argv[i - 1], 7))
			x += atoi(&argv[i][len - 1]);
		else if (!strncmp("down", argv[i - 1], 4))
			y += atoi(&argv[i][len - 1]);
		else if (!strncmp("up", argv[i - 1], 2))
			y -= atoi(&argv[i][len - 1]);
		++i;
	}
	printf("%d\n", x * y);
}

static void	second(char **argv)
{
	int	i;
	int	a;
	int	x;
	int	y;
	int	len;

	i = 0;
	a = 0;
	x = 0;
	y = 0;
	while (argv[i++])
	{
		len = strlen(argv[i]);
		if (!strncmp("forward", argv[i - 1], 7))
		{
			x += atoi(&argv[i][len - 1]);
			y += (a * atoi(&argv[i][len - 1]));
		}
		else if (!strncmp("down", argv[i - 1], 4))
			a += atoi(&argv[i][len - 1]);
		else if (!strncmp("up", argv[i - 1], 2))
			a -= atoi(&argv[i][len - 1]);
		++i;
	}
	printf("%d\n", x * y);
}

/* --- Day 2: Dive! --- */
int	main(int argc, char **argv)
{
	(void)argc;
	first(argv + 1);
	second(argv + 1);
	return (0);
}
