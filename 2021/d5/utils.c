/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:17:48 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/06 01:13:46 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	max(int argc, t_xy *xy)
{
	int	i;
	int	ret;

	ret = -1;
	i = -1;
	while (++i < argc)
	{
		if (xy[i].x > ret)
			ret = xy[i].x;
		if (xy[i].y > ret)
			ret = xy[i].y;
	}
	return (ret);
}

void	get_udlr(t_xy xy_1, t_xy xy_2, int udlr[4])
{
	udlr[0] = xy_2.y;
	udlr[1] = xy_1.y;
	udlr[2] = xy_1.x;
	udlr[3] = xy_2.x;
	if (xy_1.y > xy_2.y)
	{
		udlr[0] = xy_1.y;
		udlr[1] = xy_2.y;
	}
	if (xy_1.x > xy_2.x)
	{
		udlr[2] = xy_2.x;
		udlr[3] = xy_1.x;
	}
}

int	get_points(int *vents, int len)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < len * len)
		if (vents[i] > 1)
			++ret;
	return (ret);
}
