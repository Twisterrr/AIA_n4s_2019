/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** basic moves
*/

#include "../include/ai.h"
#include <math.h>

response_t *str_to_resp(char *str)
{
    int i = -1, s = 0;
    while (++i < strlen(str))
        if (str[i] == ':')
            s++;
    response_t *resp;
    resp = malloc(sizeof(response_t));
    resp->id = atoi(strtok(str, ":"));
    if (resp->id != 1) fprintf(stderr, "Response : %s", str);
    resp->status = strtok(NULL, ":");
    resp->code_str = strtok(NULL, ":");
    if (s == 3)
        resp->data = NULL;
    str_to_resp_two(resp, s);
    resp->info = strtok(NULL, "");
    if (*resp->info != 'N' )
        fprintf(stderr, "Info: %s", resp->info);
    return t(resp);
}

response_t *n4s_pipe(char *cmd)
{
    response_t *resp;
    char *str;
    size_t len = 0;
    write(1, cmd, strlen(cmd));
    getline(&str, &len, stdin);
    return str_to_resp(str);
}

response_t *car_direction(float dir)
{
    char buff[40] = {0};
    if (fabs(dir) > 1) dir /= dir;
    sprintf(buff, "wheels_dir:%.2f\n", dir);
    return n4s_pipe(buff);
}

response_t *car_forward(float power)
{
    if (power > 1) power = 1;
    char buff[40];
    sprintf(buff, "CAR_FORWARD:%.2f\n", power);
    return n4s_pipe(buff);
}

response_t *car_backwards(float power)
{
    if (power > 1) power = 1;
    char buff[40];
    sprintf(buff, "CAR_BACKWARDS:%.2f\n", power);
    return n4s_pipe(buff);
}

