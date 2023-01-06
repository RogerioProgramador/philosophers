/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:58:04 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/12/27 18:26:02 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	has_alpha(int argc, char **argv)
{
    int word;
    int letter;

    word = 0;
    letter = 0;
    while (++word < argc)
    {
        while (argv[word][letter])
        {
            if (!is_digit(argv[word][letter++]))
                return (1);
        }
        letter = 0;
    }
	return (0);
}

int is_valid(int argc, char **argv)
{
	if (argc < 5 || argc > 6 || !argv)
		return (0);
	else if (has_alpha(argc, argv))
		return (0);
	else
		return(1);
}
