#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <stdbool.h>

void	handle_double_op(char *input, char *res, size_t *i, size_t *j)
{
	if (*j > 0 && res[*j - 1] != ' ')
		res[(*j)++] = ' ';
	res[(*j)++] = input[*i];
	res[(*j)++] = input[*i + 1];
	if (input[*i + 2] != ' ')
		res[(*j)++] = ' ';
	(*i)++;
}

void	handle_op(char *input, char *res, size_t *i, size_t *j)
{
	if (*j > 0 && res[*j - 1] != ' ')
		res[(*j)++] = ' ';
	res[(*j)++] = input[*i];
	if (input[*i + 2] != ' ')
		res[(*j)++] = ' ';
}

void handle_ws_quotes(char *input, char *res, size_t *i, size_t *j)
{
	char quote;

	quote = input[*i];
	res[(*j)++] = input[(*i)++];
	while ((input[*i] != '\0') && (input[*i] != quote)) {
		res[(*j)++] = input[(*i)++];
	}
	if (input[*i] == quote)
	{
		printf("* Final quote found: `%c`\n", input[*i]);
		res[(*j)++] = input[(*i)];
		printf("* After: `%c`\n", input[*i]);
		printf("* RES: `%s`\n", res);
		if (input[*i] != ' ' && input[*i] != '\0') {
			printf("* I add space @ [%d]\n", *j);
			res[(*j)++] = ' ';
		}
	}
	else
		printf("error\n"); // update here
}


char *trim_spaces(char *input)
{
	size_t	len;
	size_t	j;
	size_t	i;
	bool	isspace;
	char	*res;

	if (!input)
		return (NULL);
	len = ft_strlen(input);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	isspace = false;
	while (i < len)
	{
		if ((input[i] == 34) || (input[i] == 39)) // ascii for " and '
			handle_ws_quotes(input, res, &i, &j);
		else if ((input[i] == '<' && input[i + 1] == '<') || (input[i] == '>' && input[i + 1] == '>'))
		{
			handle_double_op(input, res, &i, &j);
			isspace = true;
		}
		else if (input[i] == '|' || input[i] == '>' || input[i] == '<')
		{
			handle_op(input, res, &i, &j);
			isspace = true;
		}
		else if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		{
			if (!isspace && j > 0)
			{
				res[j++] = ' ';
				isspace = true;
			}
		}
		else
		{
			res[j++] = input[i];
			isspace = false;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	main()
{
	char	*input;
	char	*trim_inpt;
	char	*res;

	int i;
	i = 0;
	input = readline("Type Shit: ");
	if(!input)
		return (1);
	trim_inpt = ft_strtrim(input, " \n\t");
	res = trim_spaces(trim_inpt);
	printf("%s\n", input);
	printf("%s\n", trim_inpt);
	printf("%s\n", res);
	return (0);
}

// handle $