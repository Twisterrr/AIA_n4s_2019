/*
** EPITECH PROJECT, 2020
** ai
** File description:
** ai
*/

#include "../include/ai.h"
#include <math.h>

enum lidar
{
    lidar_left = 0, lidar_right = 31, lidar_center = 16, lidar_inf = 3010
};

float straight(float left, float right, float center, point_t *max)
{
    return .5 * (pow((double) (left / max->value), (double) 2) - pow((double) \
    (right / max->value), (double) (2)));
}

float curve(float left, float right, float center, point_t *max)
{
    float c;
    if (center > 410) c = -(max->ind - 16.0) / 300.0;
    else c = -(max->ind - 16.0) / 40.0;

    if (left < center){c *= 500.0 / left;}
    if (right < center){c *= 500.0 / right;}
    return c;
}

float stearing(float *r)
{
    float dir;
    float left = r[lidar_left];
    float right = r[lidar_right];
    float center = r[lidar_center];
    point_t max = lidar_max(r);

    if (left < max.value && right < max.value)
        dir = straight(left, right, center, &max);
    else
        dir = curve(left, right, center, &max);
    return dir;
}

void ai_driver(void)
{
    while (1) {
        response_t *str = n4s_pipe("GET_INFO_LIDAR\n");
        if (!str) break;
        response_t *ret;
        static float dir1 = 0;
        float dir = stearing((float *) str->data);
        dir = (dir + dir1) / 2.0;
        ret = car_direction(dir);
        if (!ret) break;
        free(ret);
        dir1 = dir;
        float power = 1.2 * ((float *) str->data)[lidar_center] / lidar_inf;
        ret = car_forward(power);
        if (!ret) break;
        free(ret);
        free(str);
    }
}
