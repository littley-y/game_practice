/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:10:47 by yehyun            #+#    #+#             */
/*   Updated: 2023/02/17 14:16:21 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "astar.h"

void puterror_exit(char* str) {
  ft_putstr_fd("Error\n", 2);
  ft_putendl_fd(str, 2);
  exit(1);
}

int putmsg_exit(char* str, t_var* var) {
  ft_putendl_fd(str, 1);
  mlx_destroy_window(var->mlx, var->win);
  exit(0);
  return (0);
}

int exit_hook(t_var* var) {
  ft_putendl_fd("Bye!", 1);
  mlx_destroy_window(var->mlx, var->win);
  exit(0);
  return (0);
}
