void menu(estructura estructura[],int estructuraLenght)
{
    char seguir='s';
    int opcion;
    do
    {
        printf("1- Agregar");
        printf("\n2- Mostrar");
        printf("\n3- Modificar");
        printf("\n4- Borrar");
        printf("\n5- Ordenar");
        printf("\n6- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            funcionagregar(estructura estructura[],int estructuraLenght);
            break;
        case 2:
            funcionMostrar(estructura estructura[],int estructuraLenght);
            break;
        case 3:
            funcionModificar(estructura estructura[],int estructuraLenght);
            break;
        case 4:
            funcionBorrar(estructura estructura[],int estructuraLenght);
            break;
        case 5:
            funcionOrdenar(estructura estructura[],int estructuraLenght);
            break;
        case 6:
            seguir='n';
            break;
        }
        if(seguir!='n');
        do
        {
            printf("Queres seguir con el programa? (S/N)");
            scanf("%c",&seguir);
        }
        while(seguir!='s'&&seguir!='n');

        system("cls");
    }
    while(seguir=='s');
}
