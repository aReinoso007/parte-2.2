#include "Principal.hpp"


Mat Imagen_Top_Black;
Mat Erosion;
Mat Dilatacion;
Mat TopHat;
Mat BlackHat;

Mat Imagen_Top_BlackAngiografia;
Mat ErosionAngiografia;
Mat DilatacionAngiografia;
Mat TopHatAngiografia;
Mat BlackHatAngiografia;

Mat Imagen_Top_BlackXray;
Mat ErosionXray;
Mat DilatacionXray;
Mat TopHatXray;
Mat BlackHatCXray;

int main(int argc, char *argv[]){

    Mat img1 = imread("/home/alex/Documents/8vo/vision-artificial/practicas/parte-2.2/imagenes/1.jpg", IMREAD_GRAYSCALE);
    Mat img2 = imread("/home/alex/Documents/8vo/vision-artificial/practicas/parte-2.2/imagenes/angiografia1.png", IMREAD_GRAYSCALE);
    Mat img3 = imread("/home/alex/Documents/8vo/vision-artificial/practicas/parte-2.2/imagenes/xray.jpg", IMREAD_GRAYSCALE);

    Mat tamanio = getStructuringElement(MORPH_CROSS, Size(37, 37));


    // Operaciones morfologicas para la Imagen Torso
	 erode(img1, Erosion, tamanio);
	 dilate(img1, Dilatacion, tamanio);
	 morphologyEx(img1, TopHat, MORPH_TOPHAT, tamanio);
	 morphologyEx(img1, BlackHat, MORPH_BLACKHAT, tamanio);
	 Imagen_Top_Black = img1 + (TopHat - BlackHat);

	 imshow("Torso", img1);
	 imshow("Erosion Torso", Erosion);
	 imshow("Dilatacion Torso", Dilatacion);
	 imshow("Tophat Torso", TopHat);
	 imshow("Blackhat Torso", BlackHat);
	 imshow("Imagen_Top_Black", Imagen_Top_Black);
	 

	 // Operaciones morfologicas para la Imagen Angiografia
	 erode(img2, ErosionAngiografia, tamanio);
	 dilate(img2, DilatacionAngiografia, tamanio);
	 morphologyEx(img2, TopHatAngiografia, MORPH_TOPHAT, tamanio);
	 morphologyEx(img2, BlackHatAngiografia, MORPH_BLACKHAT, tamanio);
	 Imagen_Top_BlackAngiografia = img2 + (TopHatAngiografia - BlackHatAngiografia);

	 imshow("Angiografia", img2);
	 imshow("Erosion Angiografia", ErosionAngiografia);
	 imshow("Dilatacion Angiografia", DilatacionAngiografia);
	 imshow("Tophat Angiografia", TopHatAngiografia);
	 imshow("Blackhat Angiografia", BlackHatAngiografia);
	 imshow("Imagen_Top_Black", Imagen_Top_BlackAngiografia);
	 
	 

	 // Operaciones morfologicas para la Imagen Xray
	 erode(img3, ErosionXray, tamanio);
	 dilate(img3, DilatacionXray, tamanio);
	 morphologyEx(img3, TopHatXray, MORPH_TOPHAT, tamanio);
	 morphologyEx(img3, BlackHatCXray, MORPH_BLACKHAT, tamanio);
	 Imagen_Top_BlackXray = img3 + (TopHatXray - BlackHatCXray);

	 imshow("Xray", img3);
	 imshow("Erosion Xray", ErosionXray);
	 imshow("Dilatacion Xray", DilatacionXray);
	 imshow("Tophat Xray", TopHatXray);
	 imshow("Blackhat Xray", BlackHatCXray);
	 imshow("Imagen_Top_Black", Imagen_Top_BlackXray);
     waitKey(0);
     destroyAllWindows();


    return 0;
}