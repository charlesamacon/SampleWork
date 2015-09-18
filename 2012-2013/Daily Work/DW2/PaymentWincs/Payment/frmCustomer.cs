using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Payment
{
    // This is the starting point for exercise 10-1 from
    // "Murach's C# 2010" by Joel Murach
    // (c) 2010 by Mike Murach & Associates, Inc. 
    // www.murach.com

    public partial class frmCustomer : Form
    {
        public frmCustomer()
        {
            InitializeComponent();
        }

        private bool isDataSaved = true;

        private void frmCustomer_Load(object sender, EventArgs e)
        {
            // Populates the combo box
            cboNames.Items.Add("Mickey Smith");
            cboNames.Items.Add("Alice Jones");
            cboNames.Items.Add("Charles Macon");
            // Sets the index to -1
            cboNames.SelectedIndex = -1;
        }

        private void dataChanged(object sender, EventArgs e)
        {
            isDataSaved = false;
        }

        private void btnSelectPayment_Click(object sender, EventArgs e)
        {
            frmPayment paymentForm = new frmPayment();
            string s = paymentForm.GetPayment();

            if (s != "")
            {
                lblPayment.Text = s;
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            if (isValidData())
            {
                SaveData();
                //isDataSaved = true;
            }
            //isDataSaved = true;
        }

        private void SaveData()
        {
            cboNames.SelectedIndex = -1;
            lblPayment.Text = "Data has been saved. \n\n(Not really, but let's pretend that it has.)";

            // call method savePayment

            isDataSaved = true;
            cboNames.Focus();
        }

        private bool isValidData()
        {
            if (cboNames.SelectedIndex == -1)
            {
                MessageBox.Show("You must select a customer.", "Entry Error");
                return false;
            }
            if (lblPayment.Text == "")
            {
                MessageBox.Show("You must enter a payment.", "Entry Error");
                return false;
            }

            return true;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void frmCustomer_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (isDataSaved == false)
            {
                string message = "This form contains unsaved data.\n\nDo you want to save it?";
                DialogResult button = MessageBox.Show(message, "Customer", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);
                if (button == DialogResult.Yes)
                {
                    if (isValidData())
                    {
                        SaveData();
                    }
                    else
                    {
                        e.Cancel = true;
                    }
                }
                if (button == DialogResult.Cancel)
                {
                    e.Cancel = true;
                }
            }
        }
    }
}