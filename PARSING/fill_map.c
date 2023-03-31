/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:46:54 by edvicair          #+#    #+#             */
/*   Updated: 2023/03/22 09:05:57 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     count_col(char **file)
{
    int max;
    int i;
    int j;

    i = 0;
    max = 0;
    while (file[i])
    {
        j = 0;
        while (file[i][j])
            j++;
        if (max < j)
            max = j;
        i++;
    }
    return (max);
}

bool    fill_map(char **file, t_cub *cub, int i, int max)
{
    int x;
    int y;

    x = 0;
    cub->width = count_col(file);
    while (file[i] && i < max)
    {
        y = 0;
        cub->map[x] = (char *)malloc(sizeof(char) * cub->width + 1);
        while (file[i][y])
        {
            cub->map[x][y] = file[i][y];
            y++;
        }
        while (y < cub->width)
        {
            cub->map[x][y] = ' ';
            y++;
        }
        cub->map[x][y] = '\0';
        i++;
        x++;
    }
    cub->map[x] = NULL;
}

bool    init_map(char **file, t_cub *cub, int i)
{
    int j;
    int k;
    
    cub->height = 0;
    while (is_line(file[i]))
        i++;
    j = i;
    while (file[j] && !is_line(file[j]))
    {
        cub->height++;
        j++;
    }
    k = j;
    while (file[k] && is_line(file[k]))
        k++;
    if (file[k] && !is_line(file[k]))
    {
        printf("Error map : The map cannot be separated by nl\n");
        return (1);
    }
    cub->map = (char **)malloc(sizeof(char *) * (cub->height + 1));
    if (!cub->map)
        return (1);
   fill_map(file, cub, i, j);
    return (0);   
}

bool    check_map(t_cub cub)
{
    int x;
    int player;

    x = 0;
    player = 0;
    while (cub.map[x] != NULL)
    {
        if (x == 0 || x == cub.height - 1)
        {
            if (error_edge(cub.map, x))
            {
                printf("error edge\n");
                return (1);
            }
        }
        else if (x > 0 && x < cub.height - 1)
        {
            if (cub.map[x][0] != ' ' && cub.map[x][0] != '1')
            {
                printf("error dext\n");
                return (1);
            }
            if (cub.map[x][cub.width - 1] != ' ' && cub.map[x][cub.width - 1] != '1')
            {
                printf("error fext\n");
                return (1);
            }
            else
            {
                if (error_map(cub.map, x))
                {
                    printf("error map\n");
                    return (1);
                }
            }
        }
        x++;
    }
    return (0);
}