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

        private Form2 addEquation;

        private EquationsContainer equationArmy;


        public MainWindow()
        {
            InitializeComponent();
            equationArmy = new EquationsContainer();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            addEquation = new Form2(CreateEquation);
            addEquation.ShowDialog();
            Equation equation = new Equation();
            equation.A = addEquation.A;
            equation.B = addEquation.B;
            equation.C = addEquation.C;
            equationArmy.Add(equation);
            //Console.WriteLine(equation.A + " " + equation.B + " " + equation.C + "******" + addEquation.A + " " + addEquation.B + " " + addEquation.C);
            //dataGridView1.RowsAdded();
            //dataGridView1.Rows.Add();
            //Console.WriteLine(dataGridView1.Size);
            ShowInTable();
        }

        private void ShowInTable()
        {
            Console.WriteLine("*******************");
            for (int i = 0; i < equationArmy.Count; i++)
            {
                dataGridView1.Rows[i].Cells[0].Value = equationArmy[i].A;
                dataGridView1.Rows[i].Cells[1].Value = equationArmy[i].B;
                dataGridView1.Rows[i].Cells[2].Value = equationArmy[i].C;
            }
        }

        private void CreateEquation()
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void MainWindow_Load(object sender, EventArgs e)
        {

        }
    }
}
