#include <iostream>
#include <windows.h>
using namespace std;

struct Jugador
{
    char nombre[50];
    int puntaje;
    Jugador *siguiente;
};

class ListaCircular
{
private:
    Jugador *cabeza;

public:
    ListaCircular();
    bool estaVacia();
    void insertar(char nombre[]);
    void mostrar();
    int cantidadJugadores();
    Jugador *getCabeza();
    void menuPrincipal();
    void liberarMemoria();
    void escribirLento(const char texto[]);
    int pedirJugada(char nombre[]);
    int resolverDuelo(int player1, int player2);
    void iniciarTorneo();
};

ListaCircular::ListaCircular()
{
    cabeza = nullptr;
}

bool ListaCircular::estaVacia()
{
    return cabeza == nullptr;
}

void ListaCircular::insertar(char nombre[])
{
    Jugador *nuevo = new Jugador();

    int i = 0;
    while (nombre[i] != '\0')
    {
        nuevo->nombre[i] = nombre[i];
        i++;
    }
    nuevo->nombre[i] = '\0';

    nuevo->puntaje = 0;

    if (estaVacia())
    {
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
    }
    else
    {
        Jugador *temp = cabeza;
        while (temp->siguiente != cabeza)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = cabeza;
    }

    cout << "Jugador inscrito correctamente en el sistema." << endl;
}

void ListaCircular::mostrar()
{
    if (estaVacia())
    {
        cout << "No hay jugadores inscritos en el sistema aun." << endl;
        return;
    }

    Jugador *temp = cabeza;
    cout << "LISTA DE JUGADORES PARTICIPANTES" << endl;

    do
    {
        cout << "Nombre: " << temp->nombre
             << " | Puntaje: " << temp->puntaje << endl;
        temp = temp->siguiente;
    } while (temp != cabeza);
}

int ListaCircular::cantidadJugadores()
{
    if (estaVacia())
        return 0;

    int contador = 0;
    Jugador *temp = cabeza;

    do
    {
        contador++;
        temp = temp->siguiente;
    } while (temp != cabeza);

    return contador;
}

Jugador *ListaCircular::getCabeza()
{
    return cabeza;
}

void mostrarMenu()
{
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

void mostrarAyuda()
{
    cout << "\n--- AYUDA ---" << endl;
    cout << "1. Inscriba al menos 2 jugadores." << endl;
    cout << "2. Inicie el torneo." << endl;
    cout << "3. Todos juegan contra todos." << endl;
    cout << "4. Se asignan puntos segun resultado." << endl;
}

void mostrarIntegrantes()
{
    cout << "\n--- INTEGRANTES ---" << endl;
    cout << "MILTON GUILLERMO RIVAS PALACIOS - 00019725" << endl;
    cout << "FERNANDO JOSE RIVAS HENRIQUEZ - 00154325" << endl;
}

void ListaCircular::liberarMemoria()
{
    if (estaVacia())
    {
        return;
    }
    Jugador *actual = cabeza->siguiente;
    Jugador *aux;

    while (actual != cabeza)
    {
        aux = actual;
        actual = actual->siguiente;
        delete aux;
    }

    delete cabeza;
    cabeza = nullptr;
}

void ListaCircular::escribirLento(const char texto[])
{
    for (int i = 0; texto[i] != '\0'; i++)
    {
        cout << texto[i];
        Sleep(50);
    }
}

int ListaCircular::pedirJugada(char nombre[])
{
    int opcion;

    cout << "\nPlayer: " << nombre << "elige\n";
    escribirLento("1. Piedra\n");
    escribirLento("2. Papel\n");
    escribirLento("3. Tijera\n");
    cout << "opcion: ";
    cin >> opcion;

    if (opcion < 1 || opcion > 3)
    {
        cout <<"ingresa una opcion correcta\n";
        return pedirJugada(nombre); 
    }

    return opcion;
}


void ListaCircular::menuPrincipal()
{
    int opcion;
    char nombre[50];

    do
    {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "Ingrese nombre del jugador: ";
            cin.getline(nombre, 50);
            insertar(nombre);
            break;

        case 2:
            mostrar();
            break;

        case 3:
            if (cantidadJugadores() < 2)
            {
                cout << "Se necesitan minimo 2 jugadores." << endl;
            }
            else
            {
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
            liberarMemoria();
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);
}

int main()
{
    ListaCircular lista;
    lista.menuPrincipal();
    return 0;
}
