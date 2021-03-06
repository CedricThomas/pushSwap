/*
** rotate.c for rotate in /home/cedric/delivery/CPE/proj_pushswap/CPE_2016_Pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 25 10:50:07 2016 Cédric Thomas
** Last update Sat Nov 26 20:02:12 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "pushswap.h"

int	ra(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
  if (*lla != NULL && (*lla)->next != *lla)
    {
      rotate_right(lla);
      update_buff(buffer, " ra", 0);
      printblank(lla, llb, bool, "ra");
    }
}

int	rra(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
   if (*lla != NULL && (*lla)->next != *lla)
    {
      rotate_left(lla);
      update_buff(buffer, " rra", 0);
      printblank(lla, llb, bool, "rra");
    }
}

int	sa(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
    if (*lla != NULL && (*lla)->next != *lla)
    {
      swap(lla);
      update_buff(buffer, " sa", 0);
      printblank(lla, llb, bool, "sa");
    }
}

int	pa(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
   if (*llb != NULL)
    {
      buffer->list_sizeb -= 1;
      push(llb, lla);
      update_buff(buffer, " pa", 0);
      printblank(lla, llb, bool, "pa");
    }
}
