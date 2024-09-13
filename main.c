#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr_length(char *arr[])
{
    int i;
    int count = 0;
    for(i=0; arr[i]!=NULL; i++)
    {
        count++;
    }
    return count;
}

int main(int _, char* args[]) {
    if (arr_length(args) < 2) {
        printf("not enough arguments were provided:\n    start -> starts mongodb-docker server\n    stop -> stops mongodb-docker server\n");
        return 1;
    }
    int background;
    if (arr_length(args) >= 3) {
        if (strcmp(args[2], "--background") == 0) {
            background = 1;
        }
    }

    if (strcmp(args[1], "start") == 0) {
        if (background == 1) {
            system("cd /usr/local/mongodb-docker && sudo docker compose up 2>/dev/null & disown");
            return 0;
        }
        system("sudo docker compose up 2>/dev/null");
        printf("\n");
    } else if (strcmp(args[1], "stop") == 0) {
        system("cd /usr/local/mongodb-docker && sudo docker compose down 2>/dev/null");
        printf("\n");
    }

    return 0;
}