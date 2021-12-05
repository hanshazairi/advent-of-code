/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:40:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/06 01:13:35 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

/* utils.c */
int		max(int argc, t_xy *xy);
void	get_udlr(t_xy xy_1, t_xy xy_2, int udlr[4]);
int		get_points(int *vents, int len);

#endif
