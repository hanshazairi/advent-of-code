/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:02:04 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/03 20:52:28 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	count(char **argv, int place, char **str, int bits[])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (argv[i])
	{
		if (!strncmp(*str, argv[i], strlen(*str)) && argv[i][place] == '1')
			++j;
		else if (!strncmp(*str, argv[i], strlen(*str)) && argv[i][place] == '0')
			++k;
		++i;
	}
	if (j + k == 1)
		return (0);
	bits[0] = j;
	bits[1] = k;
	return (1);
}

static char	*get_rating(char **argv, int is_o2)
{
	int			i;
	int			bits[2];
	char		*ret;
	char		*str;
	const int	len = strlen(argv[0]);

	str = strdup(argv[0]);
	bzero(str, strlen(str));
	i = -1;
	while (count(argv, ++i, &str, bits) && i < len)
	{
		if ((is_o2 && bits[0] >= bits[1]) || (!is_o2 && bits[0] < bits[1]))
			strlcat(str, "1", strlen(str) + 2);
		else
			strlcat(str, "0", strlen(str) + 2);
	}
	i = -1;
	while (argv[++i])
		if (!strncmp(str, argv[i], strlen(str)))
			ret = argv[i];
	free(str);
	return (ret);
}

static void	part_1(int argc, char **argv)
{
	int			i;
	int			j;
	int			bit;
	int			ret;
	const int	len = strlen(argv[0]);

	ret = 0;
	i = -1;
	while (++i < len)
	{
		bit = 0;
		j = 0;
		while (argv[j])
		{
			if (argv[j++][i] == '1')
				++bit;
		}
		ret |= bit >= argc / 2;
		ret <<= 1;
	}
	ret >>= 1;
	ret *= ret ^ (int)(pow(2, len) - 1);
	printf("%d\n", ret);
}

static void	part_2(char **argv)
{
	char		*endptr;
	const long	co2_rating = strtol(get_rating(argv, 0), &endptr, 2);
	const long	o2_rating = strtol(get_rating(argv, 1), &endptr, 2);

	printf("%ld\n", o2_rating * co2_rating);
}

/* --- Day 3: Binary Diagnostic --- */
int	main(int argc, char **argv)
{
	part_1(argc - 1, argv + 1);
	part_2(argv + 1);
	return (0);
}
