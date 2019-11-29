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
 * @file grafo.cpp
 * @brief Archivo con los metodos utilizados para la biblioteca grafo.hpp
 * @author AbrahamRH
 * @version 1.0
 * @date 2019-11-27
 */


#include "grafo.hpp"

namespace GraphDS
{
	Vertex::Vertex( std::string _name ) : name{ _name }
	{
		// nada (por el momento)names

	}

	void Vertex::add_neighbor( Vertex v )
	{
		this->neighbors.push_back( v );
	}

	std::string Vertex::get_name() const
	{
		return this->name;
	}

	void Vertex::print_neighbors()
	{
		for( auto v : this->neighbors )
			std::cout << v.get_name() << "-> ";
		std::cout << "Nil";
	}

	void Vertex::set_color( Vertex::Colors color)
	{
		this->color = color;
	}

	void Vertex::set_predecesor( std::string predecesor )
	{
		this->predecesor = predecesor;
	}

	void Vertex::set_valencia( int numero )
	{
		this->electronesValencia = numero;
	}

	void Vertex::set_electronegativad( float numero )
	{
		this->electronegatividad = numero;
	}

	float Vertex::get_electronegatividad()
	{
		return this->electronegatividad;
	}

	int Vertex::get_valencia()
	{
		return this->electronesValencia;
	}

	int Vertex::get_electronesDisponibles()
	{
		return this->electronesDisponibles;
	}

	void Vertex::disminuirElectrones( int numero )
	{
		this->electronesDisponibles-= numero;
	}

	Vertex::Colors Vertex::get_color()
	{
		return this->color;
	}

	std::string Vertex::get_predecesor()
	{
		return this->predecesor;
	}

	std::list<Vertex> Vertex::get_neighbors(){
		return this->neighbors;
	}

	void Vertex::print()
	{
		std::cout << "\nName: "     << this->get_name() << std::endl;
		std::cout << "Predecesor: " << this->get_predecesor() << std::endl;
		std::string color_as_string;

		switch( this->color ){
			case Vertex::Colors::BLACK: color_as_string = "BLACK"; break;
			case Vertex::Colors::GRAY:  color_as_string = "GRAY";  break;
			case Vertex::Colors::WHITE: color_as_string = "WHITE"; break;
		}

		std::cout << "Color: " << color_as_string << std::endl;
	}

	Graph::Graph()
	{
		// nada (por el momento)
	}

	bool Graph::add_vertex( Vertex v )
	{
		auto ret = vertices.insert( { v.get_name(), v } );
		// 'map' no permite duplicados, así que no hay necesidad de buscarlos

		return ret.second;
	}

	bool Graph::add_edge( std::string edge1, std::string edge2 )
	{
		bool res = false;
		// uno, o ambos nodos, no existen

		auto v1 = this->vertices.find( edge1 );
		auto v2 = this->vertices.find( edge2 );

		if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

			v1->second.add_neighbor( v2->second );
			v2->second.add_neighbor( v1->second );

			return true;
		}

		return res;
	}

	Vertex* Graph::get_vertex( std::string name){
		return &this->vertices.find(name)->second;
	}



	void Graph::print()
	{
		for( auto v : this->vertices ){
			std::cout << "\n" << v.second.get_name() << ": ";
			v.second.print_neighbors();
		}
		std::cout << "\n";
	}

	void Graph::BFS(Vertex* start)
	{
		start->set_color(Vertex::Colors::WHITE);
		std::list<Vertex*> queue;
		queue.push_back(start);

		while ( !queue.empty() ){

			Vertex* vertex = queue.front();
			queue.pop_front();

			for ( auto neighbors : vertex->get_neighbors() ){

				/*Se utilza el nombre de los vecinos para poder acceder a ese
				  vertex por medio de get_vertex que devuelve un apuntador y no su copia*/

				Vertex* neighbor = this->get_vertex(neighbors.get_name());

				if( neighbor->get_color() == Vertex::Colors::BLACK ){
					neighbor->set_color(Vertex::Colors::GRAY);
					neighbor->set_predecesor(vertex->get_name());
					neighbor->set_color(Vertex::Colors::WHITE);
					queue.push_back(neighbor);
				}
			}
			vertex->set_color(Vertex::Colors::WHITE);
		}

		//Impresión del contenido de los nodos del grafo
		for( auto v : this->vertices ){
			v.second.print();
		}
	}

}
