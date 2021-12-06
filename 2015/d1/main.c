/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:06:19 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/06 22:11:16 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	part_1(char *argv)
{
	int	ret;

	ret = 0;
	while (*argv)
	{
		if (*argv == '(')
			++ret;
		else
			--ret;
		++argv;
	}
	printf("%d\n", ret);
}

static void	part_2(char *argv)
{
	int	i;
	int	floor;

	floor = 0;
	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '(')
			++floor;
		else
			--floor;
		if (floor == -1)
		{
			printf("%d\n", i + 1);
			break ;
		}
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	part_1(argv[1]);
	part_2(argv[1]);
	return (0);
}
