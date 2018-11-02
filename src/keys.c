/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 00:19:55 by feedme            #+#    #+#             */
/*   Updated: 2018/10/31 00:20:00 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/*"


void	angle(t_data *data, int key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.directon.x;
	old_plane_x = data->player.projection_plane.x;
	if (key == KEY_LEFT)
	{
		data->player.direction.x = data->player.direction.x * cos(-ROT_SPEED) - data->player.direction.y * sin(-ROT_SPEED);
		data->player.direction.y = old_dir_x * sin(-ROT_SPEED) + data->player.direction.y * cos(-ROT_SPEED);
		data->player.projection_plane.x = data->player.projection_plane.x * cos(-ROT_SPEED) - data->player.projection_plane.y * sin(-ROT_SPEED);
		data->player.projection_plane.y = old_plane_x * sin(-ROT_SPEED) + data->player.projection_plane.y * cos(-ROT_SPEED);	
	}
	else
	{
		data->player.direction.x = data->player.direction.x * cos(ROT_SPEED) - data->player.direction.y * sin(ROT_SPEED);
		data->player.direction.y = old_dir_x * sin(ROT_SPEED) + data->player.direction.y * cos(ROT_SPEED);
		data->player.projection_plane.x = data->player.projection_plane.x * cos(ROT_SPEED) - data->player.projection_plane.y * sin(ROT_SPEED);
		data->player.projection_plane.y = old_plane_x * sin(ROT_SPEED) + data->player.projection_plane.y * cos(ROT_SPEED);
	}
}

void	change_pos(t_data *data, int key)
{
	if (key == KEY_W || key == KEY_UP)
	{
		if (!data->map.map[(int)data->player.position.x + data->player.direction.x * MOVE_SPEED][(int)data->player.position.y])
		data->player.position.x += data->player.direction.x * MOVE_SPEED;
		if (!data->map.map[(int)data->player.position.x][(int)data->player.position.y + data->player.direction.y * MOVE_SPEED])
		data->player.position.y += data->player.direction.y * MOVE_SPEED;
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		if (!data->map.map[(int)data->player.position.x - data->player.direction.x * MOVE_SPEED][(int)data->player.position.y])
		data->player.position.x -= data->player.direction.x * MOVE_SPEED;
		if (!data->map.map[(int)data->player.position.x][(int)data->player.position.y - data->player.direction.y * MOVE_SPEED])
		data->player.position.y -= data->player.direction.y * MOVE_SPEED;

	}
	else if (key == KEY_A)
	{
		if (!data->map.map[(int)data->player.position.x - data->player.direction.x * MOVE_SPEED][(int)data->player.position.y])
		data->player.position.x -= data->player.direction.x * MOVE_SPEED;
		if (!data->map.map[(int)data->player.position.x][(int)data->player.position.y + data->player.direction.y * MOVE_SPEED])
		data->player.position.y += data->player.direction.y * MOVE_SPEED;
	}
	else
	{
		if (!data->map.map[(int)data->player.position.x + data->player.direction.x * MOVE_SPEED][(int)data->player.position.y])
		data->player.position.x += data->player.direction.x * MOVE_SPEED;
		if (!data->map.map[(int)data->player.position.x][(int)data->player.position.y - data->player.direction.y * MOVE_SPEED])
		data->player.position.y -= data->player.direction.y * MOVE_SPEED;
	}
}

void	crouch(t_data *data)
{

}

int		keyboard(int key, void *param)
{
	t_data *d;

	d = param;
	ft_erase(d);
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	else if (key == KEY_W || (key >= KEY_A && key <= KEY_D) ||
    key == KEY_UP || key == KEY_DOWN)
		change_pos(d, key);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		angle(d, key);
	else if (key == KEY_DEL)
		reset(d);
    else if (key == KEY_CTRL_LEFT)
        d->player.height = 16;
    else if (key == KEY_SPACEBAR)
        jump(d);
	ft_draw(d);
	return (0);
}