/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Pixel
{
private:

public:


};

class Image
{
private:
	int depth;
	int row;
	int col;
	Pixel*** image;

public:
	Image(int d=1 , int r=1 , int c=1)
	{
		depth = d;
		row = r;
		col = c;
		Image = new Pixel * *[row];
		for (int i = 0; i < row; i++) {
			Image[i] = new Pixel * [col];
			for (int j = 0; j < col; j++) {
				Image[i][j] = new Pixel[depth];
				for (int k = 0; k < depth; k++) {
					Image[i][j][k] = { 0, 0, 0 }; // default color is black
				}
			}
	}

	Image(Image& copy) // const or not
	{

	}

	~Image()
	{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				delete[] Image[i][j];
			}
			delete[] Image[i];
		}
		delete[] Image;
	}

	int getRow()
	{
		return row;
	}

	int getCol()
	{
		return col;
	}

	int getDepth()
	{
		return depth;
	}

	
	


};

int main()
{





	return 0;
}
