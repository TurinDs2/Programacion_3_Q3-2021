#include "clsEmpleado.h"

clsEmpleado::clsEmpleado() : clsPersona()
{
    this->Puesto = "";
    this->Salario = 0;
}

clsEmpleado::clsEmpleado(char *Id, const string &Nomb, char Gen, short Edad, const string &Puesto, float Salario)
    : clsPersona(Id, Nomb, Gen, Edad), Puesto(Puesto), Salario(Salario){}

clsEmpleado::~clsEmpleado(){}

const string &clsEmpleado::getPuesto() const
{
    return Puesto;
}

void clsEmpleado::setPuesto(const string &Puesto)
{
    this->Puesto = Puesto;
}

float clsEmpleado::getSalario() const
{
    return Salario;
}

void clsEmpleado::setSalario(float Salario)
{
    this->Salario = Salario;
}

void clsEmpleado::Mostrar()
{
    clsPersona::Mostrar();
    cout<<"|"<<setfill(' ')<<setw(40)<<getPuesto()
        <<"|"<<setfill(' ')<<setw(7)<<getSalario()
       <<"|\n";
}

void clsEmpleado::Leer()
{
    clsPersona::Leer();

    cout<<"Ingrese el Puesto o Cargo: ";
    getline(cin, Puesto);

    cout<<"Ingrese el Salario: ";
    cin>>Salario;
    cin.ignore();
}

void clsEmpleado::LeerGUI()
{
    clsPersona::LeerGUI();

    Puesto = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese el Puesto o Cargo: ").toStdString();
    Salario = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese el Salario: ").toFloat();
}
