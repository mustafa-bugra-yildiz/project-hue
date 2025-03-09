#ifndef HUE_H
#define HUE_H

/* Returns a static hello world string */
const char *	hello(void);

/* Parser functions - return 0 on success, non-zero on error */
int		parse_integer(const char *input);
int		parse_float(const char *input);
int		parse_string(const char *input);

#endif				/* HUE_H */
