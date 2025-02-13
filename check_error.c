#include "push_swap.h"

//Here an error message is being printed out
void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

//function which checks the character if it is alphanumerical
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1;
	return 0;
}


//chec if the chracter is negative
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

//check if the character is digit
int	digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//check if character is space character
int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}


void	check_error(char **argv)
{
int i;
int j;
	
	 i = 1;
	while (argv[i])
	{
		j = 0;

		while (argv[i][j] != '\0')
		{
             if (ft_isalpha(argv[i][j]))
			             	ft_error();
			if (sign(argv[i][j]))
			{
				if (argv[i][j + 1] == '\0' || !digit(argv[i][j + 1]))  
					ft_error();
				j++;
			}
			else if (digit(argv[i][j]))
			{
				if (argv[i][j+1] == '\0')
					break ;
				if (!digit(argv[i][j+1]) && !space(argv[i][j+1]))
			             	ft_error();
			}
				j++;

		}
		i++;
	}
	return ;
}
