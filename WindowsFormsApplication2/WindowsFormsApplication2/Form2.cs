using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form2 : Form
    {
        public delegate void OnEquationCreated();

        private OnEquationCreated onequationcreated;

        public EquationsContainer equations = new EquationsContainer();

        public Form2(OnEquationCreated onequationcreated)
        {
            this.onequationcreated = onequationcreated;

            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            onequationcreated();
            Equation equation = new Equation();
            equation.A = Convert.ToInt32(textBox1.Text);
            equation.B = Convert.ToInt32(textBox2.Text);
            equation.C = Convert.ToInt32(textBox3.Text);
            Console.WriteLine(equation.A + " " + equation.B + " " + equation.C);
            equations.Add(equation);
            Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
