/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:28:59 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/02 17:05:38 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	first(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (atoi(argv[i]) + atoi(argv[j]) == 2020)
			{
				printf("%d\n", atoi(argv[i]) * atoi(argv[j]));
				return ;
			}
			++j;
		}
		++i;
	}
}

static void	second(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[i + 2])
	{
		j = i + 1;
		while (argv[j + 1])
		{
			k = j + 1;
			while (argv[k])
			{
				if (atoi(argv[i]) + atoi(argv[j]) + atoi(argv[k]) == 2020)
				{
					printf("%d\n", atoi(argv[i]) * atoi(argv[j]) * \
							atoi(argv[k]));
					return ;
				}
				++k;
			}
			++j;
		}
		++i;
	}
}

/* --- Day 1: Report Repair --- */
int	main(int argc, char **argv)
{
	(void)argc;
	first(argv + 1);
	second(argv + 1);
	return (0);
}
