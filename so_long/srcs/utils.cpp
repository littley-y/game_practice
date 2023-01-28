/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:10:47 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/28 14:40:54 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.hpp"

void putErrExit(std::string str) {
  std::cerr << "Error\n" << str << std::endl;
  exit(1);
}

void getLocation(int* x, int* y, int lx, int ly) {
  *x = lx;
  *y = ly;
}

bool isElem(char c) {
  if (c == 'E' || c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'X')
    return (1);
  else
    return (0);
}

char* ch(const char* str) {
  return (const_cast<char*>(str));
}