/*
** swap_push.c for swap_push.c in /home/cedric/delivery/CPE/proj_pushswap/CPE_2016_Pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 25 10:54:42 2016 Cédric Thomas
** Last update Fri Nov 25 14:20:55 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "pushswap.h"

int	sa(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
    if (*lla != NULL && (*lla)->next != *lla)
    {
      swap(lla);
      update_buff(buffer, "sa ", 0);
      printblank(lla, llb, bool, "sa");
    }
}

int     pa(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
   if (*llb != NULL)
    {
      push(llb, lla);
      update_buff(buffer, "pa ", 0);
      printblank(lla, llb, bool, "pa");
    } 
}

int     pb(t_number **lla, t_number **llb, int bool, t_buffer *buffer)
{
  if (*lla != NULL)
    {
      push(lla, llb);
      update_buff(buffer, "pb ", 0);
      printblank(lla, llb, bool, "pb");
    }
}