#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

void runGUI();
void runGUI() {
	// possible GUI Impl
	/*	Image^ back = gcnew Bitmap("C:\\Users\\User\\Documents\\image.bmp");
		pictureBox1->BackGroundImage = back;

		while (1)
			LocalMousePosition = PictureBox1.PointToClient(Cursor.Position)
			TextBox2.Text = ("X=" & LocalMousePosition.X & "," & "Y= " & LocalMousePosition.Y)

			if (Mouse.Leftclick()) {
				Mandelbrotset.generateImage(HEIGHT, WIDTH, bitMap, LocalMousePosition.X, LocalMousePosition.Y);
				bitMap.writeToFile("first.bmp");
			}

	*/
}

/* HVAD SKAL LAVES
*	1 -  generelle optimeringer 
*	2 - implementer Julia Set
*	3 - find nogle vilde farvekombinationer
*	4 - gør skærm interaktivt, så der zoomes med mouse click
*	5 - Implementer med vector graphics istedet for bit map
*/


int main() {
	const int HEIGHT = 1000;
	const int WIDTH = 1600;

	// create a 800x600 pixel black bitMap image (1st argument is xCoor, 2nd arguments is yCoor)
	Bitmap bitMap(HEIGHT, WIDTH);
	Mandelbrot MandelbrotSet(HEIGHT, WIDTH);

	// Repeated zoom in on fractal coordinates
	MandelbrotSet.addZoom(HEIGHT / 2, WIDTH / 2);
	//MandelbrotSet.addZoom(236, 575);

	// generate a Mandelbrot fractal
	MandelbrotSet.generateImage(HEIGHT, WIDTH, bitMap);
	bitMap.writeToFile("mandelbrot.bmp");
	std::cout << "Finished writing";

}

