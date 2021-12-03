/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:06:49 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/03 21:45:19 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <strings.h>

static void	part_1(char **argv)
{
	int	i;
	int	j;
	int	max;
	int	xy[2];

	i = -1;
	max = 0;
	while (argv[++i])
	{
		j = -1;
		bzero(xy, sizeof(int) * 2);
		while (argv[i][++j] && j < 7)
		{
			xy[1] |= argv[i][j] == 'B';
			xy[1] <<= 1;
		}
		while (argv[i][++j])
		{
			xy[0] |= argv[i][j] == 'R';
			xy[0] <<= 1;
		}
		if ((xy[1] >> 1) * 8 + (xy[0] >> 1) > max)
			max = (xy[1] >> 1) * 8 + (xy[0] >> 1);
	}
	printf("%d\n", max);
}

/* --- Day 5: Binary Boarding --- */
int	main(int argc, char **argv)
{
	(void)argc;
	part_1(argv + 1);
	return (0);
}
