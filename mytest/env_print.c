#include "main.h"
extern char **environ;
int main()
{
	size_t name_len, value_len;
	char *name = "COOK";
	char *value = "spiced chicken";
	char *env_var;
	char *env[] = {"Coconut", "Milk", "Cows", "Potatoes"};
	int i;
	char *ptr;
	
	name_len = strlen(name);
	value_len = strlen(value);

	env_var = malloc(name_len + value_len + 1);
	memcpy(env_var, name, name_len);
	env_var[name_len] = '=';
	memcpy(env_var + name_len + 1, value, value_len);
	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	puts("\n\n\n");
	ptr = (char *)(&env[1]);
	/*memcpy(*(&env[1]), env_var, name_len + value_len + 1);*/

	printf("%s\n", *(*(&env[1])));


	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	
       return (0);
}
