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
 * @file Algoritmos.cpp
 * @brief Algoritmos de búsqueda y ordenamiento
 * @version 1.0
 * @date 2019-11-30
 */

#include "Algoritmos.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

void QuickSort( elemento* elementos[], int first, int last)
{
	//std::cout << "LLAMADA INICIAL: " << std::endl ;
	size_t mid = ( first + last ) / 2;
	elemento* piv = elementos[ mid ];
	//std::cout << "ASIGNAR PIVOTE: "<< std::endl ;
	int x0 = first;
	int x1 = last;

	//std::cout << "CICLO COMP: "<< x0 << x1 << std::endl ;
	while( x0 <= x1 ){
		//std::cout << x0 << std::endl << x1 << std::endl;

		//std::cout << "PRIMERA COMP: " << std::endl ;
		while( atof(elementos[ x0 ]->e_negatividad) > atof(piv->e_negatividad) )
			++x0;
		//std::cout << "SEGUNDA COMP: " << std::endl ;			
		while( atof(elementos[ x1 ]->e_negatividad) < atof(piv->e_negatividad) )
			--x1;

		//std::cout << "IF X0 <= X1 " << std::endl ;
		if( x0 <= x1 ){

			//std::cout << "SWAP: " << std::endl ;
			swap( elementos[x0], elementos[x1] );
			
			++x0;
			--x1;
		}
	}
	
	if( first < x1){
		//std::cout << "LLAMADA REC IZQ: " << std::endl;
		QuickSort( elementos, first, x1 );
	}
		
	
	if( x0 < last ){
		//std::cout << "LLAMADA REC DER: " << std::endl;
		QuickSort( elementos, x0, last );
	}
		
}

void swap(elemento* x ,elemento* y)
{
	elemento tmp;
	tmp = *x;
	*x  = *y;
	*y  = tmp;
}

//HAY QUE AGREGAR UN CRITERIO DE COMPARACION AQUI.
bool BusquedaBinariaR(std::vector<elemento*> elementos, size_t inf, size_t sup, elemento* key, size_t* index)
{
    size_t centro = (sup + inf)/2;
    bool found = false;

    if( elementos[ centro ] == key ){
		*index = centro;
		found = true;
    }
    if( sup == inf)
		return false;

    if( key < elementos[ centro ] )
		found = BusquedaBinariaR( elementos, inf, centro, key, index);
    else if( elementos[ centro ] > key )
		found = BusquedaBinariaR( elementos, centro + 1, sup, key, index);

    return found;
}


bool BusquedaBinaria(std::vector<elemento*> elementos, size_t len, elemento key, size_t* index)
{
    return BusquedaBinariaR( elementos, 0, len, &key, index);
}

