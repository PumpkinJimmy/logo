#include <png.h>
#include "surface.h"
#include "png_surface.h"

PngSurface::PngSurface()
{
	width = height = 0;
	data = nullptr;

}
PngSurface::PngSurface(int _width, int _height, Color _bgcolor)
{
	create(_width, _height, _bgcolor);
}

void PngSurface::create(int _width, int _height, Color _bgcolor)
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

PngSurface::~PngSurface()
{
	for (int i = 0; i < height; i++)
	{
		delete [] data[i];
	}
	delete [] data;
}

void PngSurface::drawLine(Point st, Point ed, Color color)
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

void PngSurface::save(const string& filename)
{
	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,NULL, NULL, NULL);
	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (png_ptr == NULL || info_ptr == NULL)
	{
		throw "libpng error";
	}
	FILE* fp = fopen(filename.c_str(), "wb");
	if (!fp)
	{
		throw "output file error";
	}
	png_init_io(png_ptr, fp);
	png_set_IHDR(png_ptr, info_ptr,
			width, height,
			8,
			PNG_COLOR_TYPE_RGB,
			PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE,
			PNG_FILTER_TYPE_BASE);
	png_set_packing(png_ptr);
	png_write_info(png_ptr, info_ptr);
	png_write_image(png_ptr, (png_bytepp)data);
	png_write_end(png_ptr, info_ptr);
	png_destroy_write_struct(&png_ptr, &info_ptr);
	fclose(fp);
}
