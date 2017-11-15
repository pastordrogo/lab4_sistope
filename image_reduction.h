/*
	HEADERS DE FUNCIONES PARA MANEJADOR DE IMAGENES
*/

#ifndef _THREAD_HANDLER_H
#define _THREAD_HANDLER_H

#include "util.h"
#include <unistd.h>

typedef struct image {
	int ** matrix;		/* Matriz donde se guardan los datos de la imagen. */
	int ** reduction;	/* Matriz en donde se guardan los datos de la imagen reducida. */
	int N, M;			/* Tamaños de la matriz. */
	int mPixels;		/* Cantidad de pixeles que se agrupan y promedian. */

} Image;


/**
 * Funcion que lee el archivo de la imagen, aloca memoria donde sea necesario
 * para almacenar los datos e inicializa una variable del tipo Image.
 * 
 * Entrada:
 *	image 	- Puntero a una estructura del tipo Image, es inicializada en esta funcion.
 *	filename- Nombre del archivo de donde se carga la imagen.
 *	m 		- Cantidad de pixeles que se deben leer consecutivamente y promediarlos.
 */
void image_read_initialize(Image* image, char* filename, int m);

/**
 * Funcion que realize la reduccion de la imagen con el metodo de las filas.
 * 
 * Entrada:
 *	image - Puntero a la imange que se le aplica el metodo.
 * 
 * Salida: 
 */
void image_reduction_method1(Image* image);

/**
 * Funcion que realize la reduccion de la imagen con el metodo de las columnas.
 * 
 * Entrada:
 *	image - Puntero a la imange que se le aplica el metodo.
 */
void image_reduction_method2(Image* image);

/**
 * Escribe los resultados obtenidos al reducir la imagen en un archivo.
 * 
 * Entrada:
 *	image 	 - Puntero a la imagen que se quiere guardar.
 *	filename - Nombre del archivo en donde se guarda la imagen.
 */
void image_write(Image * image, char* filename);


#endif