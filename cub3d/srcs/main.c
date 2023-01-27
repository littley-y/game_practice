/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:16:28 by yehyun            #+#    #+#             */
/*   Updated: 2022/10/05 14:10:52 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		return (puterr_msg("arguments error!") + 2);
	ft_memset(&info, 0, sizeof(t_info));
	parsing_map(&info, av[1]);
	into_game(&info);
	free_info(&info);
	return (0);
}
