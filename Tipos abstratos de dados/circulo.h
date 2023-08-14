/*TAD: circulo*/

/* dependencia de modulos */
#include "ponto.h"

/* tipo exportado */

typedef struct circulo Circulo;

/* função exportadas*/
Circulo* circ_cria (float x, float y, float r);
void circ_libera (circulo* c);
float circ_area (Circulo* c);
int circ_interior (Circulo* c, Ponto* p);