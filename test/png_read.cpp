#include <iostream>
#include <png.h>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "No arg provided" << endl;
		return 0;
	}
	FILE* fp = fopen(argv[1], "rb");
	if (!fp)
	{
		cout << "Open failed" << endl;
		return 0;
	}
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_infop info_ptr = png_create_info_struct(png_ptr);

	png_init_io(png_ptr, fp);
	png_read_info(png_ptr, info_ptr);
	
	int width = png_get_image_width(png_ptr, info_ptr), height = png_get_image_height(png_ptr, info_ptr);
	png_bytep* row_pointers = (png_bytep*)malloc(height*sizeof(png_bytep));
	for (int i =0; i < height; i++)
	{
		row_pointers[i] = (png_bytep)malloc(3*width*sizeof(char));
	}
	//row_pointers = png_get_rows(png_ptr, info_ptr);
	png_read_image(png_ptr, row_pointers);
	cout << row_pointers << endl;

//	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
	//png_uint_32 width, height, bit_depth, color_type, filter_method, compression_type, interlace_type;
	//png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, &compression_type, &filter_method);
	cout << "Width: " << width << endl
		<< "Height: " << height << endl;
	int cnt = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int r = row_pointers[i][3 * j],
			g = row_pointers[i][3 * j + 1],
			b = row_pointers[i][3 * j + 2];
			if (r != 255)
			{
				printf("%d %d\n", i, j);
				cout << r << ' ' << g << ' ' << b << endl;
			}
			if (r == 255 && g == 255 && b == 255) cnt++;
		}
	}
	cout << cnt << endl;
	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
	fclose(fp);

	return 0;

}
