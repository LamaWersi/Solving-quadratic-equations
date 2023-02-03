#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	char txt[100], per;
	double a = 0, b = 0, c = 0, D = 0;
	short n = 0;
	std::cout << "Уравнение: ";
	std::cin.getline(txt, 100);
	std::cout << txt;
	
	std::cout << std::endl << "Неизвестная: ";
	std::cin >> per;
	//поиск a b c
	for (int i = 0; txt[i] != '\0'; ++i)
	{
		if ((txt[i] > 47 && txt[i] < 58) || txt[i] == per)
		{
			if (txt[i] == per)
			{//если a = 1 и / или b = 1
				if (n == 0 && a == 0)a = 1;
				else if (b == 0)b = 1;
				n++;
			}
			else
			{//поиск a b c
				if (i != 0 && txt[i-1] != '^')
				{
					if (n == 0 && !(txt[i - 1] > 47 && txt[i - 1] < 58)) 
					{ 
						a = atoi(&txt[i]); 
						if (txt[i - 1] == '-')a *= -1;
					}
					else if (n == 1 && !(txt[i - 1] > 47 && txt[i - 1] < 58)) 
					{ 
						b = atoi(&txt[i]);  
						if (txt[i - 1] == '-')b *= -1;
					}
					else if (n == 2 && !(txt[i - 1] > 47 && txt[i - 1] < 58)) 
					{ 
						c = atoi(&txt[i]); 
						if (txt[i - 1] == '-')c *= -1;
						n = -1;
					}
				}
				else if(txt[i-1] != '^'){
					a = atoi(&txt[i]);
				}
			}
		}
	}

	std::cout << "a: " << a << " b: " << b << " c: " << c<<std::endl;

	//Дискриминант
	D = (b * b) - (4 * a * c);

	std::cout << "Дискриминант: " << D<<std::endl;

	if (D == 0)
	{
		std::cout << "Корней нет";
		return 0;
	}
	else if (D < 0)
	{
		std::cout << per<<": " << b / (2 * a);
		return 0;
	}
	//если D > 0
	std::cout 
		<<per<< "1: " << ((-b) + sqrt(D)) / (2 * a) 
		<< std::endl 
		<<per<<"2: "<<((-b) - sqrt(D)) / (2 * a);

	return 0;
}