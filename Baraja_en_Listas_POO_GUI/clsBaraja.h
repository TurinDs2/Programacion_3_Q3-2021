#ifndef CLSBARAJA_H
#define CLSBARAJA_H

#include <clsCasino.h>

class clsBaraja : public clsCasino{
    private:
        clsCarta baraja[52]; //arreglo de la clase carta
        int carta_actual; //controla el número de carta que se reparte
    public:
        clsBaraja();
        ~clsBaraja();

        clsCarta * getBaraja();
        int getCarta_actual();
        void setBaraja(clsCarta *);
        void setCarta_actual(int);

        void Mezclar_Baraja();
        virtual void Mostrar();
        void Exportar();
        clsCarta Repartir_Carta();
};

#endif
