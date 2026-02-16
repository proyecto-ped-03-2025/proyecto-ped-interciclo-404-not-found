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
    int pvp(int player1, int player2);
    void mostrarCombate(const char *nombre1, int player1, const char *nombre2, int player2);
    void iniciarTorneo();
    void reportarGanador();
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
    cout << "\n===== TORNEO PIEDRA PAPEL O TIJERA =====" << endl;
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

    cout << "\nPlayer: " << nombre << " elige\n";
    escribirLento("1. Piedra\n");
    escribirLento("2. Papel\n");
    escribirLento("3. Tijera\n");
    cout << "opcion: ";
    cin >> opcion;

    if (opcion < 1 || opcion > 3)
    {
        cout << "ingresa una opcion correcta\n";
        return pedirJugada(nombre);
    }

    return opcion;
}

int ListaCircular::pvp(int player1, int player2)
{
    if (player1 == player2)
        return 0;

    switch (player1)
    {
    case 1:
        return (player2 == 3) ? 1 : 2;
    case 2:
        return (player2 == 1) ? 1 : 2;
    case 3:
        return (player2 == 2) ? 1 : 2;
    }

    return 0;
}

void ListaCircular::mostrarCombate(const char *nombre1, int player1, const char *nombre2, int player2)
{
    cout << "\n====================================\n";
    cout << "   " << nombre1 << "  VS  " << nombre2 << "\n";
    cout << "====================================\n";

    if (player1 == 1 && player2 == 2)
    {
        cout << R"(

        _______              __      __   _______            _______ 
    ---'   ____)            \ \    / /  / _____/        ---'    ____)____
          (_____)            \ \  / /  / /____                     ______)
          (_____)             \ \/ /   \____  \                   _______)
          (____)               \  /    _____)  )                 _______)
    ---.__(___)                 \/    /_______/         ---.__________)

            PAPEL CUBRE PIEDRA

)";
    }

    else if (player1 == 2 && player2 == 1)
    {
        cout << R"(

         _______             __      __   _______          _______
    ---'    ____)____       \ \    / /  / _____/       ---'   ____)
               ______)       \ \  / /  / /____               (_____)
              _______)        \ \/ /   \____  \              (_____)
             _______)          \  /    _____)  )             (____)
    ---.__________)             \/    /_______/        ---.__(___)

            PAPEL CUBRE PIEDRA

)";
    }

    else if (player1 == 1 && player2 == 3)
    {
        cout << R"(

        _______              __      __   _______           _______
    ---'   ____)            \ \    / /  / _____/        ---'   ____)____
          (_____)            \ \  / /  / /____                    ______)
          (_____)             \ \/ /   \____  \                __________)
          (____)               \  /    _____)  )              (____)
    ---.__(___)                 \/    /_______/         ---.__(___)

            PIEDRA ROMPE TIJERA

)";
    }

    else if (player1 == 3 && player2 == 1)
    {
        cout << R"(

        _______              __      __   _______           _______
    ---'   ____)____        \ \    / /  / _____/        ---'   ____)
              ______)        \ \  / /  / /____                (_____)
           __________)        \ \/ /   \____  \               (_____)
          (____)               \  /    _____)  )              (____)
    ---.__(___)                 \/    /_______/         ---.__(___)

            PIEDRA ROMPE TIJERA

)";
    }

    else if (player1 == 2 && player2 == 3)
    {
        cout << R"(

         _______             __      __   _______           _______
    ---'    ____)____       \ \    / /  / _____/        ---'   ____)____
               ______)       \ \  / /  / /____                    ______)
              _______)        \ \/ /   \____  \                __________)
             _______)          \  /    _____)  )              (____)
    ---.__________)             \/    /_______/         ---.__(___)

            TIJERA CORTA PAPEL

)";
    }

    else if (player1 == 3 && player2 == 2)
    {
        cout << R"(

        _______              __      __   _______            _______
    ---'   ____)____        \ \    / /  / _____/        ---'    ____)____
              ______)        \ \  / /  / /____                     ______)
           __________)        \ \/ /   \____  \                   _______)
          (____)               \  /    _____)  )                 _______)
    ---.__(___)                 \/    /_______/         ---.__________)

            TIJERA CORTA PAPEL

)";
    }

    else if (player1 == 1 && player2 == 1)
    {
        cout << R"(

        _______              __      __   _______          _______
    ---'   ____)            \ \    / /  / _____/       ---'   ____)
          (_____)            \ \  / /  / /____               (_____)
          (_____)             \ \/ /   \____  \              (_____)
          (____)               \  /    _____)  )             (____)
    ---.__(___)                 \/    /_______/        ---.__(___)

                 EMPATE: PIEDRA

)";
    }

    else if (player1 == 2 && player2 == 2)
    {
        cout << R"(

         _______             __      __   _______           _______
    ---'    ____)____       \ \    / /  / _____/       ---'    ____)____
               ______)       \ \  / /  / /____                    ______)
              _______)        \ \/ /   \____  \                  _______)
             _______)          \  /    _____)  )                _______)
    ---.__________)             \/    /_______/        ---.__________)

                 EMPATE: PAPEL

)";
    }

    else if (player1 == 3 && player2 == 3)
    {
        cout << R"(

        _______              __      __   _______           _______
    ---'   ____)____        \ \    / /  / _____/        ---'   ____)____
              ______)        \ \  / /  / /____                    ______)
           __________)        \ \/ /   \____  \                __________)
          (____)               \  /    _____)  )              (____)
    ---.__(___)                 \/    /_______/         ---.__(___)

                 EMPATE: TIJERA

)";
    }

    else
    {
        cout << "\n";
    }
}

