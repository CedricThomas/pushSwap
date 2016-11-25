/*
** main.c for pushswap in /home/cedric/delivery/bootstrap_pushswap/release
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov  8 13:18:31 2016 Cédric Thomas
** Last update Thu Nov 24 10:51:28 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

static int	my_pushswap(t_number *lla, int bool)
{
  if (lla != NULL && !is_sorted(&lla))
    sort(&lla, bool);
  if (!bool || lla == NULL)
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
      if (!my_put_list(&lla, my_getnbr(av[i])))
	{
	  my_putstr("Enter valide numbers\n");
	  return (84);
	}
      i += 1;
    }
  my_pushswap(lla, bool);
  while (lla != NULL)
    my_del_list(&lla, lla);
  return (0);
}
