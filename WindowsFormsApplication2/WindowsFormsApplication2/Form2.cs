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

        private double a, b, c;

        public double A
        {
            get
            {
                return a;
            }
        }

        public double B
        {
            get
            {
                return b;
            }
        }

        public double C
        {
            get
            {
                return c;
            }
        }

        public Form2(OnEquationCreated onequationcreated)
        {
            this.onequationcreated = onequationcreated;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            onequationcreated();
            if (textBox1.Text.Length != 0 && textBox2.Text.Length != 0 && textBox3.Text.Length != 0)
            {
                a = Convert.ToDouble(textBox1.Text);
                b = Convert.ToDouble(textBox2.Text);
                c = Convert.ToDouble(textBox3.Text);
            }
            Close();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
