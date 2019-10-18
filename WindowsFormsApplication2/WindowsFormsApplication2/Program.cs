using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace WindowsFormsApplication2
{
    public class Equation : IComparable<Equation>
    {
        private double descriminant;
        private double result1;
        private double result2;
        private bool isDiscriminantNegative;
        private Achtung achtung;

        public double A
        {
            get;
            set;
        }

        public double B
        {
            get;
            set;
        }

        public double C
        {
            get;
            set;
        }

        public double Result1
        {
            get
            {
                return result1;
            }
        }

        public double Result2
        {
            get
            {
                return result2;
            }
        }

        public bool IsDiscriminantNegative
        {
            get
            {
                return isDiscriminantNegative;
            }
        }

        public void SolveEquation()
        {
            isDiscriminantNegative = false;
            descriminant = Math.Pow(B, 2) - 4 * A * C;

            if (descriminant < 0)
            {
                //throw new ArgumentOutOfRangeException("Sorry, we cant solve the equation with negative descriminant");
                isDiscriminantNegative = true;
                achtung = new Achtung();
                achtung.ShowDialog();
            }

            result1 = ((-1 * B) + Math.Sqrt(descriminant)) / (2 * A);
            result2 = ((-1 * B) - Math.Sqrt(descriminant)) / (2 * A);
        }

        public int CompareTo(Equation other)
        {
            if (A.CompareTo(other.A) != 0)
            {
                return A.CompareTo(other.A);
            }
            else if ((B.CompareTo(other.B) != 0))
            {
                return B.CompareTo(other.B);
            }
            else
            {
                return C.CompareTo(other.C);
            }

        }

        public override string ToString()
        {
            return string.Format("{0}X^2 + {1}X + {2} = 0", A, B, C);
        }

    }


    interface ILabContainer<T> : System.Collections.Generic.IEnumerable<T>
    {
        // Доступ к элементу контейнера по индексу. Выбрасывает исключение, если индекс не верен.
        T this[int index]
        {
            get;
            set;
        }
        // Свойство числа элементов в контейнере.
        int Count
        {
            get;
        }
        // Добавление в контейнер элемента.
        void Add(T item);
        // Очистка контейнера.
        void Clear();
        // Удаляет элемент из контейнера. Выбрасывает исключение, если индекс не верен.
        void RemoveAt(int index);
    }


    public class EquationsContainer : ILabContainer<Equation>
    {
        private List<Equation> equations;
        public EquationsContainer()
        {
            equations = new List<Equation>();
        }

        public void Add(Equation equation)
        {
            equations.Add(equation);
            equations.Sort();
        }

        public void Clear()
        {
            equations.Clear();
        }

        public void RemoveAt(int index)
        {
            if (index < 0 || index >= equations.Count())
            {
                throw new IndexOutOfRangeException("Index is out of range!");
            }
            else
            {
                equations.RemoveAt(index);
            }
        }

        public Equation this[int index]
        {
            get
            {
                return equations[index];
            }

            set
            {

            }
        }

        public int Count
        {
            get
            {
                return equations.Count;
            }
        }

        public override string ToString()
        {
            StringBuilder builder = new StringBuilder();
            foreach (Equation equation in equations)
            {
                builder.AppendLine(equation.ToString());
            }
            return builder.ToString();
        }

        public IEnumerator<Equation> GetEnumerator()
        {
            return equations.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return equations.GetEnumerator();
        }
    }

    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainWindow());
        }
    }
}
