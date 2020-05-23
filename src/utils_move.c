/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** utils_move
*/

#include "../include/ai.h"
#include <math.h>

response_t *t(response_t *resp)
{
    if (*resp->info == 'L' )
        fprintf(stderr, "Lap %f\n", atof(resp->info + 17));
    if (*resp->info == 'T' ) {
        resp->track = atof(resp->info + 19);
        fprintf(stderr, "Track %f\n", resp->track);
        free (resp);
        return NULL;
    }
    return resp;
}

void str_to_resp_two(response_t *resp, int s)
{
    if (s >= 35) {
        float *arr = malloc(sizeof(float) * 32);
        for (int i = 0; i < 32; i++)
            arr[i] = atof(strtok(NULL, ":"));
        resp->data = arr;
    }
}