/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:28:29 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/05/24 15:28:34 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  main(void)
{
  int fd2;
  char *str;
  //fd2 = open("fichero",O_RDONLY);
  //fd2 = open("fichero_vacio",O_RDONLY);
  //fd2 = open("fichero_caracteres",O_RDONLY);
  //fd2 = open("fichero_saltos",O_RDONLY);
  fd2 = open("fichero_contenido",O_RDONLY);
  str = get_next_line(fd2);
  while (str != NULL)
  {
    printf("%s",str);
    if (str != NULL)
    {
      free(str);
      str = get_next_line(fd2);
    }
  }
  free(str);
  close(fd2);
  // system("leaks -q a.out\n");
}
