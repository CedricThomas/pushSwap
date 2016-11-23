/*
** module_pushswap.c for module_pushswap in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 14:48:10 2016 Cédric Thomas
** Last update Wed Nov 23 22:56:16 2016 Cédric Thomas
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void            printblank(t_number **lla, t_number **llb, int bool, char *mod)
{
  if ((my_strcmp(mod, "pa") != 0 ||
       *llb != NULL) && bool == 0)
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
