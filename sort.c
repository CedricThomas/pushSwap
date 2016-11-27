/*
** sort.c for sort.c in /home/cedric/Desktop/pushswap
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 16:38:49 2016 Cédric Thomas
** Last update Sun Nov 27 13:22:19 2016 Cédric Thomas
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void		update_buff(t_buffer *bf, char *mod, int forced)
{
  int		i;

  i = 0;
  if (bf->size_disp > bf->max_size - 10)
    {
      write(1, bf->buff + bf->space, bf->write_pos - bf->space);
      bf->write_pos = 0;
      bf->size_disp = 0;
      bf->space = 0;
    }
  while (mod[i])
    {
      bf->buff[bf->write_pos] = mod[i];
      bf->write_pos += 1;
      i += 1;
    }
  bf->size_disp += my_strlen(mod);
}

static int	init_buffer(t_number **lla, t_buffer *buffer)
{
  buffer->list_size = my_list_size(lla);
  buffer->max_size = 50000000;
  buffer->min_sizeb = my_list_size(lla) / 200;
  buffer->buff = malloc(buffer->max_size);
  buffer-> write_pos = 0;
  buffer->space = 1;
  if (buffer->buff == NULL)
    return (-1);
  buffer->size_disp = 0;
}

int		sort(t_number **lla, int bool)
{
  int		test;
  t_number	*llb;
  t_buffer	buffer;

  llb = NULL;
  test = 0;
  if (init_buffer(lla, &buffer) == -1)
    return (0);
  (*lla)->prev->processed = 1;
  (*lla)->prev->is_first = 1;
  while (!test)
    {
      test = create_lb(lla, &llb, bool, &buffer);
      move_lb_into_la(lla, &llb, bool, &buffer);
    }
   if (buffer.write_pos != 0 && !bool)
       write(1, buffer.buff + buffer.space, buffer.write_pos - buffer.space);
  free(buffer.buff);
}
