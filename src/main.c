/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** main
*/

#include "../include/ai.h"

int main(int ac, char **av)
{
    char *res;
    float left;
    float right;
    char cmd[40] = {0};

    n4s_pipe("START_SIMULATION\n");
    ai_driver();
    car_forward(0);
    n4s_pipe("STOP_SIMULATION\n");
    return 0;
}
