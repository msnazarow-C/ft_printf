#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"
int main()
{
	int f1 = open ("test.txt",O_RDONLY);
	int l;
	char *line;
	while ((l = get_next_line(f1, &line)) >= 0)
	{
		printf("%d\n%s\n",l,line);
		if (l == 0)
			break;
	}
}
