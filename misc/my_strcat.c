/*
** strcat.c for strcat in /home/exam/rendu/task05
** 
** Made by exam user
** Login   <exam@epitech.net>
** 
** Started on  Thu Nov 24 16:07:23 2016 exam user
** Last update Fri Nov 25 14:10:07 2016 Cédric Thomas
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

static char	*my_strdup(char *str, int len)
{
  char		*dup;
  int		size;
  int		i;

  size = len;
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      dup[i] = str[i];
      i += 1;
    }
  dup[i] = 0;
  return (dup);
}


char	*my_strlncat(char *s1, char *s2, int lens1, int lens2)
{
  char	*cat;
  int	len;
  int	i;

  if (s1 == NULL)
    return (my_strdup(s2, lens2));
  if (s2 == NULL)
    return (s1);
  len = lens1 + lens2;
  if ((cat = malloc(sizeof(char) * (1 + len))) == NULL)
    return (NULL);
  cat[len] = 0;
  i = 0;
  while (i < len)
    {
      if (i < lens1)
	cat[i] = s1[i];
      else
	cat[i] = s2[i - lens1];
      i += 1;
    }
  free(s1);
  return (cat);
}
