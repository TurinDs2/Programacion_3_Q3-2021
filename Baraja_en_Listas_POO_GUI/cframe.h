#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QMessageBox>
#include <Lista.h>
#include <clsBaraja.h>
#include <clsJugador.h>
#include <clsEmpleado.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();
    bool Conectar();
    bool Insertar();
    bool Seleccionar();

    void SubMenu(bool Estado);
    void IngrElim(bool Estado);
    vector<clsCasino*> Predefinido();
    void InsertarPredefinido(char Op);
    void Conteo();
    void Mostrar();
    void ExportarXls();
    void Agregar();
    void Agregar(clsCasino* Var);
    void Eliminar();
    void Modificar();
    char Menu_Modificar();


private slots:
    void on_RB_Mostrar_clicked();
    void on_RB_Exportar_xls_clicked();
    void on_RB_Agregar_clicked();
    void on_RB_Eliminar_clicked();
    void on_RB_Modificar_clicked();
    void on_RB_Jugar_clicked();
    void on_RB_Exportar_BD_clicked();
    void on_RB_Importar_BD_clicked();
    void on_Btn_Aceptar_clicked();
    void on_RB_Baraja_clicked();
    void on_RB_Jugador_clicked();
    void on_RB_Empleado_clicked();
    void on_RB_Frente_clicked();
    void on_RB_3er_Pos_clicked();
    void on_RB_Antepenultimo_clicked();
    void on_RB_Final_clicked();
    void on_RB_Cualquier_Pos_clicked();

private:
    Ui::cframe *ui;
    QSqlDatabase BD;

    char OpM, OpSm,OpIE;
    int ContBar, ContJug, ContEmpl;
    Lista <clsCasino*> LC;
    Nodo <clsCasino*> *Act;
    vector<clsCasino*> V;
};
#endif // CFRAME_H
