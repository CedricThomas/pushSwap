/*
** module_list.c for module_list in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 12:15:25 2016 Cédric Thomas
** Last update Sat Nov 26 23:01:54 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

int		my_put_list(t_number **ll, int nb)
{
  t_number	*elem;
  t_number	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (0);
  elem->data = nb;
  elem->processed = 0;
  elem->is_first = 0;
  if (*ll == NULL)
    {
      elem->next = elem;
      elem->prev = elem;
      *ll = elem;
    }
  else
    {
      tmp = (*ll)->prev;
      (*ll)->prev = elem;
      elem->next = *ll;
      elem->prev = tmp;
      tmp->next = elem;
    }
  return (1);
}

int		my_show_list(t_number **ll)
{
  t_number	*tmp;

  if (*ll == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  tmp = *ll;
  while (tmp->next != *ll)
    {
      my_put_nbr(tmp->data);
      my_putchar(' ');
      tmp = tmp->next;
    }
  my_put_nbr(tmp->data);
  return (0);
}

int		my_list_size(t_number **ll)
{
  t_number	*tmp;
  int		i;

  if (*ll == NULL)
    return (0);
  i = 1;
  tmp = *ll;
  while (tmp->next != *ll)
    {
      i += 1;
      tmp = tmp->next;
    }
  return (i);
}

int		my_del_list(t_number **ll, t_number *elem)
{
  if (elem == *ll)
    *ll = (*ll)->next;
  elem->next->prev = elem->prev;
  elem->prev->next = elem->next;
  if (elem == *ll)
    *ll = NULL;
  free(elem);
}

int		is_sorted(t_number **ll)
{
  t_number	*temp;
  int		bool;

  if (*ll == NULL)
    return (1);
  temp = (*ll)->next;
  bool = 1;
  while (temp != *ll)
    {
      if (temp->prev->data > temp->data)
	bool = 0;
      temp = temp->next;
    }
  return (bool);
}
