/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:00:37 by edvicair          #+#    #+#             */
/*   Updated: 2023/03/31 21:19:34 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     check_cub(char **av)
{
    int i;

    i = 0;
    while (av[1][i] != '\0')
        i++;
    if (av[1][i - 4] != '.' || av[1][i - 3] != 'c' || av[1][i - 2] != 'u' || av[1][i - 1] != 'b')
    {
        printf("Error : File is not a .cub\n");
        return (1);       
    }
    return (0);
}

bool    check_ndwe(char **file, t_cub *cub, int i, int j)
{
    if (file[i][j] == 'N' && file[i][j + 1] == 'O' && file[i][j + 2] == ' ')
    {
        j += 2;
        while (file[i][j] == ' ')
            j++;
        cub->wall_n = ft_substr(file[i], j, ft_strlen(file[i]));
        printf("N = %s\n", cub->wall_n);
        return (1);
    }
    else if (file[i][j] == 'S' && file[i][j + 1] == 'O' && file[i][j + 2] == ' ')
    {
        j += 2;
        while (file[i][j] == ' ')
            j++;
        cub->wall_s = ft_substr(file[i], j, ft_strlen(file[i]));
        printf("S = %s\n", cub->wall_s);
        return (1);
    }
    else if (file[i][j] == 'W' && file[i][j + 1] == 'E' && file[i][j + 2] == ' ')
    {
        j += 2;
        while (file[i][j] == ' ')
            j++;
        cub->wall_w = ft_substr(file[i], j, ft_strlen(file[i]));
        printf("W = %s\n", cub->wall_w);
        return (1);
    }
    else if (file[i][j] == 'E' && file[i][j + 1] == 'A' && file[i][j + 2] == ' ')
    {
        j += 2;
        while (file[i][j] == ' ')
            j++;
        cub->wall_e = ft_substr(file[i], j, ft_strlen(file[i]));
        printf("E = %s\n", cub->wall_e);
        return (1);
    }
    return (0);
}

bool    check_val(t_cub *cub)
{
    if (cub->f == -1 || cub->c == -1)
    {
        printf("Error : 0 >= RGB <= 255\n");
    }
    if (!cub->wall_n || !cub->wall_s || !cub->wall_w || !cub->wall_e || !cub->f || !cub->c)
        return (1);
    return (0);
}

bool    is_line(char *file)
{
    int i;

    i = 0;
    if (file[0] != ' ' && file[0] != '\0')
        return (0);
    while (file[i])
    {
        if (file[i] == ' ')
            i++;
        else if (file[i] != ' ' && file[i] != '\0')
            break;
    }
    if (file[i] == '\0')
        return (1);
    return (0);
}
