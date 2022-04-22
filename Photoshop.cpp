
// FCI - Programming 1 - 2022 - Assignment 3
// Program Name: photoshop
// Last Modification Date: 20/4/2022
// Author 1 and ID  and Group: Dina Maher Fadl Ali - 20210547 - S16
// Author 1 and ID  and Group: Youssef Hamed Mohammed Hamed - 20210494 - S15-S16
// Author 1 and ID  and Group: Mohamed FathElrahman Osman - 20210702- S15-S16
// Teaching Assistant: Yousrs & Nesma
// Purpose: Demonstrate use of bmplip for handling bmp colored and grayscale images program load a gray image and store it in another file.
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];
unsigned char rgbImage[SIZE][SIZE][RGB];
unsigned char newRgbImage[SIZE][SIZE][RGB];
void loadImage ();
void saveImage ();
void mirror ();
void black_white();
void flipImage ();
void merge();
void saveNewImage();
void saveNewImage3();
void darkenAndLighten();
void roto();
void chose();
double avg();
void invert();
void  detect_Image_edges ();
void grayScale ();
void colored();
void loadRgbImage ();
void saveRgbImage();
void saveNewRgbImage ();
void blur_image();
void shrink2();
void shrink3();
void shrink4();
int main() {
    int filterType;
    cout << "1-gray scale or 2-colored image:";
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
    void grayScale() {
        int choose;
        string rat;
        loadImage();
        cout << "1- Black and White" << endl
             << "2- Invert Image\n"
             << "3- Merge Filter\n"
             << "4- Flip Image\n"
             << "5- Darken and Lighten Image\n"
             << "6- Rotate Image\n"
             << "7- Detect Image Edges\n"
             << "8- Enlarge Image\n"
             << "9- Shrink Image\n"
             << "10- Mirror 1/2 Image\n"
             << "11- Shuffle Image\n"
             << "12- Blur Image\n"
             << "13- Save the image to a file\n"
             << "0- Exit\n"
             << "choose a filter: ";
        cin >> choose;
        switch (choose) {
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
                flipImage();
                break;
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
                break;
            case 9:
                cout << "Shrink to (1/2), (1/3) or (1/4)?:";
                cin >> rat;
                if (rat == "1/4") {
                    shrink4();
                    saveNewImage3();
                    exit(0);
                } else if (rat == "1/3") {
                    shrink3();
                    saveNewImage3();
                    exit(0);
                } else if (rat == "1/2") {
                    shrink2();
                    saveNewImage3();
                    exit(0);
                } else {
                    cout << "Plz enter a valid num";
                }
                break;
            case 10:
                detect_Image_edges();
                break;
            case 12:
                blur_image();
                saveImage();
                break;
        }
    }
//___________________________________________________
void loadRgbImage () {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, rgbImage);
}
//___________________________________________________
void loadImage () {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
//___________________________________________________
void saveRgbImage(){
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, rgbImage);
}
//_____________________________________________________
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
double avg(){
    double sum = 0;
    int limit =0 ;
//    Nested loop for calculating the required sum

    for (;limit <SIZE; limit++){
        for (int col =0 ; col <SIZE; col++){
            sum += image[limit][col];
        }
    }

//    calculating the result of the sum/count
    double result = sum/ count ;
    return result;
}
void black_white (){
    int limit =0;
    for (; limit<SIZE; limit++){
        for (int color =0 ; color <SIZE; color++){
            if (image[limit][color] > avg()) {
                image[limit][color] = 255;
            } else if (image[limit][color] < avg()) {
                image[limit][color] = 0;
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
            newImage[i][j] = ((image[i][j] + image2[i][j]) / 2);
        }
    }

}
// for the merge function
void saveNewRgbImage () {
    char newImageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> newImageFileName;

    // Add to it .bmp extension and load image
    strcat (newImageFileName, ".bmp");
    writeRGBBMP(newImageFileName, newRgbImage);
}
void saveNewImage(){
    char newImageFileName[100];
    cout<<"Enter the target image file name: ";
    cin>>newImageFileName;
    strcat(newImageFileName,".bmp");// to save the new image
    writeGSBMP(newImageFileName,newImage);

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
    if(n == 90){
        roto();

    }
    else if(n == 180){
        roto();
        roto();

    }

    else if(n == 270){
        roto();
        roto();
        roto();

    }
    else {
        cout<<"plz enter valid num.\n";
        chose();
    }

}
void flipImage (){
    char choise;
    cout<<"1-vertically : \n"
    <<"2-horizontally :";
    cin >> choise;
    if(choise == '1') {
        int k = 0;
        for (int i = SIZE; i > 0; i--) {
            int s = 0;
            for (int j = 0; j < SIZE; j++) {
                newImage[k][s] = image[i][j];
                s++;
            }
            k++;
        }
        saveNewImage();
        exit(0);
    }
    else if(choise == '1') {
        int k = 0;
        for (int i = 0; i < SIZE; i++) {
            int s = 0;
            for (int j = SIZE; j > 0; j--) {

                newImage[k][s] = image[i][j];
                s++;
            }
            k++;
        }
        saveNewImage();
        exit(0);
    }
}

void invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

        }
    }
}
void  detect_Image_edges (){
    int limit =0;
    for (; limit<SIZE; limit++){
        for (int color =0 ; color <SIZE; color++){
            if (image[limit][color] > avg()) {
                image[limit][color] = 255;
            } else if (image[limit][color] < avg()) {
                image[limit][color] = 0;
            }
        }
    }

    for(int i =0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            int x = (image[i-1][j]+image[i+1][j]-2*image[i][j]);
            int y = (image[i][j-1]+image[i][j+1]-2*image[i][j]);
            if(i-1 >0 || i+1<255 || j-1 >0 || j+1<255 )
                newImage[i][j] = 255-x-y;
            else
                newImage[i][j]= 255;
        }
    }
    saveNewImage();
}
// blur filter
void blur_image(){
    for (int i = 0; i < SIZE; i++) { // loop for every pixel in the image
        for (int j = 0; j < SIZE; j++) {
            // take the avg of the surrounding 25 pixel of every pixel and save in the same image.
            image[i][j] = (image[i][j]+image[i-2][j-2]+image[i-2][j-1]+image[i-2][j]+image[i-2][j+1]+image[i-2][j+2]+image[i-1][j-2]
                           +image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i-1][j+2]+image[i][j-2]+image[i][j-1]+image[i][j]+image[i][j+1]
                           +image[i][j+2]+image[i+1][j-2]+image[i+1][j-1]+image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]+image[i+2][j-2]+image[i+2][j-1]
                           +image[i+2][j]+image[i+2][j+1]+image[i+2][j+2])/26;
        }
    }
}

// shrink image to 1/4 it’s original
void shrink4(){
    for(int i=0; i < SIZE; i++){ // loop for every pixel in the image
        for(int j = 0; j < SIZE; j++){
            image3[i/4][j/4] =(image[i+1][j] + image[i][j+1] + image[i+1][j+1] + image[i][j])/4;
        }
    }
}

// shrink image to 1/2 it’s original
void shrink2(){
    for(int i=0;i<SIZE; i++) { // loop for every pixel in the image
        for (int j = 0; j < SIZE; j++) {
            image3[i / 2][j / 2] = (image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1] + image[i][j]) / 4;
        }
    }
}

// shrink image to 1/3 it’s original
void shrink3(){
    for(int i=0;i<SIZE; i++) { // loop for every pixel in the image
        for (int j = 0; j < SIZE; j++) {
            image3[i / 3][j / 3] = (image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1] + image[i][j]) / 4;
        }
    }
}
