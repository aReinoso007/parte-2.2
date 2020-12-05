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
     imwrite("resultados/torso/Erosion-torso.png", Erosion);
	 imshow("Dilatacion Torso", Dilatacion);
     imwrite("resultados/torso/Dilatacion-torso.png", Dilatacion);
	 imshow("Tophat Torso", TopHat);
     imwrite("resultados/torso/Tophat-torso.png", TopHat);
	 imshow("Blackhat Torso", BlackHat);
     imwrite("resultados/torso/Black-torso.png", BlackHat);
	 imshow("Imagen_Top_Black", Imagen_Top_Black);
     imwrite("resultados/torso/Imagen_Top_Black-torso.png", Imagen_Top_Black);
     
	 

	 // Operaciones morfologicas para la Imagen Angiografia
	 erode(img2, ErosionAngiografia, tamanio);
	 dilate(img2, DilatacionAngiografia, tamanio);
	 morphologyEx(img2, TopHatAngiografia, MORPH_TOPHAT, tamanio);
	 morphologyEx(img2, BlackHatAngiografia, MORPH_BLACKHAT, tamanio);
	 Imagen_Top_BlackAngiografia = img2 + (TopHatAngiografia - BlackHatAngiografia);

	 imshow("Angiografia", img2);
	 imshow("Erosion Angiografia", ErosionAngiografia);
     imwrite("resultados/angiografia/ErosionAngiografia.png", ErosionAngiografia);

     imwrite("resultados/Imagen_Top_Black-torso.png", Imagen_Top_Black);
     imwrite("resultados/angiografia/Imagen_Top_Black.png", Imagen_Top_Black);

	 imshow("Dilatacion Angiografia", DilatacionAngiografia);
     imwrite("resultados/angiografia/DilatacionAngiografia.png", DilatacionAngiografia);

	 imshow("Tophat Angiografia", TopHatAngiografia);
     imwrite("resultados/angiografia/TopHatAngiografia.png", TopHatAngiografia);

	 imshow("Blackhat Angiografia", BlackHatAngiografia);
     imwrite("resultados/angiografia/BlackHatAngiografia.png", BlackHatAngiografia);

	 imshow("Imagen_Top_Black", Imagen_Top_BlackAngiografia);
	 imwrite("resultados/angiografia/Imagen_Top_BlackAngiografia.png", Imagen_Top_BlackAngiografia);
	 

	 // Operaciones morfologicas para la Imagen Xray
	 erode(img3, ErosionXray, tamanio);
	 dilate(img3, DilatacionXray, tamanio);
	 morphologyEx(img3, TopHatXray, MORPH_TOPHAT, tamanio);
	 morphologyEx(img3, BlackHatCXray, MORPH_BLACKHAT, tamanio);
	 Imagen_Top_BlackXray = img3 + (TopHatXray - BlackHatCXray);

	 imshow("Xray", img3);
	 imshow("Erosion Xray", ErosionXray);
     imwrite("resultados/xray/ErosionXray.png", ErosionXray);
	 imshow("Dilatacion Xray", DilatacionXray);
     imwrite("resultados/xray/DilatacionXray.png", DilatacionXray);
	 imshow("Tophat Xray", TopHatXray);
     imwrite("resultados/xray/TopHatXray.png", TopHatXray);
	 imshow("Blackhat Xray", BlackHatCXray);
     imwrite("resultados/xray/BlackHatCXray.png", BlackHatCXray);
	 imshow("Imagen_Top_Black", Imagen_Top_BlackXray);
     imwrite("resultados/xray/Top_BlackXray.png", Imagen_Top_BlackXray);
     waitKey(0);
     destroyAllWindows();


    return 0;
}