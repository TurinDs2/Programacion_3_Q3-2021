#include "cframe.h"
#include "ui_cframe.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
    SubMenu(false);
    IngrElim(false);

    V = Predefinido();
    InsertarPredefinido('@');

    Conectar();
}

cframe::~cframe()
{
    delete ui;
}

/********************************************************SQL************************************************
show databases;
create database Programacion_3;
use Programacion_3;
create table Baraja(Cartas varchar(3));
create table Jugador(Id varchar(15), Nomb varchar(50), Gen varchar(1), Edad smallint, TotFichas float, Apuesta float);
create table Empleado(Id varchar(15), Nomb varchar(50), Gen varchar(1), Edad smallint, Puesto varchar(40), Salario float);
insert into Baraja(Cartas) values ('3T');
insert into Jugador(Id,Nomb,Gen,Edad,TotFichas,Apuesta) values ('0801-1991-00329','Carlos Yanez','M',30,'10000','10');
insert into Empleado(Id,Nomb,Gen,Edad,Puesto,Salario)values('1003-1981-09876','Lucresia Gonzáles','F',40,'Cajera','24000');
select *from Baraja;
select *from Jugador;
select *from Empleado;
mysqldump -u ceutec -p Programacion_3 > Programacion_3.sql
**********************************************************************************************************/
bool cframe::Conectar()
{
    BD = QSqlDatabase::addDatabase("QMYSQL");
    BD.setHostName("localhost");
    BD.setPort(3306);
    BD.setUserName("phpmyadmin");
    BD.setPassword("password");
    BD.setDatabaseName("Programacion_3");
    //alter user 'phpmyadmin'@'localhost' identified with mysql_native_password by 'password';
    if( BD.open() ){
        QMessageBox::information(this,".:.Exito.:.","La Conexion con la Base de Datos se Establecio Exitosamente!!!");
        return true;
    }else{
        QMessageBox::critical(this,".:.Error.:.","No fue posible Establecer Conexion con la Base de Datos!!!"+BD.lastError().text());
        return false;
    }

}

bool cframe::Insertar()
{
    QString Consulta = "";
    if( BD.open() ){
        for ( Act=LC.primeroPtr; Act!=0; Act=Act->siguientePtr ) {
            if( OpSm=='a' && typeid(*Act->datos)==typeid(clsBaraja)){
                for (int i=0; i<52; i++ ) {
                    //Consulta = "insert into Baraja(Cartas) values ('3T');";
                    Consulta = "insert into Baraja(Cartas) values ('"+QString::fromStdString( dynamic_cast<clsBaraja*>(Act->datos)->getBaraja()[i].getCarta() )+"');";
                    BD.exec(Consulta);
                }
            }else if( OpSm=='b' && typeid(*Act->datos)==typeid(clsJugador)){
                //Consulta = "insert into Jugador(Id,Nomb,Gen,Edad,TotFichas,Apuesta) values ('0801-1991-00329','Carlos Yanez','M',30,'10000','10');";
                Consulta = "insert into Jugador(Id,Nomb,Gen,Edad,TotFichas,Apuesta) values ('"+QString::fromStdString( dynamic_cast<clsJugador*>(Act->datos)->getId() )+"','"+QString::fromStdString( dynamic_cast<clsJugador*>(Act->datos)->getNomb() )+"','"+QString::fromStdString("")+dynamic_cast<clsJugador*>(Act->datos)->getGen()+"',"+QString::number( dynamic_cast<clsJugador*>(Act->datos)->getEdad() )+",'"+QString::number( dynamic_cast<clsJugador*>(Act->datos)->getTotFichas() )+"','"+QString::number( dynamic_cast<clsJugador*>(Act->datos)->getApuesta() )+"');";
                BD.exec(Consulta);
                //QMessageBox::information(this,"Insertando...",Consulta);
            }else if( OpSm=='c' && typeid(*Act->datos)==typeid(clsEmpleado)){
                //Consulta = "insert into Empleado(Id,Nomb,Gen,Edad,Puesto,Salario)values('1003-1981-09876','Lucresia Gonzáles','F',40,'Cajera','24000');";
                Consulta = "insert into Empleado(Id,Nomb,Gen,Edad,Puesto,Salario)values('"+QString::fromStdString( dynamic_cast<clsEmpleado*>(Act->datos)->getId() )+"','"+QString::fromStdString( dynamic_cast<clsEmpleado*>(Act->datos)->getNomb() )+"','"+QString::fromStdString("")+dynamic_cast<clsEmpleado*>(Act->datos)->getGen()+"',"+QString::number( dynamic_cast<clsEmpleado*>(Act->datos)->getEdad() )+",'"+QString::fromStdString( dynamic_cast<clsEmpleado*>(Act->datos)->getPuesto() )+"','"+QString::number( dynamic_cast<clsEmpleado*>(Act->datos)->getSalario() )+"');";
                BD.exec(Consulta);
            }
        }
        BD.close();
        QMessageBox::information(this,".:.Exito.:.","La Insercion a la Base de Datos se realizo exitosamente!!!");
        return true;
    }else{
        QMessageBox::critical(this,".:.Error.:.","NO fue posible realizar la inserción en la BD!!!");
        return false;
    }
}

