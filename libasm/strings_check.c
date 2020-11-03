/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 01:07:25 by sgertrud          #+#    #+#             */
/*   Updated: 2020/11/03 03:08:51 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"
#include "stdio.h"
#include "fcntl.h"
#include "errno.h"

void	test_strlen(void)
{
	printf("\033[1;32m\n=== ft_strlen === \n\033[0m");
	printf("\033[33mft_strlen (empt) =>\033[0m %ld\n", ft_strlen("\0фывыфв"));
	printf("   \033[35mstrlen (empt) =>\033[0m %ld\n", strlen("\0фывфв"));
	printf("\033[33mft_strlen (medi) =>\033[0m %ld\n",
	ft_strlen("123456789012345678901234567890"));
	printf("   \033[35mstrlen (medi) =>\033[0m %ld\n",
	strlen("123456789012345678901234567890"));
	printf("\033[33mft_strlen (long) =>\033[0m %ld\n", ft_strlen("1234567890123\
	456789012345678901234567890123456789012345678901234567890123456789012345678\
	901234567890jdsfhgplsfdhgsdafhg[oidsfg[ajkfr]poi[sdafkjsdfka]afj]sadjifas]d\
	as;hfdpdsadhfposdauhf[osjaf[isajdf[isadfagh[osadifsdjif[asidfsfjsafdjjfdasd\
	asdflkjsad[fjsa[odifj[]saidfj[]sdfsfisdaf[jdf]isadfisdfias][dijaida]difjasd\
	asdfpjo[sadifj]psdojf]psaokfdpodfs]dfj]asdjf]psdjf]asdfj]asf]psjdf]asfdp"));
	printf("   \033[35mstrlen (long) =>\033[0m %ld\n", strlen("1234567890123456\
	789012345678901234567890123456789012345678901234567890123456789012345678901\
	234567890jdsfhgplsfdhgsdafhg[oidsfg[ajkfr]poi[sdafkjsdfka]afj]sadjifas]d\
	as;hfdpdsadhfposdauhf[osjaf[isajdf[isadfagh[osadifsdjif[asidfsfjsafdjjfdasd\
	asdflkjsad[fjsa[odifj[]saidfj[]sdfsfisdaf[jdf]isadfisdfias][dijaida]difjasd\
	asdfpjo[sadifj]psdojf]psaokfdpodfs]dfj]asdjf]psdjf]asdfj]asf]psjdf]asfdp"));
}

void	test_strcpy(void)
{
	char *dst;

	dst = malloc(1000);
	printf("\033[1;32m\n=== ft_strcpy ===\n\033[0m");
	printf("\033[33mft_strcpy (empt) =>\033[0m %s\n", ft_strcpy(dst, "\0фывф"));
	printf("   \033[35mstrcpy (empt) =>\033[0m %s\n", strcpy(dst, "\0фывф"));
	printf("\033[33mft_strcpy (medi) =>\033[0m %s\n", ft_strcpy(dst,
	"medium medium medium medium medium medium\0ETOGO NET"));
	printf("   \033[35mstrcpy (medi) =>\033[0m %s\n", strcpy(dst,
	"medium medium medium medium medium medium\0ETOGO NET"));
	printf("\033[33mft_strcpy (long) =>\033[0m %s\n", ft_strcpy(dst, "0123456\
	789012345678901234567890123456789012345678901234567890123456789012345678901\
	234567890jdsfhgplsfdhgsdafhg[oidsfg[ajkfr]poi[sdafkjsdfka]afj]sadjifas]d\
	as;hfdpdsadhfposdauhf[osjaf[isajdf[isadfagh[osadifsdjif[asidfsfjsafdjjfdasd\
	asdflkjsad[fjsa[odifj[]saidfj[]sdfsfisdaf[jdf]isadfisdfias][dijaida]difjasd\
	asdfpjo[sadifj]psdojf]psaokfdpodfs]dfj]asdjf]psdjf]asdfj]asf]psjdf]asfp\0\
	ETOGOTUTNET"));
	printf("   \033[35mstrcpy (long) =>\033[0m %s\n", strcpy(dst, "0123456\
	789012345678901234567890123456789012345678901234567890123456789012345678901\
	234567890jdsfhgplsfdhgsdafhg[oidsfg[ajkfr]poi[sdafkjsdfka]afj]sadjifas]d\
	as;hfdpdsadhfposdauhf[osjaf[isajdf[isadfagh[osadifsdjif[asidfsfjsafdjjfdasd\
	asdflkjsad[fjsa[odifj[]saidfj[]sdfsfisdaf[jdf]isadfisdfias][dijaida]difjasd\
	asdfpjo[sadifj]psdojf]psaokfdpodfs]dfj]asdjf]psdjf]asdfj]asf]psjdf]asfp\0\
	ETOGOTUTNET"));
	free(dst);
}

void	test_strcmp(void)
{
	char	*s;
	int		i;

	i = -1;
	s = malloc(2001);
	while (++i < 1000)
		s[i] = 's';
	s[i] = 0;
	printf("\033[1;32m\n=== ft_strcmp === \n\033[0m");
	printf("\033[33mft_strcmp (empt) =>\033[0m %d\n", ft_strcmp("", ""));
	printf("\033[33mstrcmp (empt) =>\033[0m %d\n", strcmp("", ""));
	printf("\033[33mft_strcmp (e1st) =>\033[0m %d\n", ft_strcmp("", "string"));
	printf("\033[33mstrcmp (e1st) =>\033[0m %d\n", strcmp("", "string"));
	printf("\033[33mft_strcmp (e2nd) =>\033[0m %d\n", ft_strcmp("string", ""));
	printf("\033[33mstrcmp (e2nd) =>\033[0m %d\n", strcmp("string", ""));
	printf("\033[33mft_strcmp (same) =>\033[0m %d\n", ft_strcmp(s, s));
	printf("\033[33mstrcmp (same) =>\033[0m %d\n", strcmp(s, s));
	printf("ft_strcmp (dif+) => %d\n", ft_strcmp("\xff\xff", "\xff"));
	printf("\033[33mstrcmp (dif+) =>\033[0m %d\n", strcmp("\xff\xff", "\xff"));
	printf("\033[33mft_strcmp (dif-) =>\033[0m %d\n", ft_strcmp("a", "b"));
	printf("\033[33mstrcmp (dif-) =>\033[0m %d\n", strcmp("a", "b"));
	free(s);
}

void	test_strdup(void)
{
	char *str;

	printf("\033[1;32m\n=== ft_strdup ===\n\033[0m");
	str = ft_strdup("\0tutnichego");
	printf("\033[33mempt:\033[0m %s\n", str);
	free(str);
	str = ft_strdup("school21\0tutnichego");
	printf("\033[33mshrt:\033[0m %s\n", str);
	free(str);
	str = ft_strdup("school21school21school21school21school21school21school\
	21school21school21school21school21school21school21school21school21school\
	21school21school21\0tutnichego");
	printf("\033[33mlong:\033[0m %s\n", str);
	free(str);
}
