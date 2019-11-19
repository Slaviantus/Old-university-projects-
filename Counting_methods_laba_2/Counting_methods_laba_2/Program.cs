using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Counting_methods_laba_2
{
    class Program
    {
        static double SumNonDiagonalElements(double[,] matrix, int size, int rowNumber)
        {
            double sum = 0;
            for (int i = 0; i < size; i++)
            {
                if (rowNumber != i)
                {
                    sum += matrix[rowNumber, i];
                }
            }
            return sum;
        }

        static bool Convergence(double[,] matrix, int size)// проверка на сходимость
        {
            bool convergence = true;
            for (int i = 0; i < size; i++)
            {
                if (matrix[i, i] <= SumNonDiagonalElements(matrix, size, i))
                {
                    convergence = false;
                }
            }
            return convergence;
        }

        static int Factorial(int numb)
        {
            int res = 1;
            for (int i = numb; i > 1; i--)
                res *= i;
            return res;
        }

        static void ConversionMatrix(double[,] matrix, int size)
        {
            for (int i = 0; i < Factorial(size); i++)
            {

            }
        }

        static double[,] TriangleView(double[,] matrix, int size)
        {
            double delitel;
            for (int i = 0; i < size; i++) // прямой ход
            {
                for (int j = 0; j < size; j++)
                {
                    if ((i == j) && (i != size - 1))
                    {
                        for (int k = i + 1; k < size; k++)
                        {
                            delitel = matrix[k, j] / matrix[i, j];
                            for (int l = i; l <= size; l++)
                            {
                                matrix[k, l] = matrix[k, l] - (matrix[i, l] * delitel);
                            }

                        }
                    }
                }
            }
            return matrix;
        }

        static void IterativeMethod(double[,] matrix, int size, double eps)
        {
            double[] oldResults = new double[size];
            double[] results = new double[size];
            bool solved = false;

            for (int i = 0; i < size; i++)
            {
                oldResults[i] = matrix[i, size];
            }

            while (!solved)
            {
                for (int i = 0; i < size; i++)
                {
                        double sum = 0;
                        for (int j = 0; j < size - 1; j++)
                        {
                            if (i != j)
                            {
                                
                                sum += (matrix[i, j] * oldResults[j]);
                            }
                        }
                    results[i] = (1.0 / matrix[i, i]) * (matrix[i, size] - sum);
                   
                }

                for (int i = 0; i < size; i++)
                {
                    if (Math.Abs(oldResults[i] - results[i]) < eps)
                    {
                        solved = true;
                    }
                }

                for (int i = 0; i < size; i++)
                {
                    oldResults[i] = results[i];
                }

            }
        }



        static void ShowAllMatrix(double[,] matrix, int size)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j <= size; j++)
                {
                    if (j == size)
                    {
                        Console.Write("      " + matrix[i, j] + " ");
                    }
                    else
                    {
                        Console.Write(matrix[i, j] + " ");
                    }
                }
                Console.WriteLine();
            }
        }

        static void FillArray(double[,] matrix, int size)
        {
            Console.WriteLine("Enter the elements of matrix");
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Console.WriteLine("Enter [" + (i + 1) + "]" + "[" + (j + 1) + "]" + " element");
                    matrix[i, j] = Convert.ToDouble(Console.ReadLine());
                }
            }

            Console.WriteLine("Enter the right side of the system of equations");
            for (int i = 0; i < size; i++)
            {
                Console.WriteLine("Enter the first element of last column");
                matrix[i, size] = Convert.ToDouble(Console.ReadLine());
            }
        }

        static void Main(string[] args)
        {
            int size;
            double eps = 0;
            Console.WriteLine("Enter the size of matrix:");
            size = Convert.ToInt32(Console.ReadLine());
            double[,] matrix = new double[size, size + 1];
            FillArray(matrix, size);
            ShowAllMatrix(matrix, size);
            Console.WriteLine("Enter the accuracy:");
            eps = Convert.ToDouble(Console.ReadLine());
            //TriangleView(matrix, size);
            ShowAllMatrix(matrix, size);
            Console.ReadKey();
        }
    }
}
