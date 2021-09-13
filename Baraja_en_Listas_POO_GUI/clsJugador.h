#ifndef CLSJUGADOR_H
#define CLSJUGADOR_H
#include <clsPersona.h>

class clsJugador : public clsPersona
{
private:
    float TotFichas;
    float Apuesta;
    vector <clsCarta> Cartas;//para el Juego
public:
    clsJugador();
    clsJugador(char *Id, const string &Nomb, char Gen, short Edad, float TotFichas, float Apuesta);
    ~clsJugador();
    void setTotFichas(float TotFichas);
    void setApuesta(float Apuesta);
    float getTotFichas() const;
    float getApuesta() const;
    virtual void Mostrar();
    virtual void Leer();
    virtual void LeerGUI();
};

#endif // CLSJUGADOR_H
