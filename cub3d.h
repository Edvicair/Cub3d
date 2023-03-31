/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:26:35 by edvicair          #+#    #+#             */
/*   Updated: 2023/03/31 15:06:58 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct  s_rgb
{
    int r;
    int g;
    int b;
}                t_rgb;

typedef struct  s_cub
{
    char *wall_n;
    char *wall_s;
    char *wall_w;
    char *wall_e;
    int f;
    int c;
    int height;
    int width;
    char **map;
}               t_cub;

                            // LIB //
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void    free_double(char **str);
int     ft_atoi(const char *nptr);

                            // PARSING //
bool     parser(t_cub *cub,char **av);
bool    is_line(char *file);
bool    check_val(t_cub *cub);
bool    check_ndwe(char **file, t_cub *cub, int i, int j);
int     check_cub(char **av);
void    init_cub(t_cub *cub);
bool    init_map(char **file, t_cub *cub, int i);
bool    check_map(t_cub cub);
bool    error_map(char **map, int x);
bool    error_map2(char **map, int x, int y);
bool    error_edge(char **map, int x);
bool    check_color(int r, int g, int b);

#endif