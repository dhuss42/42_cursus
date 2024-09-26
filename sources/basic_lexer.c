
#include "libft/libft.h"

typedef enum
{
	TOKEN_PIPE,
	TOKEN_REDIN,
	TOKEN_REDOUT,
	TOKEN_WORD,
} token_type;

// enum are int values starting by 0 that are assigned to the different tokens

typedef struct s_token
{
	token_type type;
	char *input;
} token;

// struct for a single token
//	cotains the type of the token (token_type struct)
//	contains the string of chars that represents the token




token *create_token(token_type type, char *input)
{
	token *new;

	new = malloc(sizeof(token));
	if(!new)
		return (NULL);
	new->type = type;
	new->input = strdup(input);
	return (new);
}

// function creates a new token
//	allocates enough mem for the token
//	assigns the type based on the given input
//	saves the input string that corresponds to the token in question

void	free_token(void *content)
{
	token *tok = (token *)content;
	if (tok)
	{
		free(tok->input);
		free(tok);
	}
}


void	print_token(token *tok)
{
	char *token_str = NULL;

	if (tok->type == TOKEN_PIPE)
		token_str = "PIPE";
	else if (tok->type == TOKEN_REDIN)
		token_str = "REDIRECT_IN";
	else if (tok->type == TOKEN_REDOUT)
		token_str = "REDIRECT_OUT";
	else if (tok->type == TOKEN_WORD)
		token_str = "WORD";
	printf("Token\n Type: %s\n Value: %s\n\n", token_str, tok->input);
}

// function prints the Token struct and its contents
//	checks the token_type and changes the value of token_str accordingly

void	print_token_list(t_list *list)
{
	t_list *current = list;

	while (current != NULL)
	{
		token *tok = (token *)(current->content);
		print_token(tok);
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	int i;

	i = 1;
	token *tok = NULL;
	t_list *list = NULL;
	t_list *new_node = NULL;
	while (i < argc)
	{

		if (strcmp(argv[i], "|") == 0)
			tok = create_token(TOKEN_PIPE, argv[i]);
		else if (strcmp(argv[i], "<") == 0)
			tok = create_token(TOKEN_REDIN, argv[i]);
		else if (strcmp(argv[i], ">") == 0)
			tok = create_token(TOKEN_REDOUT, argv[i]);
		else
			tok = create_token(TOKEN_WORD, argv[i]);
		if (tok == NULL)
			exit(EXIT_FAILURE);

		print_token(tok);
		new_node = ft_lstnew((void *)tok);
		if (!new_node)
			free_token(tok);
		ft_lstadd_back(&list, new_node);
		i++;
	}
	printf("\033[32mTOKEN LINKED LIST\n");
	print_token_list(list);
	printf("\033[0m");
	ft_lstclear(&list, free_token);
	return (0);
}

// function iterates through input
//	compares input to the Token symbols (very basic)
//	creates the token according to the symbol in question
//	prints the token
//	frees the token

//	save the order of tokens in a linked list from libft_bonus with list add_back
//	typecast the Token into the void pointer