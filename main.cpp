#include <iostream>
using namespace std;

struct Jugador {
    char nombre[50];
    int puntaje;
    Jugador* siguiente;
};
class ListaCircular {
private:
    Jugador* cabeza;

public:
    ListaCircular() {
        cabeza = nullptr;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void insertar(char nombre[]) {
        Jugador* nuevo = new Jugador();

        int i = 0;
        while (nombre[i] != '\0') {
            nuevo->nombre[i] = nombre[i];
            i++;
        }
        nuevo->nombre[i] = '\0';

        nuevo->puntaje = 0;

        if (estaVacia()) {
            cabeza = nuevo;
            nuevo->siguiente = cabeza;
        } else {
            Jugador* temp = cabeza;
            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
            nuevo->siguiente = cabeza;
        }

        cout << "Jugador inscrito correctamente." << endl;
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "No hay jugadores inscritos." << endl;
            return;
        }

        Jugador* temp = cabeza;
        cout << "LISTA DE JUGADORES PARTICIPANTES" << endl;

        do {
            cout << "Nombre: " << temp->nombre
                 << " | Puntaje: " << temp->puntaje << endl;
            temp = temp->siguiente;
        } while (temp != cabeza);
    }

    int cantidadJugadores() {
        if (estaVacia()) return 0;

        int contador = 0;
        Jugador* temp = cabeza;

        do {
            contador++;
            temp = temp->siguiente;
        } while (temp != cabeza);

        return contador;
    }

    Jugador* getCabeza() {
        return cabeza;
    }
};

void mostrarMenu() {
    cout << "===== TORNEO PIEDRA PAPEL O TIJERA =====" << endl;
    cout << "1. Inscribir jugador" << endl;
    cout << "2. Mostrar jugadores" << endl;
    cout << "3. Iniciar torneo" << endl;
    cout << "4. Reportar ganador" << endl;
    cout << "5. Ayuda" << endl;
    cout << "6. Integrantes" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione opcion: ";
}

void mostrarAyuda() {
    cout << "\n--- AYUDA ---" << endl;
    cout << "1. Inscriba al menos 2 jugadores." << endl;
    cout << "2. Inicie el torneo." << endl;
    cout << "3. Todos juegan contra todos." << endl;
    cout << "4. Se asignan puntos segun resultado." << endl;
}

void mostrarIntegrantes() {
    cout << "\n--- INTEGRANTES ---" << endl;
    cout << "Tu Nombre - Carnet" << endl;
    cout << "Nombre Companero - Carnet" << endl;
}

int main() {

    ListaCircular lista;
    int opcion;
    char nombre[50];

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {

            case 1:
                cout << "Ingrese nombre del jugador: ";
                cin.getline(nombre, 50);
                lista.insertar(nombre);
                break;

            case 2:
                lista.mostrar();
                break;

            case 3:
                if (lista.cantidadJugadores() < 2) {
                    cout << "Se necesitan minimo 2 jugadores." << endl;
                } else {
                    cout << "Funcion torneo pendiente en otra rama." << endl;
                }
                break;

            case 4:
                cout << "Funcion ganador pendiente en otra rama." << endl;
                break;

            case 5:
                mostrarAyuda();
                break;

            case 6:
                mostrarIntegrantes();
                break;

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while(opcion != 0);

    return 0;
}