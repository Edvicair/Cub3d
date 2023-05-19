/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:03:02 by edvicair          #+#    #+#             */
/*   Updated: 2023/05/19 01:11:58 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     count_line(char **av)
{
    int fd;
    int i;

    i = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Can't open %s\n", av[1]);
        return (0);
    }
    while (get_next_line(fd))
        i++;
    return (i);
}

int color_trgb(int t, t_rgb rgb)
{
    return (t << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

bool    fill_rgb(t_rgb *rgb, char *s, int color, int x)
{
    if (x == 0)
    {
      rgb->r = -1;  
      rgb->g = -1;  
      rgb->b = -1;  
    }
    else
    {
        if (color == 1)
            rgb->r = ft_atoi(s);
        else if (color == 2)
            rgb->g = ft_atoi(s);
        else if (color == 3)
            rgb->b = ft_atoi(s);
    }
}

int    fill_color(char **file, int i, int j)
{
    char s[150];
    t_rgb rgb;
    int k;
    int color;
    int verif;
    
    color = 1;
    k = 0;
    fill_rgb(&rgb, s, color, 0);
    while (file[i][j])
    {
        if (file[i][j] < 48 && file[i][j] > 57 && file[i][j] != ',' && file[i][j] != ' ')
            return (-1);
        if (file[i][j] >= 48 && file[i][j] <= 57)
        {
            s[k] = file[i][j];
            k++;
            verif = 0;
        }
        j++;
        if (file[i][j] == ',' || !file[i][j])
        {
            if (verif == 1)
            {
                printf("Error R,G,B\n");
                return (-1);
            }
            verif = 1;
            s[k] = 0;
            fill_rgb(&rgb, s, color, 1);
            color++;
            k = 0;
        }
    }
    if (check_color(rgb.r, rgb.g, rgb.b))
        return (-1);
    return(color_trgb(0, rgb));
}

bool    split_file(char **file, t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (file[i] && check_val(cub))
    {
        j = 0;
        while (is_line(file[i]))
            i++;
        while (file[i][j] == ' ')
            j++;
        if (check_ndwe(file, cub, i, j))
            i++;
        else if (file[i][0] == 'F' && file[i][1] == ' ')
        {
            cub->f = fill_color(file, i, (j + 1));
            printf("F = %d\n", cub->f);
            if (cub->f == -1)
                return (1);
            i++;
        }
        else if (file[i][0] == 'C' && file[i][1] == ' ')
        {
            cub->c = fill_color(file, i, (j + 1));
            printf("C = %d\n", cub->c);
            if (cub->c == -1)
                return (1);
            i++;
        }
        else
            i++;
    }
    if (!file[i])
    {
        printf("Error : Need NO, SO, WE, EA, F, C and a map in .cub\n");
        return (1);
    }
    if (init_map(file, cub, i))
        return (1);
    return (0);
}

bool   fill_cub(t_cub *cub, char **av)
{
    char **file;
    char *line;
    int i;
    int fd;

    i = 0;
    file = (char **)malloc(sizeof(char *) * (count_line(av) + 2));
    if (!file)
        return (1);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Can't open %s\n", av[1]);
        return (1);
    }
    while (i == 0 || file[i - 1] !=  NULL)
    {
        file[i] = get_next_line(fd);
        i++;
    }
    file[i] = 0;
    if (split_file(file, cub))
        return (1);
    return (0);
}

bool     parser(t_cub *cub, char **av)
{
    if (check_cub(av))
        return (1);
    if (fill_cub(cub, av))
        return (1);
    int i = 0;
    while(cub->map[i])
    {
        printf("%s\n", cub->map[i]);
        i++;
    }
    if (check_map(*cub))
        return (1);
    return (0);
}