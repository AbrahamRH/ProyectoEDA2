

#include <iostream>

#include <string>

#include <list>

#include <map>

#include <array>

#include <algorithm>

#include <vector>

//----------------------------------------------------------------------
//  Class Vertex
//----------------------------------------------------------------------
class Vertex
{
public:
	enum class Colors { BLACK, GRAY, WHITE };

private:
	std::string name; ///< campo de texto. Se utilizará como key

	// aquí van más campos relacionados con la naturaleza de la información del
	// nodo. P. ej., Estudiante: promedio, semestre. Persona: dirección, edad;
	// etc.

	std::string Simbolo;

	int numeroAtomico;

	std::list<Vertex> neighbors; ///< lista de vértices adyacentes

	Colors color{ Colors::BLACK };

	std::string  predecesor;

public:

	Vertex( std::string name );

	std::string get_name() const;

	void add_neighbor( Vertex v );

	void print_neighbors();

	//Métodos agregados
	//Setters

	void set_color( Vertex::Colors color );

	void set_predecesor( std::string predecesor );

	void set_numero_atomico( int numero );

	void set_nombre( std::string nombre );

	//Getters

	int get_distance();

	Colors get_color();

	std::string get_predecesor();

	std::list<Vertex> get_neighbors();


	/* -------------------------------*/
	/**
	 * @Synopsis Método para imprimir el contendo de un vértice
	 */
	/* -------------------------------*/
	void print();
};

Vertex::Vertex( std::string _name ) : name{ _name }
{
	// nada (por el momento)
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

//Setters

void Vertex::set_color( Vertex::Colors color)
{
	this->color = color;
}

void Vertex::set_predecesor( std::string predecesor )
{
	this->predecesor = predecesor;
}


//Getters

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




//----------------------------------------------------------------------
//  Class Graph
//----------------------------------------------------------------------
class Graph
{
private:
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex

public:
	Graph();
//	Graph( std::vector<Vertex> vertices );

	bool add_vertex( Vertex v );

	bool add_edge( std::string edge1, std::string edge2 );

	void print();

	void BFS(Vertex* start);

	Vertex* get_vertex( std::string name);

};

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


//Devuelve un apuntador a un vértice del grafo
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


int main()
{
	Graph g;
	g.add_vertex( Vertex( "A" ) );
	g.add_vertex( Vertex( "B" ) );
	g.add_vertex( Vertex( "C" ) );
	g.add_vertex( Vertex( "D" ) );
	g.add_vertex( Vertex( "E" ) );
	g.add_vertex( Vertex( "F" ) );
	g.add_vertex( Vertex( "G" ) );
	g.add_vertex( Vertex( "H" ) );
	g.add_vertex( Vertex( "I" ) );
	g.add_vertex( Vertex( "J" ) );


	g.add_edge( "A", "B" );
	g.add_edge( "B", "F" );
	g.add_edge( "F", "G" );
	g.add_edge( "F", "I" );
	g.add_edge( "G", "C" );
	g.add_edge( "G", "J" );
	g.add_edge( "J", "F" );
	g.add_edge( "I", "H" );
	g.add_edge( "H", "D" );
	g.add_edge( "D", "E" );
	g.add_edge( "E", "H" );
	g.add_edge( "E", "A" );

	g.print();
	g.BFS(g.get_vertex("A"));

}
