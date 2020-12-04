#include "Principal.hpp"


int main(int argc, char *arv[]){

    Mat imagen = imread("imagenes/1.jpg");

    namedWindow("Imagen", WINDOW_AUTOSIZE);
    imshow("Imagen", imagen);
    waitKey(0);
    destroyAllWindows();

    return 0;
}