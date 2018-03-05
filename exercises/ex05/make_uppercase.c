#include <stdio.h>
#include <stdlib.h>

/* Takes a lowercase letter
and makes it uppercase
*/
char change_case_char(char c) {
	return c^(1<<5);
}

char *change_case_str(char *str, int len) {
	char *new_str = malloc((len+1)*sizeof(char));
	int i;
	for(i=0; i<len; i++){
		new_str[i] = change_case_char(str[i]);
	}
	return new_str;
}

int main() {
	char c[4] = "cat";
	char *new_str = change_case_str(c, 3);
	printf("%s\n", new_str);

	return 0;
}