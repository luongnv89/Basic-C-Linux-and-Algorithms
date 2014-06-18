#include <stdio.h>
char **path(char *input) {
	int i = 0, j = 0;
	char **path;
	while (*(input + i) != '\0') {
		*path + j = (char*) malloc(256 * sizeof(char));
		while (!isspace(*(input + i))) {
			*((*path + j) + i) = *(input + i);
			i++;
		}
		j++;
	}
	return path;
}

void show(char *path) {
	int i = 0;
	while (*(path + i) != '\0') {
		printf("%c", path[i]);
		i++;
	}
}
int main(){
	char input[256];
	scanf("%s",&input);
	show(path);
	return 0;
}
