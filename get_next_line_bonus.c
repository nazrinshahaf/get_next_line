#include "get_next_line_bonus.h"

char	*ft_join_str(char *str, char *buff)
{
	int		str_len;
	int		buff_len;
	int		total_len;
	char	*res;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	str_len = ft_strlen(str);
	buff_len = ft_strlen(buff);
	total_len = str_len + buff_len;
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	ft_memmove(res, str, str_len);
	ft_memmove(res + str_len, buff, buff_len);
	res[total_len] = '\0';
	free(str);
	return (res);
}

char	*ft_get_prev_line(char *str)
{
	char	*res;
	int		str_len;
	int		i;

	str_len = 0;
	if (!str)
		return (0);
	while (str[str_len] && str[str_len] != '\n')
		str_len++;
	if (!str[str_len])
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * ((ft_strlen(str) - str_len) + 1));
	if (!res)
		return (NULL);
	i = 0;
	str_len++;
	while (str[str_len])
		res[i++] = str[str_len++];
	res[i] = '\0';
	free(str);
	return (res);
}

char	*get_curr_line(char *str)
{
	int		i;
	char	*curr_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	curr_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!curr_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		curr_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		curr_line[i] = str[i];
		i++;
	}
	curr_line[i] = '\0';
	return (curr_line);
}

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		read_size;

	read_size = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!is_newline(str) && read_size != 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_size] = '\0';
		str = ft_join_str(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	res = get_curr_line(str[fd]);
	str[fd] = ft_get_prev_line(str[fd]);
	return (res);
}
