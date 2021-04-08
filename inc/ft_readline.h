#ifndef FT_READLINE_H
# define FT_READLINE_H

# include "../libft/libft.h"
#include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>

# define SELECT 5263131
# define NOSELECT 5328667
# define CTRL_X 24
# define CTRL_W 23
# define CTRL_E 5
# define A_UP 1096489755
# define A_DOWN 1113266971
# define A_RIGHT 1130044187
# define A_LEFT 1146821403
# define HOME 4741915
# define END 4610843
# define ENTR 10
# define ESC 27
# define DEL2 2117294875
# define DEL 127
# define RIGHT 4414235
# define LEFT 4479771
# define UP 4283163
# define DOWN 4348699

# define B_SIZE 4096

int						g_last_his;
char					*g_cmd;
int						g_sig;
int						g_first;

struct					s_line
{
	char				*str;
	int					i;
}						g_l;

typedef struct			s_auto
{
	char				*data;
	struct s_auto		*next;
}						t_auto;

struct					s_copy
{
	int					from;
	int					to;
	char				*copy;
}						g_copy;

struct					s_pos
{
	int					x;
	int					y;
}						g_pos;

typedef	struct			s_xy
{
	int					x;
	int					y;
}						t_xy;

typedef struct			s_nod
{
	char				*data;
	char				*value;
	struct s_nod		*next;
}						t_nod;

typedef struct			s_his
{
	char				*data;
	struct s_his		*next;
	struct s_his		*prev;
}						t_his;


int				init_fd(void);
void		get_cur_position(void);

#endif
