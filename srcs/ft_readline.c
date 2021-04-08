#include "../inc/ft_readline.h"

int				init_fd(void)
{
	static int	fd;

	if (!(fd) && (fd = open(ttyname(0), O_WRONLY)))
		;
	return (fd);
}

int						init_global_vars(int fd)
{
	struct termios		config;

	g_last_his = 0;
	g_first = 0;
	g_copy.from = -1;
	g_copy.to = -1;
	g_sig = 0;
	if (tcgetattr(fd, &config) < 0)
		return (-1);
	config.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(fd, TCSANOW, &config) < 0)
		return (-1);
	if (!tgetent(NULL, getenv("TERM")) || !getenv("TERM"))
	{
		ft_putendl_fd("failure to unitialise Temrcap", 2);
		return (-1);
	}
	return (0);
}

char	*my_readline(t_his **history, char *prp)
{
	struct termios old_config;
	char *line;
	int fd;

	// if (!(fd = init_fd()))
	// {
	// 	ft_putstr("21sh: Canot Open fd !!\n");
	// 	return (NULL);
	// }
	if ((fd = open("/dev/tty", O_RDWR)) < 0)
	{
		ft_putstr("21sh: Canot Open fd !!\n");
		return (NULL);
	}
	tcgetattr(fd, &old_config);
	if (init_global_vars(fd))
		return (NULL);
	get_cur_position();


	return (NULL);
}

int main(int ac, char **av)
{
	t_his *history;
	char *str = my_readline(&history, "21sh $ ");
	printf("What ! \n");
}