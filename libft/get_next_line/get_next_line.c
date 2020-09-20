#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*gnl;
	char		buff[513];
	char		*temp, *temp2;
	int			bt; 

	if (!line)
		return (-1);
	while (ft_strchr(gnl, '\n') == NULL)
	{
		bt = read(fd, buff, 512);
		if (bt < 0)
			return (-1);
		else if (!bt)
			break ;
		buff[bt] = 0;
		if (!gnl)
			gnl = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = temp;
		}
	}
	if (!bt && !gnl)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((temp = ft_strchr(gnl, '\n')))
	{
		*temp = 0;
		*line = ft_strdup(gnl);
		temp2 = ft_strdup(++temp);
		free(gnl);
		gnl = temp2;
	}
	else
	{
		*line = ft_strdup(gnl);
		free(gnl);
		gnl = NULL;
		return (0);
	}
	return (1);
}
