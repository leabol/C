#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char ch[10] = {0};

    fgets(ch, sizeof(ch), stdin);
    ch[strcspn(ch, "\n")] = '\0';

    puts(ch);

}
