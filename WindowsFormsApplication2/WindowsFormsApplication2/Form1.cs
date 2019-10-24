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

        private Form2 addEquation;

        private Change changeEquation;

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
            equation.SolveEquation();

            if (!equation.IsDiscriminantNegative)
            {
                equationArmy.Add(equation);
                if (dataGridView1.Rows.Count < equationArmy.Count)
                {
                    dataGridView1.Rows.Add();
                }
                ShowInTable();
            }
        }

        private void ShowInTable()
        {
            for (int i = 0; i < equationArmy.Count; i++)
            {
                dataGridView1.Rows[i].Cells[0].Value = equationArmy[i].A;
                dataGridView1.Rows[i].Cells[1].Value = equationArmy[i].B;
                dataGridView1.Rows[i].Cells[2].Value = equationArmy[i].C;
                dataGridView1.Rows[i].Cells[3].Value = equationArmy[i].Result1;
                dataGridView1.Rows[i].Cells[4].Value = equationArmy[i].Result2;
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

        private void delete_Click(object sender, EventArgs e)
        {
            if (equationArmy.Count > 0)
            {
                equationArmy.RemoveAt(dataGridView1.CurrentRow.Index);
                dataGridView1.Rows.RemoveAt(dataGridView1.CurrentRow.Index);
                ShowInTable();
            }
       
        }

        private void change_Click(object sender, EventArgs e)
        {
            int index = dataGridView1.CurrentRow.Index;
            changeEquation = new Change(equationArmy[index]);
            changeEquation.ShowDialog();

        }
    }
}