bool cframe::Seleccionar()//revisar porque truena
{
    QString Consulta = "";
    QSqlQuery Ejecutar;
    clsCasino *Var;
    char *Id = new char [15];
    if( BD.open() ){
        switch(OpSm){
            case 'a'://falta
                Consulta = "";
                break;
            case 'b':
                Consulta = "select *from Jugador;";
                Ejecutar.prepare(Consulta);
                Ejecutar.exec();
                while( Ejecutar.next() ){
                    //clsJugador(char *Id, const std::string &Nomb, char Gen, short Edad, float TotFichas, float Apuesta)
                    //QMessageBox::information(this,"",Ejecutar.value(0).toString()+Ejecutar.value(1).toString()+Ejecutar.value(2).toString()+Ejecutar.value(3).toString()+Ejecutar.value(4).toString()+Ejecutar.value(5).toString());
                    strcpy( Id,Ejecutar.value(0).toString().toStdString().c_str() );
                    Var = new clsJugador(Id,
                                         Ejecutar.value(1).toString().toStdString(),
                                         Ejecutar.value(2).toString().toStdString()[0],
                                         Ejecutar.value(3).toString().toUShort(),
                                         Ejecutar.value(4).toFloat(),
                                         Ejecutar.value(5).toFloat()
                                         );
                    Agregar(Var);
                }
                break;
            case 'c':
                Consulta = "select *from Empleado;";
                Ejecutar.prepare(Consulta);
                Ejecutar.exec();
                while( Ejecutar.next() ){
                    strcpy( Id,Ejecutar.value(0).toString().toStdString().c_str() );
                    Var = new clsEmpleado(Id,
                                         Ejecutar.value(1).toString().toStdString(),
                                         Ejecutar.value(2).toString().toStdString()[0],
                                         Ejecutar.value(3).toString().toUShort(),
                                         Ejecutar.value(4).toString().toStdString(),
                                         Ejecutar.value(5).toFloat()
                                         );
                    Agregar(Var);
                }
                break;
        }
        BD.close();
        QMessageBox::information(this,".:.Exito.:.","El select *from... de la Base de Datos se realizo exitosamente!!!");
        return true;
    }else{
        QMessageBox::critical(this,".:.Error.:.","NO fue posible realizar el select *from... en la BD!!!");
        return false;
    }
}

void cframe::SubMenu(bool Estado)
{
    ui->GB_Submenu->setVisible(Estado);
}

void cframe::IngrElim(bool Estado)
{
    ui->GB_Agregar_Eliminar->setVisible(Estado);
}

vector<clsCasino *> cframe::Predefinido()
{
    vector <clsCasino*> v;

    v.push_back(new clsBaraja());
    v.push_back(new clsJugador(("0801-2000-12345"),"Cristhian Nodal",'M',21,10000,10));
    v.push_back(new clsJugador(("0401-1999-56789"),"Jackson Wang",'M',22,5000,5));
    v.push_back(new clsJugador(("1001-1998-65432"),"Paquita la del Barrio",'F',23,25000,25));
    v.push_back(new clsEmpleado(("0101-1997-43210"),"Elmer Guity",'M',23,"Oficial de Vigilancia de Entrada",20000));
    v.push_back(new clsEmpleado(("0201-1996-96385"),"Karla Madison",'F',24,"Croupier",30000));
    v.push_back(new clsEmpleado(("1801-1995-74158"),"Dwayne Johnson",'M',26,"Oficial de Vigilancia de Juego",25000));

    return v;
}

