/*
** sort.c for sort.c in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 16:38:49 2016 Cédric Thomas
** Last update Tue Nov 22 14:33:24 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

int             getmin(t_number **lla)
{
  t_number	*temp;
  int		first;
  int		value;
  int		index;
  int		bool;
  int		i;

  temp = *lla;
  index = 0;
  i = 0;
  bool = 1;
  value = temp->data;
  while (temp != *lla || bool)
    {
      if (value > temp->data)
	{
	  index = i;
	  value = temp->data;
	}
      temp = temp->next;
      i += 1;
      bool = 0;
    }
  return (index);
}

static void             getfirst(t_number **lla, t_number **llb, int bool)
{
  int   min;
  int   value;
  int   i;
  int   rotate;

  min = getmin(lla);
  i = 0;
  if (min > my_list_size(lla) / 2)
    rotate = my_list_size(lla) - min;
  else
    rotate = min;
  while (i < rotate && !is_sorted(lla))
    {
      if (min > my_list_size(lla) / 2)
	rr(lla, llb, 1, bool);
      else
	r(lla, llb, 1, bool);
      i += 1;
    }
}

int		sort(t_number **lla, int bool)
{
  int		i;
  t_number	*llb;

  llb = NULL;
  while (!is_sorted(lla))
    {
      i = 0;
      if ((*lla)->data > (*lla)->next->data)
  	s(lla, &llb, 1, bool);
      getfirst(lla, &llb, bool);
      if (!is_sorted(lla))
  	p(lla, &llb, 1, bool);
    }
  while (llb != NULL)
    p(lla, &llb, 2, bool);
}
