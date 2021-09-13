#ifndef NODO_H
#define NODO_H

template< typename Tipo > class Lista;
template< typename Tipo >
class Nodo{
    friend class Lista< Tipo >;
    friend class cframe;
public:
    Nodo( const Tipo & );
    Tipo obtenerDatos() const;
private:
    Tipo datos;
    Nodo< Tipo > *siguientePtr;
};

template< typename Tipo >
Nodo< Tipo >::Nodo( const Tipo &info )
    : datos( info ), siguientePtr( 0 ){ }

template< typename Tipo >
Tipo Nodo< Tipo >::obtenerDatos() const
{
    return datos;
}

#endif
