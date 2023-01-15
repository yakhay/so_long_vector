/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:22:24 by yakhay            #+#    #+#             */
/*   Updated: 2023/01/15 15:48:30 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct	solong
{
    char *coll;
    char    *movee;
    char    *monster;
    int i;
    int j;
    int k;
    int t;
	void	*mlx;
	void	*mlx_win;
    void *pla;
    void *move;
    void *col;
    int y_col;
    int direct_col;
    void *ex;
    void *mons;
    void *wall;
    void *spa;
    void *vec;
    int		img_width;
	int		img_height;
    char **str;
    int c;
    int me;
}				t_solong;
int ft_sersh_playr(char **str, int c, char k)
{
    int i;
    int j;
     i = 0;
     while(str[i])
     {
        j = 0;
        while(str[i][j])
        {
            if (str[i][j] == k)
            {
                if (c == 0)
                    return(i);
                else
                    return(j);
            }
            j++;
        }
        i++;
     }
     return(-1);
    
}
t_solong *ft_afichage(t_solong *khay)
{
    int i;
    int j;

    i = 0;
    while (khay->str[i])
    {
        j =0;
        while(khay->str[i][j])
        {
            if (khay->str[i][j] == '1')
                mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->wall, j*64, i*64);
                else
                mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->spa, j*64, i*64);
            j++;
        }
        i++;
    }
    
    i =0;
    while (khay->str[i])
    {
        j = 0;
        while(khay->str[i][j])
        {
            mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->move, 0, 0);
            if (khay->str[i][j] == 'P')
                mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->pla, j*64, i*64);
                else if (khay->str[i][j] == 'E')
                mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->ex, j*64, i*64);
                else if (khay->str[i][j] == 'C')
                mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->col, j*64, i*64);
                else if (khay->str[i][j] == 'M')
                mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->mons, j*64, i*64);
            j++;
        }
        i++;
    }
    return(khay);
}
int sersh_coli(char **str)
{
   int i ;
   int j;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == 'C')
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int key_hook(int ev, t_solong *khay)
{
    int i;
    int j;
    int l;
    int p;
    i = khay->i;
    j = khay->j;
    
    if (ev == 0 || ev == 123 )
    {
        khay->pla =  mlx_xpm_file_to_image(khay->mlx, "./pla4.xpm", &(khay->img_width), &(khay->img_height));
        j +=-1;
        khay->me = 0;
    }
    else if (ev == 13 || ev == 126)
    {
        khay->pla =  mlx_xpm_file_to_image(khay->mlx, "./pla2.xpm", &(khay->img_width), &(khay->img_height));
        i +=-1;
        khay->me =4;
    }
    else if (ev == 125 || ev == 1)
    {
        khay->pla =  mlx_xpm_file_to_image(khay->mlx, "./pla1.xpm", &(khay->img_width), &(khay->img_height));
       i +=1;
       khay->me =7;
    } 
    else if (ev == 124 || ev == 2)
    {
        khay->pla =  mlx_xpm_file_to_image(khay->mlx, "./pla3.xpm", &(khay->img_width), &(khay->img_height));
       j +=1;
       khay->me =1;
    }
    ft_afichage(khay);
    if (ev == 49)
    {
        l =ft_sersh_playr(khay->str,1,'P');
        p = ft_sersh_playr(khay->str,0,'P');
        if (khay->me == 1)
        {
            khay->vec =  mlx_xpm_file_to_image(khay->mlx, "./vector.xpm", &(khay->img_width), &(khay->img_height));
            mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->vec,(l+1)*64 - 30,p*64);
             if (khay->str[p][l] == 'M' || khay->str[p][l+1] == 'M')
                khay->str[p][l+1] = '0';
        }
        else if (khay->me == 0)
        {
         khay->vec =  mlx_xpm_file_to_image(khay->mlx, "./vector1.xpm", &(khay->img_width), &(khay->img_height));
            mlx_put_image_to_window(khay->mlx, khay->mlx_win, khay->vec,(l-1)*64 - 30,p*64);
            if (khay->str[p][l] == 'M' || khay->str[p][l-1] == 'M')
            khay->str[p][l-1] = '0';
        } 
    }
     else if (ev == 53)
        exit(0);
    if (khay->str[i][j] && khay->str[i][j] != '1')
    {
        if (khay->str[i][j] == 'M')
            exit(0);
       if (khay->str[i][j] != 'E')
       {
        khay->str[khay->i][khay->j]= '0';
         khay->str[i][j]= 'P';
         khay->i = i;
         khay->j = j;
       }
        if (sersh_coli(khay->str) == 0)
        {
            khay->ex =  mlx_xpm_file_to_image(khay->mlx, "./exit1.xpm", &(khay->img_width), &(khay->img_height));
            if (khay->str[i][j] == 'E')
                exit(0);
        }
    }
    return 0;
}
int ft_sersh(char *str)
{
    int i = 0;
    int j;
    if (!str)
        return (-1);
    j = ft_strlen(str);
    if (str[0] == '\n')
        return (-1);
    if (str[j -1] == '\n')
        return (-1);
    while (str[i])
    {
        if (str[i] == '\n' && str[i + 1] == '\n')
            return (-1);
        i++;
    }
    return (0);
    
}
void anime(t_solong *khay)
{
    
    if ((khay->t == 3) || (khay->t == 6)||(khay->t == 9))
    {
       if(khay->movee[6] == '5')
            khay->movee[6] = '1';
        else
            khay->movee[6] +=1;
        khay->move = mlx_xpm_file_to_image(khay->mlx, khay->movee, &(khay->img_width), &(khay->img_height));
        if(khay->coll[6] == '6')
            khay->coll[6] = '1';
        else
            khay->coll[6] +=1;
        khay->col = mlx_xpm_file_to_image(khay->mlx, khay->coll, &(khay->img_width), &(khay->img_height));
        if (khay->monster[16] == '9' && khay->monster[15] == '0')
        {
            khay->monster[15] = '1';
            khay->monster[16] = '0';
        }
        else if (khay->monster[16] == '9' && khay->monster[15] == '1')
        {
            khay->monster[15] = '0';
            khay->monster[16] = '1';
        }
        else
        khay->monster[16] += 1;
        khay->mons = mlx_xpm_file_to_image(khay->mlx, khay->monster, &(khay->img_width), &(khay->img_height));
        if (khay->t == 9) 
            khay->t = 0;
    }
}
int key(t_solong *khay)
{
    mlx_clear_window(khay->mlx,khay->mlx_win);

    if (khay->t <= 9)
        khay->t +=1;
    anime(khay);
    ft_afichage(khay);
    return 0;
}
void so_long(char **str)
{
    t_solong khay;
    khay.coll =ft_strdup("./col11.xpm");
    khay.movee =ft_strdup("./move1.xpm");
    khay.monster= ft_strdup("./monster/nebta01.xpm");
    int i = 0;
    int j;
    khay.t = 0;
    khay.str = str;
    khay.c = 0;
    khay.k = 1;
    khay.me = 3;
     while (khay.str[i] != NULL)
        i++;
    j = ft_strlen(khay.str[0]);
    khay.img_width = 64;
    khay.img_height = 64;
    khay.str = str;
    khay.mlx = mlx_init();
    khay.mlx_win = mlx_new_window(khay.mlx, j * 64, i * 64, "Hello world!");
    khay.pla = mlx_xpm_file_to_image(khay.mlx, "./pla1.xpm", &(khay.img_width), &(khay.img_height));
    khay.ex = mlx_xpm_file_to_image(khay.mlx, "./exit.xpm", &(khay.img_width), &(khay.img_height));
    khay.col = mlx_xpm_file_to_image(khay.mlx, khay.coll, &(khay.img_width), &(khay.img_height));
    khay.move =mlx_xpm_file_to_image(khay.mlx, khay.movee, &(khay.img_width), &(khay.img_height));
    khay.wall = mlx_xpm_file_to_image(khay.mlx, "./wall.xpm", &(khay.img_width), &(khay.img_height));
    khay.spa= mlx_xpm_file_to_image(khay.mlx, "./space.xpm", &(khay.img_width), &(khay.img_height));
    khay.mons= mlx_xpm_file_to_image(khay.mlx, khay.monster, &(khay.img_width), &(khay.img_height));
    khay.vec =  mlx_xpm_file_to_image(khay.mlx, "./vector.xpm", &(khay.img_width), &(khay.img_height));
    khay.i = ft_sersh_playr(khay.str, 0,'P');
    khay.j = ft_sersh_playr(khay.str, 1,'P');
    ft_afichage(&khay);
    mlx_hook(khay.mlx_win,2,0, key_hook, &khay);
    mlx_loop_hook(khay.mlx, key, &khay);
	mlx_loop(khay.mlx);
}
int main(int ac ,char **av)
{
    int fd;
    char *str;
    char *line;
    char **sp;
    char  **spc;
 
    if(ac <2)
        return 0;
    str = NULL;
    fd = open(av[1],O_RDWR);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        str = ft_strjoine(str,line);
    }
    sp = ft_split(str,'\n');
    spc= ft_split(str, '\n');
    if (sp == NULL)
        return (write(1,"empty map",9),0);
    if (ft_sersh(str) == -1)
        return (write(1,"the map contains a plus line",29),0);
   if (ft_check_map(spc) == 0)
    so_long(sp);
}