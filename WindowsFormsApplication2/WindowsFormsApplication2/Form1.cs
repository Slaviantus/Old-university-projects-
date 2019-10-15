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
    public partial class MainWindow : Form
    {
        public EquationsContainer equations;

        /*public EquationsContainer Equations
        {
            get
            {
                return equations;
            }

        }*/
     

          public MainWindow()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new Form2(CreateEquation).ShowDialog();
            Equation equation = new Equation();
            //dataGridView1.RowsAdded();
            Console.WriteLine("Geralt!!");
            //dataGridView1.Rows.Add();
            //Console.WriteLine(dataGridView1.Size);

            
        }

        private void CreateEquation()
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
