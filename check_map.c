/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:11:38 by yakhay            #+#    #+#             */
/*   Updated: 2023/01/15 15:39:03 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct	valid
{
	int			E;
	int			C;
    int			P;
    int c;
    int l;
    int k;
}				t_valid;

int ft_check_wall_valid(char **sp)
{
    int i = 0;
    int j;
    while(sp[i])
    {
        j =0;
        while(sp[i][j])
        {
            if(sp[i][j] == 'C')
                return(-1);
            else if (sp[i][j] == 'P')
                return (-1);
            else if (sp[i][j] == 'E')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}
void flood_fill(char **str, int x, int y)
{
     if (str[x][y] == 'C')
           str[x][y]  = '1';
        else if (str[x][y]  == 'P')
            str[x][y] = '1';
        else if (str[x][y] == 'E')
        {
            str[x][y] = 'e';
            return ;
        }
        else if (str[x][y] == '0')
            str[x][y] = '1';
        if (str[x-1][y] != '1')
            flood_fill(str,x - 1,y);
        if (str[x+1][y] != '1' )
            flood_fill(str,x + 1,y);
        if (str[x][y - 1] != '1')
            flood_fill(str,x,y-1);
        if (str[x][y + 1] != '1')
            flood_fill(str,x,y +1);
        if (str[x][y + 1] == '1' && str[x][y - 1] == '1' && str[x+1][y] == '1' && str[x-1][y] == '1')
            return;
}
int ft_count_collectible_exit_player(int E,int C, int P)
{
    if (E != 1 || C < 1 || P != 1)
        return -1;
    return 0;
}
int ft_check_map(char **sp)
{
    int i;
    int j;
    t_valid lst;
   
    lst.C = 0;
    lst.P = 0;
    lst.E = 0;
    i = 0;
    j = 0;
    lst.k = ft_strlen(sp[i]);
    while(sp[i])
    {
        j = 0;
        if (i == 0 || sp[i + 1] == NULL)
        {
            while(sp[i][j] == '1')
                j++;
            if( lst.k != j || sp[i][j] == '0')
                return (write(2,"num of line not equal or  line  have 0",38),-1);
        }
        j = 0;
        while(sp[i] && sp[i][j])
        {
            lst.k = ft_strlen(sp[i]);
            if (sp[i][0] != '1' || sp[i][lst.k - 1] != '1')
                return(write(2,"the map is missing a wall",26),-1);
            if (sp[i][j] == 'C')
                lst.C++;
            else if (sp[i][j] == 'P')
            {
                lst.P++;
                lst.c = i;
                lst.l = j;
            }
            else if (sp[i][j]== 'E')
                lst.E++;
            else if (sp[i][j]== 'M')
                lst.C++;
            else if (sp[i][j] && sp[i][j] != '0' && sp[i][j] != '1')
                return (write(2,"the map contains an item no valid",33),-1);
            j++;
        }
        i++;
    }
    if(ft_count_collectible_exit_player(lst.E,lst.C,lst.P) == -1)
        return (write(2,"count collectible exit player not valid",40),-1);
    flood_fill(sp, lst.c, lst.l);
    if (ft_check_wall_valid(sp) == -1)
        return (write(2,"walled element",14),-1);
    return (0);
}