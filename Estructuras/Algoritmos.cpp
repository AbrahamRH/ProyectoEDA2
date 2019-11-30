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

void QuickSort( int elementos[], size_t first, size_t last)
{
	size_t mid = ( first + last ) / 2;
	int piv = elementos[ mid ];
	size_t x0 = first;
	size_t x1 = last;

	while( x0 <= x1 ){
		while( elementos[ x0 ] < piv )
			++x0;
		while( elementos[ x1 ] > piv )
			--x1;
		if( x0 <= x1 ){
			swap( &elementos[ x0 ], &elementos[ x1 ] );
			++x0;
			--x1;
		}
	}
	if( first < x1)
		QuickSort( elementos, first, x1 );
	if( x0 < last )
		QuickSort( elementos, x0, last );
}

void swap(int* x ,int* y)
{
	int tmp;
	tmp = *x;
	*x  = *y;
	*y  = tmp;
}


bool BusquedaBinariaR(int elementos[], size_t inf, size_t sup, int* key, size_t* index)
{
    size_t centro = (sup + inf)/2;
    bool found = false;

    if( elementos[ centro ] == *key ){
		*index = centro;
		found = true;
    }
    if( sup == inf)
		return false;

    if( *key < elementos[ centro ] )
		found = BusquedaBinariaR( elementos, inf, centro, key, index);
    else if( elementos[ centro ] > *key )
		found = BusquedaBinariaR( elementos, centro + 1, sup, key, index);

    return found;
}


bool BusquedaBinaria(int elementos[], size_t len, int key, size_t* index)
{
    return BusquedaBinariaR( elementos, 0, len, &key, index);
}

