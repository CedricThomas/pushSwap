/*
** sort_fct.c for sort_fct.c in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 16:26:56 2016 Cédric Thomas
** Last update Tue Nov 22 14:43:56 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

int	s(t_number **lla, t_number **llb, int mod, int bool)
{
  if (mod == 1 && my_list_size(lla) > 1)
    {
      swap(lla);
      my_putstr("sa");
      printblank(lla, llb, bool);
    }
  else if (mod == 2 && my_list_size(llb) > 1)
    {
      swap(llb);
      my_putstr("sb");
      printblank(lla, llb, bool);
    }
  else
    {
      if (my_list_size(llb) > 2 && my_list_size(lla) > 2)
	{
	  swap(lla);
	  swap(llb);
	  my_putstr("sc");
	  printblank(lla, llb, bool);
	}
    }
}

int	p(t_number **lla, t_number **llb, int mod, int bool)
{
    if (mod == 1 && my_list_size(lla) > 0)
    {
      push(lla, llb);
      my_putstr("pb");
      printblank(lla, llb, bool);
    }
  else if (mod == 2 && my_list_size(llb) > 0)
    {
      push(llb, lla);
      my_putstr("pa");
      printblank(lla, llb, bool);
    }
}

int	r(t_number **lla, t_number **llb, int mod, int bool)
{
   if (mod == 1 && my_list_size(lla) > 1)
    {
      rotate_right(lla);
      my_putstr("ra");
      printblank(lla, llb, bool);
    }
  else if (mod == 2 && my_list_size(llb) > 1)
    {
      rotate_right(llb);
      my_putstr("rb");
      printblank(lla, llb, bool);
    }
  else
    {
      if (my_list_size(llb) > 1 && my_list_size(lla) > 1)
	{
	  rotate_right(lla);
	  rotate_right(llb);
	  my_putstr("rr");
	  printblank(lla, llb, bool);
	}
    }
}

int	rr(t_number **lla, t_number **llb, int mod, int bool)
{
   if (mod == 1 && my_list_size(lla) > 1)
    {
      rotate_left(lla);
      my_putstr("rra");
      printblank(lla, llb, bool);
    }
  else if (mod == 2 && my_list_size(llb) > 1)
    {
      rotate_left(llb);
      my_putstr("rrb");
      printblank(lla, llb, bool);
    }
  else
    {
      if (my_list_size(llb) > 1 && my_list_size(lla) > 1)
	{
	  rotate_left(lla);
	  rotate_left(llb);
	  my_putstr("rrr");
	  printblank(lla, llb, bool);
	}
    }
}
