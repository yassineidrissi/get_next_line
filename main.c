#include "get_next_line.h"

int main()
{
	int i;
	i = 0;
	char *line;
	int fd = open("./gnlTester/files/42_with_nl", O_RDONLY);
	while (i++ < 2)
	{
		line = get_next_line(fd);
		printf("%d-%s", i, line);
	}
	return (0);		
}