void cframe::InsertarPredefinido(char Op)
{
    switch ( Op ){
    case '!':
        for( int i=0; i<V.size(); i++){
            LC.insertarAlFrente( V[i] );
        }
        break;
    case '@':
        for( int i=0; i<V.size(); i++){
            LC.insertarAl3er( V[i] );
        }
        break;
    case '#'://Antepenultimo

        break;
    case '$':
        for( int i=0; i<V.size(); i++){
            LC.insertarAlFinal( V[i] );
        }
        break;
    case '%'://Cualquier

        break;
    }
}

void cframe::Conteo()
{
    Act = LC.primeroPtr;
    ContBar = ContEmpl = ContJug = 0;

    for (; Act!=0; Act = Act->siguientePtr ) {
        if( typeid(*Act->datos)==typeid(clsBaraja) ){
            ContBar++;
        }else if( typeid(*Act->datos)==typeid(clsJugador) ){
            ContJug++;
        }else if( typeid(*Act->datos)==typeid(clsEmpleado) ){
            ContEmpl++;
        }
    }

}

void cframe::Mostrar()
{
    ui->TW_Mostrar->clear();
    Conteo();
    switch (OpSm) {
    case 'a':{
        ui->TW_Mostrar->setColumnCount(2);
        ui->TW_Mostrar->setRowCount(ContBar*52);
        ui->TW_Mostrar->setHorizontalHeaderLabels(QStringList()<<"Baraja"<<"La baraja es");

        int pos=0,ftw=0;
        for( Act = LC.primeroPtr; Act!=0; Act = Act->siguientePtr, pos++ ){
            if( typeid(*Act->datos) == typeid(clsBaraja) ){
                for(int i=0; i<52; ftw++, i++){
                    QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(pos+1) );
                    QTableWidgetItem *Carta = new QTableWidgetItem( QString::fromStdString( dynamic_cast<clsBaraja*>(Act->datos)->getBaraja()[i].getCarta() ) );
                    ui->TW_Mostrar->setItem(ftw,0,Pos);
                    ui->TW_Mostrar->setItem(ftw,1,Carta);
                }
            }
        }
        break;}
    case 'b':{
        ui->TW_Mostrar->setColumnCount(7);
        ui->TW_Mostrar->setRowCount(ContJug);
        ui->TW_Mostrar->setHorizontalHeaderLabels(QStringList()<<"Posicion"<<"Identidad"<<"Nombre Completo"<<"Genero"<<"Edad"<<"Fichas"<<"Apuesta");

        int pos=0,ftw=0;
        for(  Act = LC.primeroPtr; Act!=0; Act = Act->siguientePtr, pos++){
            if( typeid(*Act->datos) == typeid(clsJugador) ){
                QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(pos) );
                QTableWidgetItem *Id = new QTableWidgetItem( QString::fromStdString( dynamic_cast<clsJugador*>(Act->datos)->getId() ) );
                QTableWidgetItem *Nombre = new QTableWidgetItem( QString::fromStdString( dynamic_cast<clsJugador*>(Act->datos)->getNomb() ) );
                QTableWidgetItem *Gen = new QTableWidgetItem( QString::fromStdString("") + dynamic_cast<clsJugador*>(Act->datos)->getGen() );
                QTableWidgetItem *Edad = new QTableWidgetItem( QString::number( dynamic_cast<clsJugador*>(Act->datos)->getEdad() ) );
                QTableWidgetItem *Fichas = new QTableWidgetItem( QString::number( dynamic_cast<clsJugador*>(Act->datos)->getTotFichas() ) );
                QTableWidgetItem *Apuesta = new QTableWidgetItem( QString::number( dynamic_cast<clsJugador*>(Act->datos)->getApuesta() ) );
                ui->TW_Mostrar->setItem(ftw,0,Pos);
                ui->TW_Mostrar->setItem(ftw,1,Id);
                ui->TW_Mostrar->setItem(ftw,2,Nombre);
                ui->TW_Mostrar->setItem(ftw,3,Gen);
                ui->TW_Mostrar->setItem(ftw,4,Edad);
                ui->TW_Mostrar->setItem(ftw,5,Fichas);
                ui->TW_Mostrar->setItem(ftw,6,Apuesta);
                ftw++;
            }
        }
        break;}
    case 'c':{
        ui->TW_Mostrar->setColumnCount(7);
        ui->TW_Mostrar->setRowCount(ContEmpl);
        ui->TW_Mostrar->setHorizontalHeaderLabels(QStringList()<<"Posicion"<<"Identidad"<<"Nombre Completo"<<"Genero"<<"Edad"<<"Puesto"<<"Salario");

        int pos=0,ftw=0;
        for( Act = LC.primeroPtr; Act!=0; Act = Act->siguientePtr, pos++ ){
            if( typeid(*Act->datos) == typeid(clsEmpleado) ){
                    QTableWidgetItem *Pos = new QTableWidgetItem( QString::number(pos) );
                    QTableWidgetItem *Id = new QTableWidgetItem( QString::fromStdString( dynamic_cast<clsEmpleado*>(Act->datos)->getId() ) );
                    QTableWidgetItem *Nombre = new QTableWidgetItem( QString::fromStdString( dynamic_cast<clsEmpleado*>(Act->datos)->getNomb() ) );
                    QTableWidgetItem *Gen = new QTableWidgetItem( QString::fromStdString("") + dynamic_cast<clsEmpleado*>(Act->datos)->getGen() );
                    QTableWidgetItem *Edad = new QTableWidgetItem( QString::number( dynamic_cast<clsEmpleado*>(Act->datos)->getEdad() ) );
                    QTableWidgetItem *Puesto = new QTableWidgetItem( QString::fromStdString( dynamic_cast<clsEmpleado*>(Act->datos)->getPuesto() ) );
                    QTableWidgetItem *Salario = new QTableWidgetItem( QString::number( dynamic_cast<clsEmpleado*>(Act->datos)->getSalario() ) );
                    ui->TW_Mostrar->setItem(ftw,0,Pos);
                    ui->TW_Mostrar->setItem(ftw,1,Id);
                    ui->TW_Mostrar->setItem(ftw,2,Nombre);
                    ui->TW_Mostrar->setItem(ftw,3,Gen);
                    ui->TW_Mostrar->setItem(ftw,4,Edad);
                    ui->TW_Mostrar->setItem(ftw,5,Puesto);
                    ui->TW_Mostrar->setItem(ftw,6,Salario);
                    ftw++;
            }
        }
        break;}
    }
}

