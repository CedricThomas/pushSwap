/*
** pushswap.h for pushswap in /home/cedric/delivery/bootstrap_pushswap/release
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov  8 13:03:03 2016 Cédric Thomas
** Last update Fri Nov 25 14:24:36 2016 Cédric Thomas
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

# define BUFF_SIZE	409600

typedef struct		s_number
{
  int			data;
  char			bool;
  int			tag;
  struct s_number	*next;
  struct s_number	*prev;
}			t_number;

typedef struct		s_buffer
{
  char			buff[BUFF_SIZE];
  int			buff_size;
  int			disp_size;
  char			*to_disp;
  int			list_size;
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
**rotate.c
*/
int	ra(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	rra(t_number **lla, t_number **llb, int bool, t_buffer *buffer);

/*
**swap_push.c
*/
int	sa(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	pa(t_number **lla, t_number **llb, int bool, t_buffer *buffer);
int	pb(t_number **lla, t_number **llb, int bool, t_buffer *buffer);

/*
**sort.c
*/
void	update_buff(t_buffer *buffer, char *mod, int forced);
int	sort(t_number **lla, int bool);

/*
**strcat.c
*/
char	*my_strlncat(char *s1, char *s2, int lens1, int lens2);
int	my_strlen(char *str);

#endif /* !PUSHSWAP_H_ */
