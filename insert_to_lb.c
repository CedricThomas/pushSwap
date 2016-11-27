/*
** insert_to_lb.c for insert in /home/cedric/delivery/CPE/proj_pushswap/CPE_2016_Pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 26 11:40:18 2016 Cédric Thomas
** Last update Sat Nov 26 19:17:27 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "pushswap.h"

int	ins_first(t_number **lla, t_number **llb,
		  int bool, t_buffer *buffer)
{
  if ((*lla)->data >= (*llb)->data)
    {
      (*lla)->processed = 1;
      pb(lla, llb, bool, buffer);
      return (1);
    }
  return (0);
}

int	ins_last(t_number **lla, t_number **llb,
		 int bool, t_buffer *buffer)
{
  if ((*lla)->data <= (*llb)->prev->data)
    {
      (*lla)->processed = 1;
      pb(lla, llb, bool, buffer);
      rb(lla, llb, bool, buffer);
      return (1);
    }
  return (0);
}

int	ins_betfirst(t_number **lla, t_number **llb,
		     int bool, t_buffer *buffer)
{
  if ((*lla)->data < (*llb)->data && (*lla)->data >= (*llb)->next->data)
    {
      (*lla)->processed = 1;
      pb(lla, llb, bool, buffer);
      sb(lla, llb, bool, buffer);
      return (1);
    }
  return (0);
}

int	ins_betlast(t_number **lla, t_number **llb,
		    int bool, t_buffer *buffer)
{
  if ((*lla)->data > (*llb)->prev->data
      && (*lla)->data <= (*llb)->prev->prev->data)
    {
      (*lla)->processed = 1;
      rrb(lla, llb, bool, buffer);
      pb(lla, llb, bool, buffer);
      rb(lla, llb, bool, buffer);
      rb(lla, llb, bool, buffer);
      return (1);
    }
  return (0);

}

int	insert_first_into_lb(t_number **lla, t_number **llb,
			     int bool, t_buffer *buffer)
{
  if (*llb == NULL)
    {
      (*lla)->processed = 1;
      pb(lla, llb, bool, buffer);
      return (1);
    }
  else if (ins_betfirst(lla, llb, bool, buffer)
	   || ins_betlast(lla, llb, bool, buffer)
	   || ins_first(lla, llb, bool, buffer)
	   || ins_last(lla, llb, bool, buffer))
    return (1);
}
