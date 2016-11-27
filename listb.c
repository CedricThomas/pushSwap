/*
** swap_push.c for swap_push.c in /home/cedric/delivery/CPE/proj_pushswap/CPE_2016_Pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 25 10:54:42 2016 Cédric Thomas
** Last update Sat Nov 26 20:21:52 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "pushswap.h"

int	sb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
    if (*llb != NULL && (*llb)->next != *llb)
    {
      swap(llb);
      update_buff(buffer, " sb", 0);
      printblank(lla, llb, bool, "sb");
    }
}

int	rb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
  if (*llb != NULL && (*llb)->next != *llb)
    {
      rotate_right(llb);
      update_buff(buffer, " rb", 0);
      printblank(lla, llb, bool, "rb");
    }
}

int	rrb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
   if (*llb != NULL && (*llb)->next != *lla)
    {
      rotate_left(llb);
      update_buff(buffer, " rrb", 0);
      printblank(lla, llb, bool, "rrb");
    }
}

int	pb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
  if (*lla != NULL)
    {
      push(lla, llb);
      update_buff(buffer, " pb", 0);
      printblank(lla, llb, bool, "pb");
      buffer->list_sizeb += 1;
      (*llb)->processed = 1;
    }
}
