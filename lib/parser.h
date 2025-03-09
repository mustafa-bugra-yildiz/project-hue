#ifndef PARSER_H
#define PARSER_H

/* Public parser functions - return 0 on success, non-zero on error */
int		parser_ParseInteger(const char *input);
int		parser_ParseFloat(const char *input);
int		parser_ParseString(const char *input);

#endif				/* PARSER_H */