void cframe::ExportarXls()
{
    string Nombre = "";

    switch (OpSm) {
    case 'b':
        Nombre = "Jugadores.xls";
        break;
    case 'c':
        Nombre = "Empleados.xls";
        break;
    }

    ofstream Archivo(Nombre.data(), ios::out | ios::app);

    switch (OpSm) {
    case 'a':
        for( Act = LC.primeroPtr; Act!=0; Act = Act->siguientePtr ){
            if( typeid(*Act->datos) == typeid(clsBaraja) ){
                dynamic_cast<clsBaraja*>(Act->datos)->Exportar();
            }
        }
        break;
    case 'b':
        Archivo<<"Identidad\tNombre Completo\tGenero\tEdad\tFichas\tApuesta\n";
        for( Act = LC.primeroPtr; Act!=0; Act = Act->siguientePtr ){
            if( typeid(*Act->datos) == typeid(clsJugador) ){
                Archivo<<dynamic_cast<clsJugador*>(Act->datos)->getId()<<"\t"
                                   <<dynamic_cast<clsJugador*>(Act->datos)->getNomb()<<"\t"
                                   <<dynamic_cast<clsJugador*>(Act->datos)->getGen()<<"\t"
                                   <<dynamic_cast<clsJugador*>(Act->datos)->getEdad()<<"\t"
                                   <<dynamic_cast<clsJugador*>(Act->datos)->getTotFichas()<<"\t"
                                   <<dynamic_cast<clsJugador*>(Act->datos)->getApuesta()<<"\n";
            }
        }
        break;
    case 'c':
        Archivo<<"Identidad\tNombre Completo\tGenero\tEdad\tPuesto\tSalario\n";
        for( Act = LC.primeroPtr; Act!=0; Act = Act->siguientePtr ){
            if( typeid(*Act->datos) == typeid(clsEmpleado) ){
                Archivo<<dynamic_cast<clsEmpleado*>(Act->datos)->getId()<<"\t"
                                   <<dynamic_cast<clsEmpleado*>(Act->datos)->getNomb()<<"\t"
                                   <<dynamic_cast<clsEmpleado*>(Act->datos)->getGen()<<"\t"
                                   <<dynamic_cast<clsEmpleado*>(Act->datos)->getEdad()<<"\t"
                                   <<dynamic_cast<clsEmpleado*>(Act->datos)->getPuesto()<<"\t"
                                   <<dynamic_cast<clsEmpleado*>(Act->datos)->getSalario()<<"\n";
            }
        }
        break;
    }
    Archivo.close();
    Mostrar();
    QMessageBox::information(this,".:.Éxito.:.","La Exportación se realizó de manera exitosa!!!");
}

