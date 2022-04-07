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
   auto choose;
  loadImage();
  //under this line cout your filters numbers ... the varible "choose" its for the user to pick up filter number
   cin >> choose;
    switch (choose) {
        // edit this statement with your function number and mention the function inside its case
        case 1:
        case 2:
        case 3:
        case 4:
        case "a" :
          mirror();
           break;
  saveImage();
  return 0;
}
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
 string choise;
 
   cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? : ";
   cin >> choise;
   switch (choise)
   {
   case  "l":
    for (int i = 0; i < SIZE; i++) {
       for (int j = SIZE; j > 0; j--) {
           image[i][j] = image[i][SIZE-j];     
       }
        }
      break;
   case "r" :
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
           image[i][j] = image[i][SIZE-j];   
   

   }
} 
break;
   case "u" :
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         image[SIZE-i][SIZE-j] = image[i][SIZE-j]; 
      }
       }
       break;
   case "d" : 
      for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
            image[i][j] =image[SIZE-i][j];     
         }
          }
          break;
   }

