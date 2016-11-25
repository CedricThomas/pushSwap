/*
** module_pushswap.c for module_pushswap in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 14:48:10 2016 Cédric Thomas
** Last update Fri Nov 25 13:03:04 2016 Cédric Thomas
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void            printblank(t_number **lla, t_number **llb, int bool, char *mod)
{
  if (bool)
    {
      my_putstr(mod);
      write(1, "\nla :", 5);
      my_show_list(lla);
      write(1, "\nlb :", 5);
      my_show_list(llb);
      write(1, "\n", 1);
    }
}

int	swap(t_number **ll)
{
  int	tmp;

  if (*ll != NULL && (*ll)->next != *ll)
    {
      tmp = (*ll)->data;
      (*ll)->data = (*ll)->next->data;
      (*ll)->next->data = tmp;
    }
}

int	rotate_left(t_number **ll)
{
  if (*ll != NULL && (*ll)->next != *ll)
    {
      *ll = (*ll)->prev;
    }
}

int	rotate_right(t_number **ll)
{
  if (*ll != NULL && (*ll)->next != *ll)
    {
      *ll = (*ll)->next;
    }
}

int		push(t_number **lla, t_number **llb)
{
  t_number	*temp;

  temp = *lla;
  if (*lla == NULL)
    return (0);
  *lla = (*lla)->next;
  if (*lla == temp)
    *lla = NULL;
  temp->next->prev = temp->prev;
  temp->prev->next = temp->next;
  if (*llb == NULL)
    {
      temp->next = temp;
      temp->prev = temp;
      *llb = temp;
      return (0);
    }
  temp->next = *llb;
  temp->prev = (*llb)->prev;
  temp->prev->next = temp;
  temp->next->prev = temp;
  *llb = temp;
  return (0);
}
