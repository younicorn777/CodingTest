#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000000];
    int cnt = 0, len;

    scanf("%[^\n]s", str);
    len = strlen(str);

    if (len == 1 && str[0] == ' ') {
        printf("%d", cnt);
        return 0;
    }

    for (int i = 1; i < len - 1; i++) {
        if (str[i] == ' ') {
            cnt++;
        }
    }

    printf("%d", cnt + 1);
}