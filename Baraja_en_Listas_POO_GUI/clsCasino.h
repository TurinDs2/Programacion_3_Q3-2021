#ifndef CLSCASINO_H
#define CLSCASINO_H
#include <clsCarta.h>
#include <QMainWindow>
#include <QInputDialog>

class clsCasino: public QMainWindow
{
public:
    clsCasino();
    virtual void Mostrar() = 0;
};

#endif // CLSCASINO_H
