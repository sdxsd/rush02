#ifndef FT_ATOI_H
# define FT_ATOI_H

/* walks over the whitespace, returns offset */
unsigned int	check_whitespace(char *str);
/* determines if the number should be negative or not
 * returns offset
 * ^ is the XOR operator, *neg ^ 1 will flip the first bit */
unsigned int	should_be_negative(char *str, int *neg);
/* converts string to long, as a human would
 * overflow behaviour is undefined */
long			ft_atoi(char *str);
#endif
