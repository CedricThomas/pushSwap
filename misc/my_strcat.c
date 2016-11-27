/*
** my_strcat.c for strcat in /home/cedric/delivery/CPE/proj_pushswap/CPE_2016_Pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 25 15:19:24 2016 Cédric Thomas
** Last update Sat Nov 26 15:35:18 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "pushswap.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

char	*my_strdup(char *str)
{
  char		*dup;
  int		size;
  int		i;

  size = my_strlen(str);
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      dup[i] = str[i];
      i += 1;
    }
  dup[i] = 0;
  return (dup);
}
