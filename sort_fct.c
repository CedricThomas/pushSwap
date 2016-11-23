/*
** sort_fct.c for sort_fct.c in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 16:26:56 2016 Cédric Thomas
** Last update Wed Nov 23 22:42:30 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

int	s(t_number **lla, t_number **llb, int mod, int bool)
{
  if (mod == 1 && *lla != NULL && (*lla)->next != *lla)
    {
      swap(lla);
      my_putstr("sa");
      printblank(lla, llb, bool, "sa");
    }
  else if (mod == 2 && *llb != NULL && (*llb)->next != *llb)
    {
      swap(llb);
      my_putstr("sb");
      printblank(lla, llb, bool, "sb");
    }
  else
    {
      if (*lla != NULL && (*lla)->next != *lla &&
	  mod == 2 && *llb != NULL && (*llb)->next != *llb)
	{
	  swap(lla);
	  swap(llb);
	  my_putstr("sc");
	  printblank(lla, llb, bool, "sc");
	}
    }
}

int	p(t_number **lla, t_number **llb, int mod, int bool)
{
    if (mod == 1 && *lla != NULL)
    {
      push(lla, llb);
      my_putstr("pb");
      printblank(lla, llb, bool, "pb");
    }
  else if (mod == 2 && *llb != NULL)
    {
      push(llb, lla);
      my_putstr("pa");
      printblank(lla, llb, bool, "pa");
    }
}

int	r(t_number **lla, t_number **llb, int mod, int bool)
{
   if (mod == 1 && *lla != NULL && (*lla)->next != *lla)
    {
      rotate_right(lla);
      my_putstr("ra");
      printblank(lla, llb, bool, "ra");
    }
  else if (mod == 2 && *llb != NULL && (*llb)->next != *llb)
    {
      rotate_right(llb);
      my_putstr("rb");
      printblank(lla, llb, bool, "rb");
    }
  else
    {
      if (*lla != NULL && (*lla)->next != *lla &&
	  *llb != NULL && (*llb)->next != *llb)
	{
	  rotate_right(lla);
	  rotate_right(llb);
	  my_putstr("rr");
	  printblank(lla, llb, bool, "rr");
	}
    }
}

int	rr(t_number **lla, t_number **llb, int mod, int bool)
{
   if (mod == 1 && *lla != NULL && (*lla)->next != *lla)
    {
      rotate_left(lla);
      my_putstr("rra");
      printblank(lla, llb, bool, "rra");
    }
  else if (mod == 2 && *llb != NULL && (*llb)->next != *llb)
    {
      rotate_left(llb);
      my_putstr("rrb");
      printblank(lla, llb, bool, "rrb");
    }
  else
    {
      if (*lla != NULL && (*lla)->next != *lla
	  && *llb != NULL && (*llb)->next != *llb)
	{
	  rotate_left(lla);
	  rotate_left(llb);
	  my_putstr("rrr");
	  printblank(lla, llb, bool, "rrr");
	}
    }
}
