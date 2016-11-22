/*
** module_pushswap.c for module_pushswap in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 14:48:10 2016 Cédric Thomas
** Last update Mon Nov 21 19:30:31 2016 Cédric Thomas
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void            printblank(t_number **lla, t_number **llb, int bool)
{
  if ((!is_sorted(lla) || *llb != NULL) && bool == 0)
    write(1, " ", 1);
  if (bool)
    {
      my_putstr("\nla :");
      my_show_list(lla);
      my_putstr("\nlb :");
      my_show_list(llb);
      my_putchar('\n');
    }
}

int	swap(t_number **ll)
{
  int	tmp;

  if (my_list_size(ll) > 1)
    {
      tmp = (*ll)->data;
      (*ll)->data = (*ll)->next->data;
      (*ll)->next->data = tmp;
    }
}

int	rotate_left(t_number **ll)
{
  if (my_list_size(ll) > 1)
    {
      *ll = (*ll)->prev;
    }
}

int	rotate_right(t_number **ll)
{
  if (my_list_size(ll) > 1)
    {
      *ll = (*ll)->next;
    }
}

int		push(t_number **lla, t_number **llb)
{
  int		temp;

  if (my_list_size(lla) >= 1)
    {
      temp = (*lla)->data;
      my_del_list(lla, *lla);
      my_put_list(llb, temp);
      *llb = (*llb)->prev;
    }
}
