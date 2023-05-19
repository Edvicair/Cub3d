/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:05:36 by edvicair          #+#    #+#             */
/*   Updated: 2023/05/18 23:33:12 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_cub(t_cub *cub)
{
    cub->wall_n = NULL;
    cub->wall_s = NULL;
    cub->wall_w = NULL;
    cub->wall_e = NULL;
    cub->f = 0;
    cub->c = 0;
    cub->height = 0;
    cub->width = 0;
    cub->map = NULL;
}

int     main(int ac, char **av)
{
    t_cub cub;
    
    init_cub(&cub);
    if (ac == 2)
    {
        if (parser(&cub, av))
            printf("PAS OK\n");
        else
            printf("OK\n");
    }
    else    
        printf("Error : .cub in arg\n");
    return (0);
}
