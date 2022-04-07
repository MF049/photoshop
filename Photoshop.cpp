// Program: photoshop
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad FathElrahman Osman
// Date:    7 April 2022
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void mirror ();
 

int main()
{
   string choose;
  loadImage();
  //under this line cout your filters numbers ... the varible "choose" its for the user to pick up filter number
  cout << "1-black and white "<<endl;
  cout << "2-invert image "<<endl;
  cout << "3-merge two images "<<endl;
  cout << "4- rotate image "<<endl;
  cout << "5-darken and Lighten Image "<<endl;
  cout << "6-mirror image "<<endl;
  cout << "choose a filter";
   cin >> choose;
    switch (choose) {
        // edit this statement with your function number and mention the function inside its case
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            mirror();
            break;
    }
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
// write your code function under this line pleas
//and write your names in the top of the program
void mirror (){
    int choise;

    cout << "Mirror 1-left, 2-right, 3-upper, 4-down side? : ";
    cin >> choise;
    switch (choise)
    {
        case  1:
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE; j > 0; j--) {
                    image[i][j] = image[i][SIZE-j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = image[i][SIZE-j];


                }
            }
            break;
        case 3:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[SIZE-i][SIZE-j] = image[i][SIZE-j];
                }
            }
            break;
        case 4:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] =image[SIZE-i][j];
                }
            }
            break;
    }
}
