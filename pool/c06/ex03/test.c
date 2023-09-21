#include<unistd.h>

void fprint(int argc,char *argv[])
{	
	int i;
	int j;

	i = 1;
	while(argc > i)
	{	
		j = 0;
		while(argv[i][j])
		{	
			write(1, &argv[i][j], 1);	
			j++;
		}
		i++;
		write(1, "\n", 1);
		}
}
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] != '\0')
	{	
		if(s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return 0;
}
int main(int argc, char *argv[])
{
	int i;
	int j;
	char *t;

	i = 0;
	while(i < argc - 1)
	{	
		j = i + 1;
		while(j < argc)
		{		
			if(ft_strcmp(argv[i] , argv[j]) > 0)
			{	
				t = argv[i];
				argv[i] = argv[j];
				argv[j] = t;
			}
			j++;
		}
		i++;
	}
	fprint(argc,argv);
	return 0;
}

			
	