void ListaCircular::iniciarTorneo()
{
    if (cantidadJugadores() < 2)
    {
        cout << "Se necesitan minimo 2 jugadores\n";
        return;
    }

    Jugador *aux = cabeza;

    do
    {
        aux->puntaje = 0;
        aux = aux->siguiente;
    } while (aux != cabeza);

    Jugador *player1 = cabeza;

    do
    {
        Jugador *player2 = player1->siguiente;

        while (player2 != cabeza)
        {
            int jugada1 = pedirJugada(player1->nombre);
            int jugada2 = pedirJugada(player2->nombre);

            mostrarCombate(player1->nombre, jugada1, player2->nombre, jugada2);

            int resultado = pvp(jugada1, jugada2);

            if (resultado == 0)
            {
                escribirLento("Empate\n");
                player1->puntaje += 1;
                player2->puntaje += 1;
            }
            else if (resultado == 1)
            {
                escribirLento("Gana ");
                escribirLento(player1->nombre);
                cout << endl;
                player1->puntaje += 3;
            }
            else
            {
                escribirLento("Gana ");
                escribirLento(player2->nombre);
                cout << endl;
                player2->puntaje += 3;
            }

            player2 = player2->siguiente;
        }

        player1 = player1->siguiente;

    } while (player1->siguiente != cabeza);

    escribirLento("\nTorneo finalizado.\n");
}

void ListaCircular::reportarGanador()
{
    if (estaVacia())
    {
        cout << "No hay jugadores inscritos.\n";
        return;
    }

    Jugador *aux = cabeza;
    bool todosCero = true;

    do
    {
        if (aux->puntaje != 0)
        {
            todosCero = false;
            break;
        }
        aux = aux->siguiente;
    } while (aux != cabeza);

    if (todosCero)
    {
        cout << "aun no se ha jugado el torneo\n";
        return;
    }

    aux = cabeza;
    Jugador *ganador = cabeza;

    do
    {
        if (aux->puntaje > ganador->puntaje)
            ganador = aux;

        aux = aux->siguiente;

    } while (aux != cabeza);

    cout << "\n=== ||GANADOR DEL TORNEO|| ===\n";
    cout << "Jugador: " << ganador->nombre << " | Puntaje: " << ganador->puntaje << endl;
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
            cout << endl;
            break;

        case 2:

            mostrar();
            cout << endl;
            break;

        case 3:

            if (cantidadJugadores() < 2)
            {
                cout << "Se necesitan minimo 2 jugadores." << endl;
            }
            else
            {
                iniciarTorneo();
            }
            cout << endl;
            break;

        case 4:

            reportarGanador();
            cout << endl;
            break;

        case 5:

            mostrarAyuda();
            cout << endl;
            break;

        case 6:
            mostrarIntegrantes();
            cout << endl;
            break;

        case 0:

            liberarMemoria();
            cout << "Saliendo..." << endl;
            cout << endl;
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
