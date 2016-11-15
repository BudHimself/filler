#include "libft/include/printf.h"

int			main(int ac, char **av)
{
	char	*start;
	char	name_map[2];
	char	*name_ia;
	char	*ret;
	char	*line;
	char	*p1;
	char	*p2;
	char	*sys;
	int		ia;
	int		map;
	int		num;
	int		fd;

	ia = 0;
	if (ac < 2 || ac > 3)
	{
		ft_putendl("mettre en parametre le nom de votre IA sans le chemin, au format : \"login.filler\" present dans le dossier ./players de la VM");
		ft_putendl("indiquer en deuxieme parametre \"-p1\" ou \"-p2\" pour jouer en joueur 1 ou 2");
		return (0);
	}
	if (ft_strequ(av[2], "-p1"))
	{
		p1 = ft_strdup("-p2");
		p2 = ft_strdup("-p1");
	}
	else if (ft_strequ(av[2], "-p2"))
	{
		p1 = ft_strdup("-p1");
		p2 = ft_strdup("-p2");
	}
	while (ia < 6)
	{
		if (ia == 0)
			name_ia = ft_strdup("players/abanlin.filler ");
		if (ia == 1)
			name_ia = ft_strdup("players/carli.filler ");
		if (ia == 2)
			name_ia = ft_strdup("players/champely.filler ");
		if (ia == 3)
			name_ia = ft_strdup("players/grati.filler ");
		if (ia == 4)
			name_ia = ft_strdup("players/hcao.filler ");
		if (ia == 5)
			name_ia = ft_strdup("players/superjeannot.filler ");
		map = 48;
		fd = open("resultat", O_CREAT | O_RDWR | O_APPEND, 0666);
		ft_putendl("---------------");
		ft_putendl(name_ia);
		while (map < 51)
		{
			num = 0;
			name_map[0] = map;
			name_map[1] = 0;
			ft_putstr("map0");
			ft_putendl(name_map);
			ft_putendl("---------------");
			while (num < 5)
			{
				start = ft_strdup("./filler_vm -f maps/map0");
				ret = ft_strnew(0);
				ret = ft_strjoin_free(start, name_map, 1);
				ret = ft_strjoin_free(ret, " ", 1);
				ret = ft_strjoin_free(ret, p1, 1);
				ret = ft_strjoin_free(ret, " ", 1);
				ret = ft_strjoin_free(ret, name_ia, 1);
				ret = ft_strjoin_free(ret, " ", 1);
				ret = ft_strjoin_free(ret, p2, 1);
				ret = ft_strjoin_free(ret, " ", 1);
				ret = ft_strjoin_free(ret, " players/", 1);
				ret = ft_strjoin_free(ret, av[1], 1);
				ret = ft_strjoin_free(ret, " > resultat_vm", 1);
				system(ret);
				system("cat resultat_vm | grep \"==\" && cat filler.trace | grep \"won\"");
				num++;
			}
			ft_putendl("---------------");
			map++;
		}
		ia++;
	}
	free(p1);
	free(p2);
	return (0);
}
