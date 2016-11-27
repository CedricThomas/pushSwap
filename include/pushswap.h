/*
** pushswap.h for pushswap in /home/cedric/delivery/bootstrap_pushswap/release
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov  8 13:03:03 2016 Cédric Thomas
** Last update Sun Nov 27 12:01:06 2016 Cédric Thomas
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

typedef struct		s_number
{
  int			data;
  char			processed;
  int			is_first;
  struct s_number	*next;
  struct s_number	*prev;
}			t_number;

typedef struct		s_buffer
{
  char			*buff;
  char			space;
  int			write_pos;
  int			max_size;
  int			min_sizeb;
  int			size_disp;
  int			list_size;
  int			list_sizeb;
}			t_buffer;

/*
**module_list.c
*/
int	my_put_list(t_number **ll, int data);
int	my_show_list(t_number **ll);
int	my_list_size(t_number **ll);
int	my_del_list(t_number **ll, t_number *elem);
int	is_sorted(t_number **ll);

/*
**module_pushswap.c
*/
int	swap(t_number **ll);
int	rotate_left(t_number **ll);
int	rotate_right(t_number **ll);
int	push(t_number **lla, t_number **llb);
void	printblank(t_number **lla, t_number **llb, int bool, char *mod);

/*
**lista.c
*/
int	ra(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	rra(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	sa(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	pa(t_number **lla, t_number **llb, int bool, t_buffer *buffer);

/*
**listb.c
*/
int	rb(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	rrb(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	sb(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	pb(t_number **lla, t_number **llb, int bool, t_buffer *buffer);

/*
**insert_into_lb.c
*/
int	ins_first(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	ins_last(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	ins_betfirst(t_number **lla, t_number **llb,
		     int bool, t_buffer *buffer);
int	ins_betlast(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int     insert_first_into_lb(t_number **lla, t_number **llb,
			     int bool, t_buffer *buffer);

/*
**init_lb.c
*/
int	create_lb(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int     move_lb_into_la(t_number **lla, t_number **llb,
			int bool, t_buffer *buffer);

/*
**sort.c
*/
void	update_buff(t_buffer *buffer, char *mod, int forced);
int	sort(t_number **lla, int bool);

/*
**strcat.c
*/
char	*my_strdup(char *str);
int	my_strlen(char *str);

#endif /* !PUSHSWAP_H_ */
