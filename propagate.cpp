// implement the propagate application here
//Sasha Morgan

#include "heap_priority_queue.h"
#include <fstream>
#include "image.h"
#include <iostream>

struct pix
{

	int x; //The X location 
	int y; //The Y location
	int velocity; //The Velocity of the pixel
	bool operator > (const pix &rhs);
	bool operator < (const pix &rhs);
	bool operator ==(const pix &rhs);
	bool operator <=(const pix &rhs);
};

int main(int argc, char *argv[])
{
	string in = argv[1]; //Takes in the first command line argument for the file name
	string vin = argv[2]; //Takes in the command line argument for the speed file
	string of = argv[3]; //Output file
	int time = atoi(argv[4]);

	pix orgin; //A pixel that acts like a refrenece

	Image<Pixel> in2 = readFromFile(in); //sets the input pixel
	Image<Pixel> v = readFromFile(vin); //sets the velocity pixel
	Image<Pixel> f = readFromFile(of); //sets the output pixel

	HeapPriorityQueue<pix> qdog; //creates a priority heap

	for (int a = 0; a <in2.width(); a++) //Loop that runs the width of the input file
	{
		for (int h = 0; h < in2.height(); h++) //loop that runs the height of the input file
		{
			pix insert; //creates a pixel
			insert.x = a; //sets the pixels x location equal to the width
			insert.y = h; //sets the pixels y location equal to the height
			insert.velocity = in2(a, h).red; //sets the pixel speed 
			qdog.add(insert); //inserts the item into the queue
		}
	}

	for (int i = 0; i < time; i++)
	{
		pix loc = qdog.peek(); //sets the location pizel equal o the top item in the queue
		int x2 = loc.x;
		int y2 = loc.y;
		uint8_t velo = loc.velocity; //creates a speed variable that will never be negative
		
		f(x2, y2).red = velo;
		f(x2, y2).blue = velo;
		f(x2, y2).green = velo;
	}

}
bool pix::operator > (const pix &rhs)
{
	bool check = true;
	if (velocity > rhs.velocity || velocity == rhs.velocity)
	{ 
		check = false; 
	}
	return check;
}
bool pix::operator < (const pix &rhs)
{
	bool check = true;
	if (velocity > rhs.velocity || velocity == rhs.velocity)
	{
		check = false;
	}
	return check;
}
bool pix::operator == (const pix &rhs)
{
	bool check = true;
	if (velocity > rhs.velocity || velocity == rhs.velocity)
	{
		check = false;
	}
	return check;
}
bool pix::operator <= (const pix &rhs)
{
	bool check = true;
	if (velocity > rhs.velocity || velocity == rhs.velocity)
	{
		check = false;
	}
	return check;
}