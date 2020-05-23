/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** ai.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef AI_H
#define AI_H

typedef struct{
    int ind;
    float value;
} point_t;

typedef struct {
    int id;
    char * cmd;
    char * status;
    char * code_str;
    void * data;
    char * info;
    float lap;
    float track;
}response_t;


response_t * car_direction(float direction);
response_t * car_forward(float power);
response_t * car_backwards(float power);

void ai_driver();
response_t * n4s_pipe(char *cmd);
response_t *t(response_t *resp);
void str_to_resp_two(response_t *resp, int s);
point_t lidar_max(float * a);
#endif //AI_H
