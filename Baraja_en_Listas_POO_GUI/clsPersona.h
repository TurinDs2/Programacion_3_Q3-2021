#ifndef CLSPERSONA_H
#define CLSPERSONA_H
#include <clsCasino.h>

class clsPersona : public clsCasino
{
private:
    char *Id = new char[15];
    string Nomb;
    char Gen;
    short Edad;
public:
    clsPersona();
    clsPersona(char *Id, const string &Nomb, char Gen, short Edad);
    ~clsPersona();
    void setId(char *Id);
    char *getId() const;
    void setNomb(const string &Nomb);
    const string &getNomb() const;
    void setGen(char Gen);
    char getGen() const;
    void setEdad(short Edad);
    short getEdad() const;
    virtual void Mostrar() = 0;
    virtual void Leer();
    virtual void LeerGUI();
};

#endif // CLSPERSONA_H
