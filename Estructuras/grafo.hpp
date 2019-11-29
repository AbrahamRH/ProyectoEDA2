/* Copyright (C)
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
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
 * @file grafo.hpp
 * @brief Biblioteca estática con las declaraciones de clases y sus métodos implemetados en un namespace
 * @author AbrahamRH
 * @version 1.2
 * @date 2019-11-27
 */

#include <iostream>

#include <string>

#include <list>

#include <map>

#include <array>

#include <algorithm>

#include <vector>

namespace GraphDS
{

	//----------------------------------------------------------------------
	//  Class Vertex
	//----------------------------------------------------------------------
	class Vertex
	{
	public:
		enum class Colors { BLACK, GRAY, WHITE };

	private:

		std::string name;				///< Nombre del elemento. Se utilizará como key

		std::string Simbolo;			///< Simbolo del elemento

		int electronesValencia;			///< Electrones de Valencia

		int electronesDisponibles;		///< Electrones disponibles

		float electronegatividad;		///< Electronegatividad

		std::list<Vertex> neighbors; 	///< lista de vértices adyacentes

		Colors color{ Colors::BLACK };	///< Color del vértice

		std::string  predecesor;		///< Nombre del vértice predecesor

	public:

		/* -------------------------------*/
		/**
		 * @brief Constructor de la clase Vertex
		 *
		 * @param name Nombre para inicializar el vértice
		 */
		/* -------------------------------*/
		Vertex( std::string name );

		/* -------------------------------*/
		/**
		 * @brief Método para obtener el nombre del vértice
		 *
		 * @return
		 */
		/* -------------------------------*/
		std::string get_name() const;

		/* -------------------------------*/
		/**
		 * @brief Método ppara agregar un nodo vecino a la lista del vértice
		 *
		 * @param v Vértice agregado a la lista
		 */
		/* -------------------------------*/
		void add_neighbor( Vertex v );

		/* -------------------------------*/
		/**
		 * @brief Método para imprimir los nodos vecinos al vértice
		 */
		/* -------------------------------*/
		void print_neighbors();

		//Setters

		/* -------------------------------*/
		/**
		 * @brief Método para asignar un color al vértice
		 *
		 * @param color Color ( estado ) asignado
		 */
		/* -------------------------------*/
		void set_color( Vertex::Colors color );

		/* -------------------------------*/
		/**
		 * @brief Método para asignar el predecesor al vértice
		 *
		 * @param predecesor Nombre del vértice predecesor
		 */
		/* -------------------------------*/
		void set_predecesor( std::string predecesor );

		/* -------------------------------*/
		/**
		 * @brief Método para asignar los electrones de valencia
		 *
		 * @param numero Número asignado
		 */
		/* -------------------------------*/
		void set_valencia( int numero );

		/* -------------------------------*/
		/**
		 * @brief Método para asignar los electrones de valencia
		 *
		 * @param numero Número asignado
		 */
		/* -------------------------------*/
		void set_electronegativad( float numero );

		//Getters

		/* -------------------------------*/
		/**
		 * @brief Método para obtener el color (estado) de un vértice
		 *
		 * @return Color ( estado ) de un vértice
		 */
		/* -------------------------------*/
		Colors get_color();

		/* -------------------------------*/
		/**
		 * @brief Método para obtener el predecesor a un vértice
		 *
		 * @return Nombre del predecesor al vértice
		 */
		/* -------------------------------*/
		std::string get_predecesor();

		/* -------------------------------*/
		/**
		 * @brief Método para obtener los vecinos de un vértice
		 *
		 * @return Lista con los vecinos de un vértice
		 */
		/* -------------------------------*/
		std::list<Vertex> get_neighbors();

		/* -------------------------------*/
		/**
		 * @brief Método para obtener el numero electrones de valencia
		 *
		 * @return Electrones de valencia
		 */
		/* -------------------------------*/
		int get_valencia();

		/* -------------------------------*/
		/**
		 * @brief Método para obtener el numero de electronegatividad
		 *
		 * @return Electronegatividad
		 */
		/* -------------------------------*/
		float get_electronegatividad();

		/* -------------------------------*/
		/**
		 * @brief Método para obtener el numero de electrones disponibles
		 *
		 * @return electronesDisponibles
		 */
		/* -------------------------------*/
		int get_electronesDisponibles();

		/* -------------------------------*/
		/**
		 * @brief Método para disminuir el numero de electrones disponibles
		 *
		 * @param electrones a disminuir
		 */
		/* -------------------------------*/
		void disminuirElectrones( int numero );

		/* -------------------------------*/
		/**
		 * @brief Método para imprimir el contendo de un vértice
		 */
		/* -------------------------------*/
		void print();
	};

	//----------------------------------------------------------------------
	//  Class Graph
	//----------------------------------------------------------------------
	class Graph
	{
	private:
		// asociamos un vértice (value) a una cadena (key):
		// vertices[ string ] = a_vertex
		std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo

	public:
		/* -------------------------------*/
		/**
		 * @brief Constructor de la clase Graph
		 */
		/* -------------------------------*/
		Graph();

		/* -------------------------------*/
		/**
		 * @brief Método para agregar un vértice al grafo
		 *
		 * @param v Vétice que sera agregado al grafo
		 *
		 * @return True: Si se agrego el vértice al grafo False: en caso contrario
		 */
		/* -------------------------------*/
		bool add_vertex( Vertex v );

		/* -------------------------------*/
		/**
		 * @brief Método para agregar las aristas a los vértices
		 *
		 * @param edge1 Nodo de la arista
		 * @param edge2 Nodo de la arista
		 *
		 * @return True: si se agrego la arista False: en caso contrario
		 */
		/* -------------------------------*/
		bool add_edge( std::string edge1, std::string edge2 );

		/* -------------------------------*/
		/**
		 * @brief Método ara la impresión del grafo
		 */
		/* -------------------------------*/
		void print();

		/* -------------------------------*/
		/**
		 * @brief Algoritmo para el recorrido del grafo Breadth-first search
		 *
		 * @param start Apuntador al vértice de inicio del recorrido
		 */
		/* -------------------------------*/
		void BFS( Vertex* start );

		/* -------------------------------*/
		/**
		 * @brief Método para obtener un vértice del grafo
		 *
		 * @param name Nombre del vértice que se desea obtener
		 *
		 * @return Apuntador a el vértice
		 */
		/* -------------------------------*/
		Vertex* get_vertex( std::string name);

	};
}
