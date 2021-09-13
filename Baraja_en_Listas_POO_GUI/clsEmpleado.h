#ifndef CLSEMPLEADO_H
#define CLSEMPLEADO_H
#include <clsPersona.h>

class clsEmpleado : public clsPersona
{
private:
    string Puesto;
    float Salario;
public:
    clsEmpleado();
    clsEmpleado(char *Id, const string &Nomb, char Gen, short Edad, const string &Puesto, float Salario);
    ~clsEmpleado();
    const string &getPuesto() const;
    void setPuesto(const string &Puesto);
    float getSalario() const;
    void setSalario(float Salario);
    virtual void Mostrar();
    virtual void Leer();
    virtual void LeerGUI();
};

#endif // CLSEMPLEADO_H
