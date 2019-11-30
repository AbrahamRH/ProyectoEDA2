/* Copyright (C)
 * 2019 - AbrahamRH
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/**
 * @file Algoritmos.hpp
 * @brief Biblioteca estática con las declaraciones de las funciones de los algoritmos
 * @version 1.0
 * @date 2019-11-30
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


/* -------------------------------*/
/**
 * @brief Algoritmo de ordenamiento quicksort
 *
 * @param elementos[] Colección de elementos a ordenar
 * @param first Indice a la primer posición de arreglo
 * @param last  Indice a la posición final del arreglo
 */
/* -------------------------------*/
void QuickSort(int elementos[] ,size_t first, size_t last);

/* -------------------------------*/
/**
 * @brief Función para el intercambio de contenido de dos variables
 *
 * @param x Variable a intercambiar 1
 * @param y Variable a intercambiar 2
 */
/* -------------------------------*/
void swap(int* x , int* y);

/* -------------------------------*/
/**
 * @brief Función de activación para la función de búsqueda binaria recursiva
 *
 * @param elementos[] Colección de elementos en la que se realizara la búsqueda
 * @param len Tamaño de la coleccón de elementos
 * @param key Elemento que se va a buscar
 * @param index Indice de la posición del elemento si se encuentra
 *
 * @return True: Si el elemento fue encontrado. False: en caso contrario
 */
/* -------------------------------*/
bool BusquedaBinaria(int elementos[], size_t len, int key, size_t* index);

/* -------------------------------*/
/**
 * @brief Función de busqueda binaria recursiva
 *
 * @param elementos[] Colección de elementos en la que se realizara la búsqueda
 * @param inf Indice inferior del segmento en el que se realizara la búsqueda
 * @param sup Indice superior del segmento en el que se realizara la búsqueda
 * @param key Elemento que se va a buscar
 * @param index Indice de la posición del elemento si se encuentra
 *
 * @return True: Si el elemento fue encontrado. False: en caso contrario

 */
/* -------------------------------*/
bool BusquedaBinariaR(int elementos[], size_t inf, size_t sup, char* key, size_t* index);

