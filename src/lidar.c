/*
** EPITECH PROJECT, 2020
** lidar
** File description:
** ai
*/

#include "../include/ai.h"

point_t lidar_max(float *a)
{
    point_t max = {0};
    for (int i = 0; i < 32; i++)
        if (a[i] > max.value){
            max.value = a[i];
            max.ind = i;
        }
    return max;
}
