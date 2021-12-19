#include <iostream>

extern const int a, b, c, d;

int main()
{
	std::cout << a * (b + (static_cast < float > (c) / d)) << std::endl;

	int x = 15, y = 40;
	x = (x <= 21) ? 21 - x : 2 * (x - 21);
	y = (y <= 21) ? 21 - y : 2 * (y - 21);
	std::cout << x << ' ' << y << std::endl;

	int arr[3][3][3]{0};
	int* p = arr[0][0];
	arr[1][1][1] = 100;
	std::cout << p[16] << std::endl; // если массив arr[x][y][z] а необходимый элемент в arr[i][j][k], то p[i*y*z + j*z + k]

	return 0;
}