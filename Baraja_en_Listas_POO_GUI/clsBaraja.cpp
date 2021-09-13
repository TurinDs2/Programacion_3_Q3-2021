#include <clsBaraja.h>

clsBaraja::clsBaraja() {
    srand(time(0));
    int ncarta = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 4; j++) {
            switch (j) {
                case 0:
                    baraja[ncarta].setNum(i);
                    baraja[ncarta].setSigno('C');
                    break;
                case 1:
                    baraja[ncarta].setNum(i);
                    baraja[ncarta].setSigno('D');
                    break;
                case 2:
                    baraja[ncarta].setNum(i);
                    baraja[ncarta].setSigno('E');
                    break;
                case 3:
                    baraja[ncarta].setNum(i);
                    baraja[ncarta].setSigno('T');
                    break;
            }
            ncarta++;
        }
    }
}

clsBaraja::~clsBaraja() {

}

clsCarta *clsBaraja::getBaraja()
{
    return this->baraja;
}


void clsBaraja::Mostrar() {

    for (int i = 0; i < 52; i++) {
        baraja[i].Mostrar_Carta();
    }

    cout << "\n";
}

void clsBaraja::Exportar()
{
    std::string Nombre = "Baraja.xls";
    ofstream Archivo(Nombre.data(), ios::out | ios::app);

    Archivo << "La baraja es: " << endl;
    for (int i = 0; i < 52; i++) {
        Archivo<<baraja[i].getNum()<<baraja[i].getSigno()<<endl;
    }
    Archivo.close();
}

void clsBaraja::Mezclar_Baraja() {
    int ind;
    clsCarta tp;

    setCarta_actual(0);

    for (int i = 0; i < 52; i++) {
        ind = rand() % 52; //valor aleatorio entre 0 - 51
        tp = baraja[i];
        baraja[i] = baraja[ind];
        baraja[ind] = tp;
    }
}

clsCarta clsBaraja::Repartir_Carta() {
    if (getCarta_actual() >= 51) {
        cout << "Se acabaron las cartas" << endl;
        carta_actual = 0;
        return baraja[51];
    }
    carta_actual++;
    return baraja[carta_actual - 1];
}

void clsBaraja::setCarta_actual(int n) {
    carta_actual = n;
}

int clsBaraja::getCarta_actual() {
    return carta_actual;
}

void clsBaraja::setBaraja(clsCarta *A)
{
    //baraja = A;
}
