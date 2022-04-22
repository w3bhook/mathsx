#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

#define SPACE " "
#define NL "\n"
#define E 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274

namespace mathsx
{

	long double pi = 0;
	long double sum = 0;

	namespace calculus
	{

		long double sigmoid(double x) { return ((double)1/((double)1+exp((double)-x))); }
		long double relu(long double x) { return (x > 0) ? x : 0; }

		long double find_pi(int n)
		{
			long double k = 1;
			long double sum = 1;
			
			for(int i = 1; i < n; i++)
			{
				k *= (long double)i / ((long double)2.0 * (long double)i + (long double)1);
				sum += (long double)k;
			}

			return (long double)2*(long double)sum;
		}

		long double sigma(int start, int end, int step, std::string equation, std::string placeholder)
		{
			long double x = 0;

			FILE *fp, *outputfile;
			char var[40];

			std::string cmd = "curl https://duckypl.pythonanywhere.com/api/maths/eval/" + equation + ":" + placeholder + ":" + std::to_string(start) + ":" +std::to_string(end);
			std::cout << "string: " << cmd;

			fp = popen(cmd.c_str(), "r");
				while (fgets(var, sizeof(var), fp) != NULL)
				{
					x = x + atoi(var);
				}
			pclose(fp);
			std::cout << NL << "fp: " << var << NL;

			return x;
		}

	}

	namespace function
	{

		long double pow(long double x, long double y)
		{
			sum = 1;
			for(int i = 0; i < y; i++) sum *= x;
			return sum;
		}

		long double sqrt(long double x)
		{
			return pow(x, 0.5);
		}

		long double root(long double x, long double y)
		{
			y = 1 / y;
			return pow(x, y);
		}

		long double fac(long double x)
		{
			if(x <= 0) return 1;
			else return x * fac(x - 1);
		}

		long double fast_fac(long double x)
		{
			return pow(x, x) * pow(E, -x) * pow(x, 0.5) * pow(2*x, 0.5);
		}

        long double sin(long double x)
        {
            sum = 0;
            if (!x) return x;
            for (int i = 0; i < pow(x, 10); i++)
                sum += pow(-1, i) * (pow(x, ((2 * i) + 1)) / fac(((2 * i) + 1)));
            return sum;
        }
        
        long double cos(long double x)
        {
            sum = 0;
            for (int i = 0; i < pow(x, 10); i++)
                sum += pow(-1, i) * (pow(x, ((2 * i))) / fac(((2 * i))));
            return sum;
        }

	}

	namespace trigonometry
	{

		short int a = ((-32768+(32767*2))+32767/32767);
	}

	namespace geometry
	{

		long double circum(long double r, long double p) { return (long double)2*mathsx::calculus::find_pi(p)*r; }

	}

}

int main()
{

	float _tf, _rad, _tsq, _n, _trn, _ts, _tr, _base, _expon;
	int _start, _end, _step, opt;
	std::string _equation, _placeholder;

	std::cout << NL << "Welcome to Mathsx, what do you want to do?" << NL << NL << "(1) [sigma]" << NL << "(2) [sigmoid]" << NL << "(3) [relu]" << NL << "(4) [pow]" <<  NL << "(5) [find_pi]" << NL << "(6) [fac]" << NL << "(7) [circum]" << NL << "(8) [fast_fac]" << NL << "(9) [sqrt]" << NL << "(10) [root]" << NL << NL << "$ ";
	std::cin >> opt;

	switch(opt)
	{
		case 1:

			std::cout << NL << "Start: ";
			std::cin >> _start;

			std::cout << NL << "End: ";
			std::cin >> _end;

			std::cout << NL << "Step: ";
			std::cin >> _step;

			std::cout << NL << "Equation: ";
			std::cin >> _equation;

			std::cout << NL << "Placeholder: ";
			std::cin >> _placeholder;

			std::cout << NL << NL << "sigma: " << mathsx::calculus::sigma(_start, _end, _step, _equation, _placeholder) << NL << NL << NL;

			break;

		case 2:

			std::cout << NL << "Number to sigmoidify: ";
			std::cin >> _ts;

			std::cout << NL << NL << "sigmoid: " << mathsx::calculus::sigmoid(_ts) << NL << NL << NL;

			break;

		case 3:

			std::cout << NL << "Number to reluify: ";
			std::cin >> _tr;

			std::cout << NL << NL << "relu: " << mathsx::calculus::relu(_tr) << NL << NL << NL;

			break;

		case 4:

			std::cout << NL << "Base: ";
			std::cin >> _base;

			std::cout << NL << "Exponent: ";
			std::cin >> _expon;

			std::cout << NL << NL << "pow: " << mathsx::function::pow(_base, _expon) << NL << NL << NL;

			break;

		case 5:

			int _prec;

			std::cout << NL << "Precision (0-60): ";
			std::cin >> _prec;

			std::cout.precision(_prec);
			std::cout << NL << NL << "pi: " << mathsx::calculus::find_pi(_prec) << NL << NL << NL;

			break;

		case 6:

			std::cout << NL << "Number: ";
			std::cin >> _tf;

			std::cout << NL << NL << "fact: " << mathsx::function::fac(_tf) << NL << NL << NL;

			break;

		case 7:

			std::cout << NL << "Radius: ";
			std::cin >> _rad;

			std::cout << NL << "Precision: ";
			std::cin >> _prec;

			std::cout << NL << NL << "circumference: " << mathsx::geometry::circum(_rad, _prec) << NL << NL << NL;

			break;

		case 8:
			std::cout << NL << "Number: ";
			std::cin >> _tf;

			std::cout << NL << NL << "fast factorial: " << mathsx::function::fast_fac(_tf) << NL << NL << NL;

			break;

		case 9:

			std::cout << NL << "Number: ";
			std::cin >> _tsq;

			std::cout << NL << NL << "sqrt: " << mathsx::function::sqrt(_tsq) << NL << NL << NL;

			break;

		case 10:

			std::cout << NL << "Number: ";
			std::cin >> _n;

			std::cout << NL << "Root of: ";
			std::cin >> _trn;

			std::cout << NL << NL << "root: " << mathsx::function::root(_n, _trn) << NL << NL << NL;

			break;

		default:
			main();

			break;
	}
	system("pause");
}