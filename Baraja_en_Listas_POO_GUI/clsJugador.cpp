#include "clsJugador.h"

clsJugador::clsJugador() : clsPersona()
{
    this->TotFichas = 0;
    this->Apuesta = 0;
}

clsJugador::clsJugador(char *Id, const std::string &Nomb, char Gen, short Edad, float TotFichas, float Apuesta)
    : clsPersona(Id,Nomb,Gen,Edad)
{
    this->TotFichas = TotFichas;
    this->Apuesta = Apuesta;
}

clsJugador::~clsJugador()
{}

void clsJugador::setTotFichas(float TotFichas)
{
    this->TotFichas = TotFichas;
}

void clsJugador::setApuesta(float Apuesta)
{
    this->Apuesta = Apuesta;
}

float clsJugador::getTotFichas() const
{
    return TotFichas;
}

float clsJugador::getApuesta() const
{
    return Apuesta;
}

void clsJugador::Mostrar()
{
    clsPersona::Mostrar();
    cout<<"|"<<setfill(' ')<<setw(6)<<getTotFichas()
        <<"|"<<setfill(' ')<<setw(7)<<getApuesta()
       <<"|\n";
}

void clsJugador::Leer()
{
    clsPersona::Leer();

    cout<<"Ingrese el Total de Fichas: ";
    cin>>TotFichas;
    cin.ignore();

    cout<<"Ingrese el Monto de las Apuestas: ";
    cin>>Apuesta;
    cin.ignore();
}

void clsJugador::LeerGUI()
{
    clsPersona::LeerGUI();

    TotFichas = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese el Total de Fichas: ").toFloat();
    Apuesta = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese el Monto de las Apuestas: ").toFloat();
}
