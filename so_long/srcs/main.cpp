/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:21:11 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/27 17:26:46 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.hpp"

void check_file(int ac, const std::string& mapName, std::ifstream& ifs) {
  if (ac == 1)
    putErrExit("No map!");
  if (ac > 2)
    putErrExit("Too many arguments!");
  ifs.open(mapName);
  if (ifs.fail())
    putErrExit("Wrong files!");
  if (mapName.find(".ber") != mapName.size() - 4)
    putErrExit("Wrong extension!");
}

int main(int ac, char** av) {
  Map map;
  Param param;
  std::ifstream ifs;

  check_file(ac, std::string(av[1]), ifs);
  map.setMap(ifs);
  mlx_game(&map);
  return (0);
}
