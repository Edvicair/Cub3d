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

// bool    fill_map(char **file, t_cub *cub, int i, int max)
// {
//     int x;
//     int y;

//     x = 0;
//     cub->width = count_col(file);
//     while (file[i] && i < max)
//     {
//         y = 0;
//         cub->map[x] = (char *)malloc(sizeof(char) * cub->width + 1);
//         while (file[i][y])
//         {
//             cub->map[x][y] = file[i][y];
//             y++;
//         }
//         while (y < cub->width)
//         {
//             cub->map[x][y] = ' ';
//             y++;
//         }
//         cub->map[x][y] = '\0';
//         i++;
//         x++;
//     }
//     cub->map[x] = NULL;
// }

// bool    init_map(char **file, t_cub *cub, int i)
// {
//     int j;
//     int k;
    
//     cub->height = 0;
//     while (is_line(file[i]))
//         i++;
//     j = i;
//     while (file[j] && !is_line(file[j]))
//     {
//         cub->height++;
//         j++;
//     }
//     k = j;
//     while (file[k] && is_line(file[k]))
//         k++;
//     if (file[k] && !is_line(file[k]))
//     {
//         printf("Error map : The map cannot be separated by nl\n");
//         return (1);
//     }
//     cub->map = (char **)malloc(sizeof(char *) * (cub->height + 1));
//     if (!cub->map)
//         return (1);
//    fill_map(file, cub, i, j);
//     return (0);   
// }

// bool    fill_map(char **file, t_cub *cub, int min, int max)
// {
//     int x;
//     int y;
//     int w;

//     y = min;
//     x = 0;
//     printf("min = %d\n", min + 1);
//     printf("max = %d\n", max + 1);
//     while (x < cub->width)
//     {
//         y = min;
//         w = 0;
//         cub->map[x] = (char *)malloc(sizeof(char) * cub->height + 1);
//         if (!cub->map[x])
//             return (1);
//         while (y < max)
//         {
//             // if (!file[y][x] && x < cub->width)
//             // {
//             //     while (x < cub->width)
//             //     {
//             //         cub->map[x][w] = ' ';
//             //         x++;
//             //     }
//             // }
//             // if (file[y][x] == ' ')
//             //     file[y][x] = '1';
//             cub->map[x][w] = file[y][x];
//             y++;
//             w++;
//         }
//         cub->map[x][w] = '\0';
//         x++;
//     }
//     cub->map[x] = NULL;
// }

bool    malloc_cub(t_cub *cub)
{
    int i;

    i = 0;
    cub->map = (char **)malloc(sizeof(char *) * (cub->width + 1));
    if (!cub->map)
        return (1);
    while (i < cub->width)
    {
        cub->map[i] = (char *)malloc(sizeof(char) * (cub->height + 1));
        if (!cub->map[i])
            return (1);
        i++;
    }
    return (0);
}

bool    fill_map(char **file, t_cub *cub, int min, int max)
{
    int x;
    int y;
    int z;
    int w;
    y = min;
    z = 0;
    w = 0;
    x = cub->width;
    if (malloc_cub(cub))
        return (1);
    while (y < max)
    {
        while(x > ft_strlen(file[y]))
        {
            cub->map[z][w] = ' ';
            z++;
            x--;
        }
        x--;
        while(x >= 0)
        {
            cub->map[z][w] = file[y][x];
            z++;
            x--;
        }
        y++;
        w++;
        x = cub->width;
        z = 0;
    }
    while(z < cub->width)
    {
        cub->map[z][cub->height] = '\0';
        z++;
    }
    cub->map[z] = NULL;
    return (0);
}

bool    check_nl_map(char **file, t_cub *cub, int j)
{
    while (file[j])
    {
        if (!is_line(file[j]))
        {
            printf("Error map : The map cannot be separated by nl\n");
            return (1);
        }
        j++;
    }
    return (0);
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
        k = 0;
        while (file[j][k])
            k++;
        if (k > cub->width)
            cub->width = k;
        cub->height++;
        j++;
    }
    if (check_nl_map(file, cub, j))
        return (1);
    fill_map(file, cub, i, j);
    return (0); 
}


bool    check_map(t_cub cub)
{
    int x;
    int y;
    int player;

    x = 0;
    y = 0;
    player = 0;
    while (cub.map[x] != NULL)
    {
        if (x == 0 || x == cub.width - 1)
        {
            if (error_edge(cub.map, x))
            {
                printf("error edge\n");
                return (1);
            }
        }
        else if (x > 0 && x < cub.width - 1)
        {
            if (cub.map[x][0] != ' ' && cub.map[x][0] != '1')
            {
                printf("error dext\n");
                return (1);
            }
            if (cub.map[x][cub.height - 1] != ' ' && cub.map[x][cub.height - 1] != '1')
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