void cframe::Agregar()
{
    clsCasino* Var;
    switch (OpSm) {
    case 'a':
        Var = new clsBaraja();
        dynamic_cast<clsBaraja*>(Var)->Mezclar_Baraja();
        break;
    case 'b':
        Var = new clsJugador();
        dynamic_cast<clsJugador*>(Var)->LeerGUI();
        break;
    case'c':
        Var = new clsEmpleado();
        dynamic_cast<clsEmpleado*>(Var)->LeerGUI();
        break;
    }
    Agregar(Var);
}

void cframe::Agregar(clsCasino *Var)
{
    switch (OpIE) {
    case '1':
        LC.insertarAlFrente(Var);
        break;
    case '2':
        LC.insertarAl3er(Var);
        break;
    case '3':
        break;
    case '4':
        LC.insertarAlFinal(Var);
        break;
    case '5':
        break;
    case '6':
        break;
    }
}

void cframe::Eliminar()
{
    clsCasino* Var;
    switch (OpIE) {

    case '1':
        if ( LC.eliminarDelFrente(Var) )
            //cout << valor << " se elimino de la lista\n";
            break;
    case '2':
        if ( LC.eliminarDel3er( Var ) )
            // cout << valor << " se elimino de la lista\n";
            break;
    case '3':
        break;
    case '4':
        if ( LC.eliminarDelFinal( Var ) )
            //cout << valor << " se elimino de la lista\n";
            break;
    case '5':
        break;
    case '6':
        break;
    }
    if( typeid(*Var) == typeid(clsBaraja) ){
        OpSm = 'a';
    }else if( typeid(*Var) == typeid(clsJugador) ){
        OpSm = 'b';
    }else if( typeid(*Var) == typeid(clsEmpleado) ){
        OpSm = 'c';
    }
}

void cframe::Modificar()
{
    int P=0, Pos = QInputDialog::getInt(this,".:.Posición.:.","Ingrese la Posición a Modificar:");


    for ( Act=LC.primeroPtr; Act!=0; Act=Act->siguientePtr, P++ ) {
        if( P==Pos ){
            if( OpSm=='a' && typeid(*Act->datos)==typeid(clsBaraja) ){
                dynamic_cast<clsBaraja*>(Act->datos)->Mezclar_Baraja();
            }else if( (OpSm=='b' && typeid(*Act->datos)==typeid(clsJugador)) || (OpSm=='c' && typeid(*Act->datos)==typeid(clsEmpleado)) ){
                switch ( Menu_Modificar() ) {
                    case '1':
                        char *Id;
                        strcpy( Id, QInputDialog::getText(this,"","Ingrese la nueva Identidad:").toStdString().c_str() );
                        dynamic_cast<clsPersona*>(Act->datos)->setId(Id);
                        break;
                    case '2':
                        dynamic_cast<clsPersona*>(Act->datos)->setNomb( QInputDialog::getText(this,"","Ingrese el Nuevo Nombre: ").toStdString() );
                        break;
                    case '3':
                        dynamic_cast<clsPersona*>(Act->datos)->setGen( QInputDialog::getText(this,"","Ingrese el Nuevo Género: ").toStdString()[0] );
                        break;
                    case '4':
                        dynamic_cast<clsPersona*>(Act->datos)->setEdad( QInputDialog::getText(this,"","Ingrese la Nueva Edad: ").toUShort() );
                        break;
                    case '5':
                        if( OpSm=='b' ){
                            dynamic_cast<clsJugador*>(Act->datos)->setTotFichas( QInputDialog::getText(this,"","Ingrese la Nueva Cantidad de Fichas: ").toFloat() );
                        }else if( OpSm=='c' ){
                            dynamic_cast<clsEmpleado*>(Act->datos)->setPuesto( QInputDialog::getText(this,"","Ingrese el Nuevo Cargo: ").toStdString() );
                        }
                        break;
                    case '6':
                        if( OpSm=='b' ){
                            dynamic_cast<clsJugador*>(Act->datos)->setApuesta( QInputDialog::getText(this,"","Ingrese la Nueva Apuesta: ").toFloat() );
                        }else if( OpSm=='c' ){
                            dynamic_cast<clsEmpleado*>(Act->datos)->setSalario( QInputDialog::getText(this,"","Ingrese el Nuevo Salario: ").toFloat() );
                        }
                        break;
                }
            }else{
                QMessageBox::critical(this,".:.Error.:.","La Posición Ingresada No Existe para el tipo de dato Indicado!!!");
                return;
            }
        }
    }
}

