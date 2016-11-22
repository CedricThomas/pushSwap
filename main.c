/*
** main.c for pushswap in /home/cedric/delivery/bootstrap_pushswap/release
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov  8 13:18:31 2016 Cédric Thomas
** Last update Mon Nov 21 17:06:15 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

static int	is_composed(char *str1, char *str2)
{
  int		i;
  int		j;
  int		bool;

  i = 0;
  while (str1[i])
    {
      bool = 0;
      j = 0;
      while (str2[j])
	{
	  if (str2[j] == str1[i])
	    bool = 1;
	  j += 1;
	}
      if (bool == 0)
	return (0);
      i += 1;
    }
  return (1);
}

static int	is_number(char *str)
{
  int		i;
  int		bool;

  bool = 1;
  i = 0;
  while (str[i])
    {
      if (i != 0 && (str[i] == '-' || str[i] == '+'))
	bool = 0;
      i += 1;
    }
  if (!is_composed(str, "0123456789-+"))
    bool = 0;
  return (bool);
}

static int	my_pushswap(t_number *lla, int bool)
{
  sort(&lla, bool);
  if (!bool)
    my_putchar('\n');
  return (0);
}

int		main(int ac, char **av)
{
  t_number	*lla;
  int		i;
  int		bool;

  i = 1;
  bool = 0;
  if (ac > 1 && my_strcmp("-v", av[1]) == 0)
    {
      bool += 1;
      i += 1;
    }
  lla = NULL;
  while (i < ac)
    {
      if (!my_put_list(&lla, my_getnbr(av[i]))
	  || !is_number(av[i]))
	{
	  my_putstr("Enter valide numbers\n");
	  return (84);
	}
      i += 1;
    }
  my_pushswap(lla, bool);
  return (0);
}
