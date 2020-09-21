#include "get_next_line.h"

static int			output(char **s, char **line, int r)
{
	char			*tmp;
	char			*aux;

	if (r < 0)
		return (-1);
	if (*s == NULL && r == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((tmp = ft_strchr(*s, '\n')))
	{
		*tmp = 0;
		*line = ft_strdup(*s);
		aux = ft_strdup(++tmp);
		free(*s);
		*s = aux;
	}
	else
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			*temp;
	static char		*s[4096];
	char			buff[BUFFER_SIZE + 1];
	int				r;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = 0;
		if (s[fd] == NULL)
			s[fd] = (ft_strdup(buff));
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(&s[fd], line, r));
}