char cframe::Menu_Modificar()
{
    QString Cinco = (OpSm=='b' ? "Total de Fichas" : (OpSm=='c' ? "Cargo" : ""));
    QString Seis = (OpSm=='b' ? "Apuesta" : (OpSm=='c' ? "Salario" : ""));
    char Op = QInputDialog::getText(this,".:.Modificar.:.","1.-> Modificar Identidad.\n"
                                                            "2.-> Modificar Nombre.\n"
                                                            "3.-> Modificar Género.\n"
                                                            "4.-> Modificar Edad.\n"
                                                            "5.-> Modificar "+ Cinco +"\n"
                                                            "6.-> Modificar "+ Seis +"\n"
                                                            "Su elección es:").toStdString()[0];
    if( Op<'1' || Op>'6' ){
        QMessageBox::critical(this,".:.Error.:.","La opción ingresada NO existe!!!\nFavor vuelva a Intentarlo!!!");
        Menu_Modificar();
    }
    return Op;
}

void cframe::on_Btn_Aceptar_clicked()
{
    switch (OpM) {
    case 'A':
        Mostrar();
        break;
    case 'B':
        ExportarXls();
        break;
    case 'C':
        Agregar();
        Mostrar();
        break;
    case 'D':
        Eliminar();
        Mostrar();
        break;
    case 'E'://Modificar
        Mostrar();
        Modificar();
        Mostrar();
        break;
    case 'F'://jugar Modificar Clase Jugador y lo del TotFichas y Apuesta indicado por Boris

        break;
    case 'G'://ExportarBD
        Insertar();
        Mostrar();
        break;
    case 'H'://Importar BD
        Seleccionar();
        Mostrar();
        break;
    }
}

void cframe::on_RB_Mostrar_clicked()
{
    SubMenu(true);
    IngrElim(false);
    OpM = 'A';
}

void cframe::on_RB_Exportar_xls_clicked()
{
    SubMenu(true);
    IngrElim(false);
    OpM = 'B';
}

void cframe::on_RB_Agregar_clicked()
{
    SubMenu(true);
    IngrElim(true);
    OpM = 'C';
}

void cframe::on_RB_Eliminar_clicked()
{
    SubMenu(false);
    IngrElim(true);
    OpM = 'D';
}

void cframe::on_RB_Modificar_clicked()
{
    SubMenu(true);
    IngrElim(false);
    OpM = 'E';
}

void cframe::on_RB_Jugar_clicked()
{
    SubMenu(true);
    IngrElim(false);
    OpM = 'F';
}

void cframe::on_RB_Exportar_BD_clicked()
{
    SubMenu(true);
    IngrElim(false);
    OpM = 'G';
}

void cframe::on_RB_Importar_BD_clicked()
{
    SubMenu(true);
    IngrElim(true);
    OpM = 'H';
}

void cframe::on_RB_Baraja_clicked()
{
    OpSm = 'a';
}

void cframe::on_RB_Jugador_clicked()
{
    OpSm = 'b';
}

void cframe::on_RB_Empleado_clicked()
{
    OpSm = 'c';
}

void cframe::on_RB_Frente_clicked()
{
    OpIE = '1';
}

void cframe::on_RB_3er_Pos_clicked()
{
    OpIE = '2';
}

void cframe::on_RB_Antepenultimo_clicked()
{
    OpIE = '3';
}

void cframe::on_RB_Final_clicked()
{
    OpIE = '4';
}

void cframe::on_RB_Cualquier_Pos_clicked()
{
    OpIE = '5';
    SubMenu(true);
}
