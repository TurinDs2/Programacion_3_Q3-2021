#include "clsPersona.h"

clsPersona::clsPersona()
{
    strcpy(this->Id, "");
    this->Nomb = "";
    this->Gen = ' ';
    this->Edad = 0;
}

clsPersona::clsPersona(char *Id, const std::string &Nomb, char Gen, short Edad)
{
    strcpy(this->Id, Id);
    this->Nomb = Nomb;
    this->Gen = Gen;
    this->Edad = Edad;
}

clsPersona::~clsPersona()
{
    this->Id = NULL;
    delete []Id;
}

void clsPersona::setId(char *Id)
{
    strcpy(this->Id, Id);
}

char *clsPersona::getId() const
{
    return Id;
}

void clsPersona::setNomb(const string &Nomb)
{
    this->Nomb = Nomb;
}

const string &clsPersona::getNomb() const
{
    return Nomb;
}

void clsPersona::setGen(char Gen)
{
    this->Gen = Gen;
}

char clsPersona::getGen() const
{
    return Gen;
}

void clsPersona::setEdad(short Edad)
{
    this->Edad = Edad;
}

short clsPersona::getEdad() const
{
    return Edad;
}

void clsPersona::Leer()
{
    cout<<"Ingrese la Identidad: ";
    cin.get(Id,16);
    cin.ignore();

    cout<<"Ingrese el Nombre: ";
    getline(cin,Nomb);

    cout<<"Ingrese el Genero: ";
    cin.get(Gen);
    cin.ignore();

    cout<<"Ingrese la Edad: ";
    cin>>Edad;
    cin.ignore();
}

void clsPersona::LeerGUI()
{
    strcpy(Id, QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese la Identidad: ").toStdString().c_str());
    Nomb = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese el Nombre: ").toStdString();
    Gen = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese el Genero: ").toUpper().toStdString()[0];
    Edad = QInputDialog::getText(this,".:.Nuevo Registro.:.","Ingrese la Edad: ").toUShort();
}

void clsPersona::Mostrar()
{
    cout<<"|"<<setfill(' ')<<setw(15)<<getId()
        <<"|"<<setfill(' ')<<setw(50)<<getNomb()
        <<"|"<<setfill(' ')<<setw(6)<<getGen()
        <<"|"<<setfill(' ')<<setw(4)<<getEdad();
}
