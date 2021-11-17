#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		is_newline(char *str);
void	*ft_memmove(void *dst, const void *src, int len);
#endif
