/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:38:24 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/03 20:51:34 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	reset(int fields[])
{
	int	i;

	i = 0;
	while (i < 8)
		fields[i++] = 0;
}

static void	check(char *key, int fields[])
{
	if (!strncmp("byr", key, 3))
		fields[0] = 1;
	else if (!strncmp("iyr", key, 3))
		fields[1] = 1;
	else if (!strncmp("eyr", key, 3))
		fields[2] = 1;
	else if (!strncmp("hgt", key, 3))
		fields[3] = 1;
	else if (!strncmp("hcl", key, 3))
		fields[4] = 1;
	else if (!strncmp("ecl", key, 3))
		fields[5] = 1;
	else if (!strncmp("pid", key, 3))
		fields[6] = 1;
	else if (!strncmp("cid", key, 3))
		fields[7] = 1;
}

static void	validate(int *ret, int fields[])
{
	if (fields[0] * fields[1] * fields[2] * fields[3] * fields[4] * fields[5] \
			* fields[6] == 1)
		*ret += 1;
	reset(fields);
}

static void	part_1(FILE *file, int fields[])
{
	int		ret;
	char	*key;
	char	*tmp;
	char	*line;
	size_t	linecap;

	ret = 0;
	line = 0;
	while (getline(&line, &linecap, file) != -1)
	{
		tmp = line;
		if (strlen(line) == 1)
			validate(&ret, fields);
		key = strsep(&tmp, " ");
		while (key)
		{
			check(key, fields);
			key = strsep(&tmp, " ");
		}
	}
	free(line);
	validate(&ret, fields);
	printf("%d\n", ret);
}

/* --- Day 4: Passport Processing --- */
int	main(int argc, char **argv)
{
	int		fields[8];
	FILE	*file;

	(void)argc;
	file = fopen(argv[1], "r");
	if (!file)
		return (1);
	reset(fields);
	part_1(file, fields);
	fclose(file);
	return (0);
}
