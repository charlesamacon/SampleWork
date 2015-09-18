using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CSClassLibrary;
namespace InvoiceTotalWincs
{
    public partial class frmInvoiceTotal : Form
    {
        public frmInvoiceTotal()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            // Close the form
            this.Close();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            // Clear the text boxes
            txtSubtotal.Text = "";
            txtDiscountPercent.Text = "";
            txtDiscountAmount.Clear();
            txtTotal.Clear();
            // Set the focus to txtSubtotal
            txtSubtotal.Focus();
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            if (IsValidData())
            {
                // Get the information from the form
                double subtotal = Convert.ToDouble(txtSubtotal.Text);
                // Defining the discount percent
                double discountPercent = 0.0;
                if (subtotal >= 500)
                {
                    discountPercent = 0.2;
                }
                else if (subtotal >= 250)
                {
                    discountPercent = 0.15;
                }
                else if (subtotal >= 100)
                {
                    discountPercent = 0.1;
                }
                else
                {
                    discountPercent = 0.0;
                }
                // Find the discount amount and total
                double discountAmount = subtotal * discountPercent;
                double total = subtotal - discountAmount;
                // Display results on the form
                txtDiscountPercent.Text = discountPercent.ToString("p");
                txtDiscountAmount.Text = discountAmount.ToString("c");
                txtTotal.Text = total.ToString("c");
            }
        }
        private bool IsValidData()
        {
            return WindowsValidator.IsPresent(txtSubtotal) &&
                WindowsValidator.IsDouble(txtSubtotal) &&
                WindowsValidator.IsDouble(txtSubtotal, 0);
        }
    }
}
