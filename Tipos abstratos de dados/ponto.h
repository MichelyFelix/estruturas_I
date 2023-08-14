/*TAD: ponto (x, y)*/
typedef struct ponto Ponto;
/*Tipo exportado */
Ponto *pto_cria (float x, float y);
void pto_libera (Ponto* p);
void pto_acessa (Ponto* p, float* x, float* y);
void pto_atibui (Ponto* p, float x, float y);
float pto_distancia (Ponto *p1, Ponto* p2);