/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:41:40 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/12/28 21:24:07 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#include <stdio.h>

void    *rotina_teste(void *param)
{
    *(int *)param = *(int *)param + 1;
    int number = *(int *)param;

    printf("Filósofo numero %i está aqui\n", number);
    pthread_exit(0);
}

void run(t_params *params)
{
    int i;
    pthread_t threads[params->number_of_philosophers];

    i = 0;
    while (i < params->number_of_philosophers)
    {
        pthread_create(&threads[i], NULL, rotina_teste, &i);
    }
}

/*
TODO:
    o i não funciona como eu penso, pois as threads são criadas muito rapidamente e ambas acessam
    a variavel com o valor que estiver na hora, tenho que fazer elas acessarem o i de forma ordenada.
    parece que esse mutex pode ajudar, para não deixar uma thread atrapalhar a outra
*/