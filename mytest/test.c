#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char cd_emsg[] = "can't cd to ";
	char *end = "/root";
	char *ch_msg;

	ch_msg = malloc((strlen(end) + strlen(cd_emsg)) * sizeof(char *));
	memcpy(ch_msg, cd_emsg, strlen(cd_emsg));
	memcpy(ch_msg + strlen(cd_emsg), end, strlen(end));

	printf("%s", ch_msg);
	return (0);

}
