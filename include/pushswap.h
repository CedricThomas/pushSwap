/*
** pushswap.h for pushswap in /home/cedric/delivery/bootstrap_pushswap/release
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov  8 13:03:03 2016 Cédric Thomas
** Last update Wed Nov 23 22:43:05 2016 Cédric Thomas
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

typedef struct		s_number
{
  int			data;
  char			bool;
  int			tag;
  struct s_number	*next;
  struct s_number	*prev;
}			t_number;

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
**sort_fct.c
*/
int	s(t_number **lla, t_number **llb, int mod, int bool);
int	p(t_number **lla, t_number **llb, int mod, int bool);
int	r(t_number **lla, t_number **llb, int mod, int bool);
int	rr(t_number **lla, t_number **llb, int mod, int bool);

/*
**sort.c
*/
int	sort(t_number **lla, int bool);

#endif /* !PUSHSWAP_H_ */
