enum color { blanco, negro };
enum tipo { peon, torre, caballo, alfil, reina, rey };
struct pieza{
    enum color micolor;
    enum tipo mitipo;
};
int Valido_P(struct pieza *mipieza, int x1, int y1, int x2, int y2);