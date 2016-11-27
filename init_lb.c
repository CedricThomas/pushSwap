/*
** init_lb.c for init_lb in /home/cedric/delivery/CPE/proj_pushswap/CPE_2016_Pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 26 12:04:05 2016 Cédric Thomas
** Last update Sun Nov 27 13:15:32 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "pushswap.h"

static int	do_not_processed(t_number **lla, t_number **llb,
				 int bool, t_buffer *buffer)
{
  int	test;

  test = 0;
  if (!(*lla)->processed)
    {
      if ((*lla)->prev->data <= (*llb)->data)
	pa(lla, llb, bool, buffer);
      else
	rra(lla, llb, bool, buffer);
      test = 1;
    }
  else if (!(*lla)->prev->processed && (*lla)->data >= (*llb)->data)
    {
      pa(lla, llb, bool, buffer);
      test = 1;
    }
  return (test);
}

static int	get_to_cancel(t_number **lla, t_number **llb,
			      int bool, t_buffer *buffer)
{
  int	to_cancel;

  to_cancel = 0;
  while (*llb != NULL && ++to_cancel)
    {
      if (do_not_processed(lla, llb, bool, buffer))
	to_cancel += 0;
      else if ((*lla)->data >= (*lla)->prev->data)
	{
	  if ((*llb)->data <= (*lla)->data && (*llb)->data >= (*lla)->prev->data
	      || (*lla)->prev == *lla)
	    pa(lla, llb, bool, buffer);
	  else
	    rra(lla, llb, bool, buffer);
	}
      else
	{
	  if ((*llb)->data <= (*lla)->data || (*llb)->data >= (*lla)->prev->data
	      || (*lla)->prev == *lla)
	    pa(lla, llb, bool, buffer);
	  else
	    rra(lla, llb, bool, buffer);
	}
    }
  return (to_cancel);
}

int	move_lb_into_la(t_number **lla, t_number **llb,
			int bool, t_buffer *buffer)
{
  int	ramod;

  ramod = get_to_cancel(lla, llb, bool, buffer);
  if (ramod < (buffer->list_size - ramod))
    {
      while (!(!(*lla)->processed ||
	       ((*lla)->processed &&
		(*lla)->prev->processed &&
		(*lla)->data < (*lla)->prev->data)))
	ra(lla, llb, bool, buffer);
    }
  else
    {
      while (!(!(*lla)->processed && (*lla)->prev->processed
	     || (*lla)->processed && (*lla)->prev->processed
	       && (*lla)->prev->data > (*lla)->data))
	rra(lla, llb, bool, buffer);
    }
}

int	complete_lb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
  while (!(*lla)->processed && buffer->list_sizeb < buffer->min_sizeb)
    {
      if ((*llb)->data > (*llb)->prev->data)
	{
	  if ((*lla)->data >= (*llb)->data || (*lla)->data <= (*llb)->prev->data)
	    pb(lla, llb, bool, buffer);
	  else
	    rb(lla, llb, bool, buffer);
	}
      else
	{
	  if ((*lla)->data >= (*llb)->data && (*lla)->data <= (*llb)->prev->data)
	    pb(lla, llb, bool, buffer);
	  else if ((*lla)->data < (*llb)->data)
	    rb(lla, llb, bool, buffer);
	  else
	    rrb(lla, llb, bool, buffer);
	}
    }
  while (*llb != NULL && (*llb)->data <= (*llb)->prev->data)
    rb(lla, llb, bool, buffer);
}

int	create_lb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
  int	test;

  test = 1;
  buffer->list_sizeb = 0;
  while ((*lla)->processed == 0 && test)
    {
      test = insert_first_into_lb(lla, llb, bool, buffer);
    }
  if (buffer->list_sizeb < buffer->min_sizeb && (*lla)->processed == 0)
    complete_lb(lla, llb, bool, buffer);
  return ((*lla)->processed);
}
