/*
** sort.c for sort.c in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 16:38:49 2016 Cédric Thomas
** Last update Fri Nov 25 14:19:48 2016 Cédric Thomas
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void    update_buff(t_buffer *bf, char *mod, int forced)
{
  int	i;

  i = 0;
  while (mod[i] && !forced)
    {
      bf->buff[bf->buff_size] = mod[i];
      bf->buff_size += 1;
      i += 1;
    }
  if (bf->buff_size > BUFF_SIZE - 6 || forced)
    {
      bf->to_disp = my_strlncat(bf->to_disp, bf->buff, bf->disp_size, bf->buff_size);
      bf->disp_size += bf->buff_size;
      bf->buff_size = 0;
    } 
}

int             getmin(t_number **lla)
{
  t_number	*temp;
  int		first;
  int		value;
  int		index;
  int		bool;
  int		i;

  temp = *lla;
  index = 0;
  i = 0;
  bool = 1;
  value = temp->data;
  while (temp != *lla || bool)
    {
      if (value > temp->data)
	{
	  index = i;
	  value = temp->data;
	}
      temp = temp->next;
      i += 1;
      bool = 0;
    }
  return (index);
}

static void             getfirst(t_number **lla,
				 t_number **llb, int bool, t_buffer *buffer)
{
  int   min;
  int   value;
  int   i;
  int   rotate;

  min = getmin(lla);
  i = 0;
  if (min > buffer->list_size / 2)
    rotate = buffer->list_size - min;
  else
    rotate = min;
  while (i < rotate)
    {
      if (min > buffer->list_size / 2)
	rra(lla, llb, bool, buffer);
      else
	ra(lla, llb, bool, buffer);
      i += 1;
    }
}

int		sort(t_number **lla, int bool)
{
  int		i;
  t_number	*llb;
  t_buffer	buffer;

  llb = NULL;
  buffer.list_size = my_list_size(lla);
  buffer.to_disp = NULL;
  buffer.disp_size = 0;
  buffer.buff_size = 0;
  while ((*lla)->next->next != *lla)
    {
      i = 0;
      if ((*lla)->data > (*lla)->next->data)
  	sa(lla, &llb, bool, &buffer);
      getfirst(lla, &llb, bool, &buffer);
      pb(lla, &llb, bool, &buffer);
      buffer.list_size -= 1;
    }
  if ((*lla)->next->data < (*lla)->data)
    sa(lla, &llb, bool, &buffer);
  while (llb != NULL)
    pa(lla, &llb, bool, &buffer);
  update_buff(&buffer, "test", 1);
  write(1, buffer.to_disp, buffer.disp_size - 1);
  free(buffer.to_disp);
}
