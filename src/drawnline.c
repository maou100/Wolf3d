/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawnline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:36:12 by feedme            #+#    #+#             */
/*   Updated: 2018/10/30 18:49:13 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/*"

typedef struct		s_bresenham
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				e;
	int				e2;
	int				range;
}					t_bresen;

void	ft_vars(t_point a, t_point b, t_bresen *var)
{
	var->dx = abs(b.x - a.x);
	var->sx = a.x < b.x ? 1 : -1;
	var->dy = abs(b.y - a.y);
	var->sy = a.y < b.y ? 1 : -1;
	var->e = (var->dx > var->dy ? var->dx : -var->dy) / 2;
	var->e2 = var->e;
	if (var->dy != 0)
		var->range = 200 / var->dy;
}

void	ft_putline(t_data *d, t_point a, t_point b, int color)
{
	t_bresen	var;

	ft_vars(a, b, &var);
	while (42)
	{
		if (a.x == b.x && a.y == b.y)
			break ;
		var.e2 = var.e;
		if (var.e2 > -var.dx)
		{
			var.e -= var.dy;
			a.x += var.sx;
		}
		if (var.e2 < var.dy)
		{
			var.e += var.dx;
			a.y += var.sy;
		}
	}
}
