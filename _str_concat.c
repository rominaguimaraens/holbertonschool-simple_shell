#include  "main.h"

char *_str_concat(char *s1, char *s2)
{
	char *conc;
	int p1, p2 = 0, len;

	if (s1 != NULL && s2 == NULL)
		len = strlen(s1);
	if (s1 == NULL && s2 != NULL)
		len = strlen(s2);
	if (s1 != NULL && s2 != NULL)
		len = (strlen(s1) + strlen(s2));
	len += 1;
	conc = malloc(len);
	if (conc == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		for (p1 = 0; s1[p1]; p1++)
		{
			conc[p2] = s1[p1];
			p2++;
		}
	}
	if (s2 != NULL)
	{
		for (p1 = 0; s2[p1]; p1++)
		{
			conc[p2] = s2[p1];
			p2++;
		}
	}
	conc[p2] = '\0';
	return (conc);
}
