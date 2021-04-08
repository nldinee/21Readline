/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:09:16 by nabdelba          #+#    #+#             */
/*   Updated: 2021/04/08 11:27:21 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_readline.h"

void		clean_posx_str(char *buff)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	j = 0;
	str = ft_strdup(buff);
	while (!ft_isdigit(str[i]) && str[i])
		i++;
	while (ft_isdigit(str[i]) && str[i])
		buff[j++] = str[i++];
	buff[j] = '\0';
	g_pos.y = ft_atoi(buff);
	j = 0;
	ft_strclr(buff);
	while (!ft_isdigit(str[i]) && str[i])
		i++;
	while (ft_isdigit(str[i]) && str[i])
		buff[j++] = str[i++];
	g_pos.x = ft_atoi(buff);
	ft_strdel(&str);
}

void		get_cur_position(void)
{
	char	buff[21];

	buff[20] = 0;
	while (!ft_isdigit(buff[2]))
	{
		write(0, "\e[6n", 4);
		read(0, buff, 20);
	}
	ft_putendl(&buff[1]);
	clean_posx_str(buff);
}
