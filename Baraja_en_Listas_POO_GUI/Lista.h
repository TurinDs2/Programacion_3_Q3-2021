#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <clsCasino.h>
using std::cout;
#include "Nodo.h" // definición de la clase Nodo

template< typename Tipo >
class Lista{
    friend class cframe;
public:
    Lista();
    ~Lista();
    void insertarAlFrente( const Tipo & );
    void insertarAl3er( const Tipo & );
    void insertarAlFinal( const Tipo & );
    bool eliminarDelFrente( Tipo & );
    bool eliminarDel3er( Tipo & );
    bool eliminarDelFinal( Tipo & );
    bool estaVacia() const;
    void imprimir() const;
private:
    Nodo< Tipo > *primeroPtr;
    Nodo< Tipo > *ultimoPtr;
    Nodo< Tipo > *obtenerNuevoNodo( const Tipo & );
};

template< typename Tipo >
Lista< Tipo >::Lista()
    : primeroPtr( 0 ), ultimoPtr( 0 ){ }

template< typename Tipo >
Lista< Tipo >::~Lista(){
    if ( !estaVacia() ){
        cout << "Destruyendo nodos ...\n";
        Nodo< Tipo > *actualPtr = primeroPtr;
        Nodo< Tipo > *tempPtr;
        while ( actualPtr != 0 ){ // elimina los nodos restantes
            tempPtr = actualPtr;
            cout << tempPtr->datos << "\t";
            actualPtr = actualPtr->siguientePtr;
            delete tempPtr;
        } // fin de while
    } // fin de if
    cout << "Se destruyeron todos los nodos\n\n";
}


template< typename Tipo >
void Lista< Tipo >::insertarAlFrente( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor ); // nuevo nodo
    if ( estaVacia() )
        primeroPtr = ultimoPtr = nuevoPtr;
    else{
        nuevoPtr->siguientePtr = primeroPtr;
        primeroPtr = nuevoPtr;
    }
}

template< typename Tipo >
void Lista< Tipo >::insertarAl3er( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        primeroPtr = ultimoPtr = nuevoPtr;
    else if( primeroPtr==ultimoPtr ){
        ultimoPtr->siguientePtr = nuevoPtr;
        ultimoPtr = nuevoPtr;
    }else if( primeroPtr->siguientePtr==ultimoPtr ){
        ultimoPtr->siguientePtr = nuevoPtr;
        ultimoPtr = nuevoPtr;
    }else{
        nuevoPtr->siguientePtr = primeroPtr->siguientePtr->siguientePtr;
        primeroPtr->siguientePtr->siguientePtr = nuevoPtr;
    }
}

template< typename Tipo >
void Lista< Tipo >::insertarAlFinal( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        primeroPtr = ultimoPtr = nuevoPtr;
    else{
        ultimoPtr->siguientePtr = nuevoPtr;
        ultimoPtr = nuevoPtr;
    }
}


template< typename Tipo >
bool Lista< Tipo >::eliminarDelFrente( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        Nodo< Tipo > *tempPtr = primeroPtr;
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0;
        else
            primeroPtr = primeroPtr->siguientePtr;
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

template<typename Tipo>
bool Lista<Tipo>::eliminarDel3er(Tipo &valor)
{
    if ( estaVacia() ){
        return false;
    }else{
        Nodo< Tipo > *tempPtr;
        if( primeroPtr==ultimoPtr ){
            tempPtr = primeroPtr;
            primeroPtr = ultimoPtr = 0;
        }else if( primeroPtr->siguientePtr==ultimoPtr ){
            tempPtr = primeroPtr->siguientePtr;
            ultimoPtr = primeroPtr;
            primeroPtr->siguientePtr = 0;
        }else{
            tempPtr = primeroPtr->siguientePtr->siguientePtr;
            if( primeroPtr->siguientePtr->siguientePtr==ultimoPtr ){
                ultimoPtr = primeroPtr->siguientePtr;
            }
            primeroPtr->siguientePtr->siguientePtr = primeroPtr->siguientePtr->siguientePtr->siguientePtr;
        }
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

template< typename Tipo >
bool Lista< Tipo >::eliminarDelFinal( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        Nodo< Tipo > *tempPtr = ultimoPtr;
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0;
        else{
            Nodo< Tipo > *actualPtr = primeroPtr;
            // localiza el penúltimo elemento
            while ( actualPtr->siguientePtr != ultimoPtr )
                actualPtr = actualPtr->siguientePtr;
            ultimoPtr = actualPtr;
            actualPtr->siguientePtr = 0;
        } // fin de else
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

template< typename Tipo >
bool Lista< Tipo >::estaVacia() const{
    return primeroPtr == 0;
}


template< typename Tipo >
Nodo< Tipo > *Lista< Tipo >::obtenerNuevoNodo(const Tipo &valor ){
    return new Nodo< Tipo >( valor );
}


template< typename Tipo >
void Lista< Tipo >::imprimir() const{
    if ( estaVacia() ) {
        cout << "La lista esta vacia\n\n";
        return;
    }
    Nodo< Tipo > *actualPtr = primeroPtr;
    cout << "La lista es: ";
    while ( actualPtr != 0 ) {
        if( typeid (actualPtr->datos)==typeid (clsCasino*) ){
            actualPtr->datos->Mostrar();
        }else{
            cout << actualPtr->datos << "\t";
        }
        actualPtr = actualPtr->siguientePtr;
    }
    cout << "\n\n";
}

#endif
