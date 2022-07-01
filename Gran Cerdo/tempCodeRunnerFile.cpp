
        cin >> opcion;
        cls();

     switch(opcion){
        case 1:
            nuevoJuego(j1, j2);
            break;
        case 2:
            Estadisticas(j1, j2);
            break;
        case 3:
            Cerditos(j1, j2);
            break;
        default:
            break;
    }
    } while(opcion !=0);

    return 0;
}
