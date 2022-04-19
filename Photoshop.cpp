// Program: photoshop
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad FathElrahman Osman
// Date:    7 April 2022
// Version: 1.0
// plz add ur names above .... and  ur filters choices in the switch statement
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];
void loadImage ();
void saveImage ();
void mirror ();
void black_white();
void merge();
void saveNewImage();
void saveNewImage3();
void darkenAndLighten();
void roto();
void chose();
void invert();
void grayScale ();
void colored();
int main()
{
    int filterType;
    cout << "1-gray scale or 2-colored image :";
    cin >> filterType;
    switch (filterType) {
        case 1:
            grayScale();
            break;
        case 2 :
            colored();
            break;
    }

}
void grayScale () {

    int choose;
    loadImage();
    //under this line cout your filters numbers ... the varible "choose" its for the user to pick up filter number
    cout << "1-black and white " << endl;
    cout << "2-invert image " << endl;
    cout << "3-merge two images " << endl;
    cout << "4-rotate image " << endl;
    cout << "5-darken and Lighten Image " << endl;
    cout << "6-mirror image " << endl;
    cout << "choose a filter : ";
    cin >> choose;
    switch (choose) {
        // edit this statement with your function number and mention the function inside its case
        case 1:
            black_white();
            break;
        case 2:
            invert();
            break;
        case 3:
            merge();
            saveNewImage();
            break;
        case 4:
        case 5:
            darkenAndLighten();
            saveNewImage3();
            break;
        case 6:
            mirror();
            break;
        case 7:
            chose();
            roto();

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
void black_white (){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(image[i][j] > 133) {
                image[i][j] = 255;
            } else{
                image[i][j] = 0;
            }

        }

    }

}
// merge function
void merge(){
    char image2FileName[100];
    cout<<"Please enter name of image file to merge with: ";
    cin>>image2FileName; // take the name of the image to merge
    strcat (image2FileName,".bmp");// add the extension
    readGSBMP(image2FileName,image2);
    // looping over all indexs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            new_image[i][j] = ((image[i][j] + image2[i][j]) / 2);
        }
    }

}
// for the merge function
void saveNewImage(){
    char newImageFileName[100];
    cout<<"Enter the target image file name: ";
    cin>>newImageFileName;
    strcat(newImageFileName,".bmp");// to save the new image
    writeGSBMP(newImageFileName,new_image);

}
void saveNewImage3(){
    char newImageFileName3[100];
    cout<<"Enter the target image file name: ";
    cin>>newImageFileName3;
    strcat (newImageFileName3,".bmp");
    writeGSBMP(newImageFileName3,image3);

}
void darkenAndLighten(){
    char op; // ask the user if darken or lighten
    cout<<"Do you want to (d)arken or (l)ighten?";
    cin>>op; // take the option
    if(op=='l') // if lighten loop over all indexes
        for(int i=0;i<SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image3[i][j] = ((image[i][j] + 255) / 2);
            }
        }
        // if the darken method
    else if(op =='d')
        // loop over all indexes
        for(int i=0;i<SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image3[i][j] = (image[i][j]/4);
            }
        }
}


void roto(){
    for (int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < i ; j++)
            swap(image[i][j],image[j][i]);

    }

    for (int i = 0 ; i < SIZE; i++){
        for(int j = 0 ; j <SIZE/ 2 ; j++)
            swap(image[i][j],image[i][SIZE-j]);

    }

}

void chose(){

    int n ;
    cout<<"do you want to rotate 90,180,or 270?";
    cin>>n;
    if(n ==90){
        roto();

    }
    else if(n ==180){
        roto();
        roto();

    }

    else if(n ==270){
        roto();
        roto();
        roto();

    }
    else {
        cout<<"plz enter valid num.\n";
        chose();
    }







}

void invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

// Example code to convert to BW the image
            //A better version should NOt use 127 but the
            //average of the pixels

//z = image[i][j];
//if (z <127 )
//{
//   y = 127 -  z;
//   y +=127 ;
//}
//
//else if (z >127 )
//{
//   y = z - 127;
//   y = 127 - y;
//}
//else if (z==127){
//
//y = 127;
//}
//image[i][j]=y;

// do something with the image
        }
    }
}

