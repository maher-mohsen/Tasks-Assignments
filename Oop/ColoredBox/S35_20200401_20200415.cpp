/*
Student 1:
		Name : Kevin Marco
		ID : 20200401 
		Group B,S35	

Student 2:
		Name : Maher mohsen bahig
		ID : 20200415
		Group B,S35

*/

#include<iostream>
#include<algorithm>
#include<windows.h>
using namespace std;
#ifndef SETCOLORFUN_H_INCLUDED
#define SETCOLORFUN_H_INCLUDED
#include <windows.h>

//Coloring Function

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

/*
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/


#endif // SETCOLORFUN_H_INCLUDED

//Create ColoredBox class
class ColoredBox{

private:
	int length,width,color;
	char block;
	char** box;
	static int biggest_area;
public:
//create Constructor
	ColoredBox 	(int len,int wid,int col = 15,char character='#'){
		length=len;
		width=wid;
		color=col;
		block = character;
// max area
		biggest_area =max(biggest_area , getArea());
//declaring 2D-Dynamic_Array
		box = new char* [length];
		for(int i=0;i<length;i++){
			box[i] =new char[width];
		}
		for(int i = 0 ; i < length ; i++){
			for(int j = 0 ; j < width ;j++)
				box[i][j] = block;
		}
	}

//Setters Functions
  	void setLen(int x){length=x;}
	void setWid(int x){width=x;}
	void setColor(int x){color=x;}
	void setboxChar(char x){block=x;}

//getters Functions
    int getLen(){return length;}
	int getWid(){return width;}
	int getCol(){return color;}
	int getArea(){return length*width;}
	static int getMaxArea(){return biggest_area;}
	char getboxChar(){return block;}

//Create Display_Functions
	void display(int rows =0 , int columns =0)
	{
		if ( rows == length ) {
			return ; 
		}
		if ( columns == width ) {
			cout << '\n';
			display (rows + 1 , 0) ;
		}
		else {
			cout << box[rows][columns];
			display (rows , columns + 1 ) ;
		}
	}

// display transpose
	void displayTransposed(int i = 0 , int j = 0){
		if(i == width) return;
		if(j == length) cout << endl, displayTransposed(i + 1 ,0);
		else{
			SetColor(color);
			cout << block ;
			SetColor(15);
			displayTransposed(i , j + 1);
		}
	}

// Display wider 
	void displayWider(int i = 0 , int j = 0){
		if(i == length) return;
		if(j == width )cout << endl, displayWider(i + 1 ,0);
		else{
			SetColor(color);
			cout << block << " ";
			SetColor(15);
			displayWider(i , j + 1);
		}
	}

//Display Chess
	void displayChess(int col,int i = 0 , int j = 0 ){
		static bool f = 0;
		if( i == length) return;
		if( j == width) cout << endl, displayChess(col , i + 1 ,0);
		else{
			if(f){SetColor(col);cout << block;SetColor(15);}
			else {SetColor(color);cout << block;SetColor(15);}
			f = !f;
			displayChess(col, i, j+1);
		}
		
	}

//Create Destructor
	~ColoredBox(){
		for(int i = 0 ; i < length ;i++){
			delete [] box[i];
		}
		delete[] box;
		cout << endl;
	}
};

/*Declare Static Variable*/int ColoredBox :: biggest_area = 0;



int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}