/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_grading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:48:29 by liovino           #+#    #+#             */
/*   Updated: 2025/02/01 22:56:09 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Per avere un passaggio tra colori più smooth e rendere tutto meno 
// un pugno nell'occhio bisogna aggiungere dei "colori intermedi".

// Per fare ciò, ti tocca usare la "linear interpolation" su
// ogni componente del colore (separatamente per r, g, b)...
// Finalmente puoi usare la struct!!

// Formula:
// inter_val = start_val + ((step/tot_step) * (end_val - start_val))

// Super simile a scaling() !!!

// Da decidere quanti step intermedi fare tra un colore significativamente
// diverso e l'altro.

// Buonanotte <33