/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

/*
Para las pruebas primero utilicé el comando gcc con ambos estándares c11 y c99: gcc -Wall -pedantic -std=cxx ejemplo1.c , llegó al punto de no 
dar warnings ni errores.
También utilicé el comando g++ con los estándares c++11 y c++98: g++ -Wall -pedantic -std=c++xx ejemplo1.c , muestra otros warnings con respecto a gcc. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };

/* 
La letra R está demás y lo que está dentro de las comillas se han generado saltos de línea por lo que
no se puede asignar el valor a la constante. Realizando los cambios se corrige el error 
*/
const char* s1 = R"foo(
Hello
World
)foo";
const char* s2 = "\nHello\nWorld\n";

/* 
La función void no tiene retorno de valor, el return 1 no debe ir.
se podría reemplazar con un exit(0); 
*/
void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 
/*
La función gets está deprecated, no se debe usar más porque no valida la cantidad de caracteres ingresados y como consecuencia genera overflow.
En vez de esa función se debe usar fgets.
*/
void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	gets(response);

	if (response[0] == 'n') 
		exit(0);  

	return;
}

/* 
Con el parámetro -Wall en la compilación hay warnings donde indica variables sin utilizar dentro de la función main:
analitic3, size_array2 y size_array1. Se deben comentar o eliminar si no se van a utilizar para que no ocupen espacio en memoria.

Al momento de ejecutar, espera parámetros para su ejecución de lo contrario no se ejecuta y muestra error, así mismo se debe hacer una validación
en caso se ingresen parámetros con tamaño mayor a 24 que es lo que se ha definido en char key[24].
*/ 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal";
    int size_array1 = strlen("аналитик");
    int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
    char analitic3[100]="аналитик";

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}
