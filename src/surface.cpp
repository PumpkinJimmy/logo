#include <cstdio>
#include <cstdlib>
#include "surface.h"

DummySurface::DummySurface()
{
	width = height = 0;
	data = nullptr;

}
DummySurface::DummySurface(int _width, int _height, Color _bgcolor)
{
	create(_width, _height, _bgcolor);
}

void DummySurface::create(int _width, int _height, Color _bgcolor)
{
	width = _width;
	height = _height;
	data = new char* [height];
	for (int i = 0; i < height; i++)
	{
		data[i] = new char[width * 3];
		for (int j = 0; j < width; j++)
		{
			data[i][3 * j] = _bgcolor.b;
			data[i][3 * j + 1] = _bgcolor.g;
			data[i][3 * j + 2] = _bgcolor.r;
		}
	}
}

DummySurface::~DummySurface()
{
	for (int i = 0; i < height; i++)
	{
		delete [] data[i];
	}
	delete [] data;
}

void DummySurface::drawLine(Point st, Point ed, Color color)
{
	if (st.y == ed.y)
	{
		for (int i = st.x; i <= ed.x; i++)
		{
			data[st.y][3 * i] = color.b;
			data[st.y][3 * i + 1] = color.g;
			data[st.y][3 * i + 2] = color.r;
		}
	}
	else
	{
		//x = my + n
		double m = (ed.x - st.x) / double(ed.y - st.y);
		double n = st.x - m * st.y;

		for (int i = st.y; i <= ed.y; i++)
		{
			int xi = int(m * i + n + 0.5); 
			data[i][3 * xi] = color.b;
			data[i][3 * xi + 1] = color.g;
			data[i][3 * xi + 2] = color.r;
		}
	}
}

void DummySurface::save(const string& filename)
{
	FILE* fp = fopen(filename.c_str(), "wb");
	fwrite(data, sizeof(char), width * height, fp);
	fclose(fp);

}
