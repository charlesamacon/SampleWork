using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace InvoiceTotal
{
    // This is the starting point for exercise 8-1 from
    // "Murach's C# 2010" by Joel Murach
    // (c) 2010 by Mike Murach & Associates, Inc. 
    // www.murach.com

    public partial class frmInvoiceTotal : Form
	{
		public frmInvoiceTotal()
		{
			InitializeComponent();
		}

        // TODO: declare class variables for array and list here
        decimal[] invoices = new decimal[5];
        int index = 0;
        List<decimal> invoiceList = new List<decimal>();

        private void btnCalculate_Click(object sender, EventArgs e)
		{
            try
            {

                if (txtSubtotal.Text == "")
                {
                    MessageBox.Show(
                        "Subtotal is a required field.", "Entry Error");
                }
                else
                {
			        decimal subtotal = Decimal.Parse(txtSubtotal.Text);
                    if (subtotal > 0 && subtotal < 10000)
                    {
                        decimal discountPercent = 0m;
                        if (subtotal >= 500)
                            discountPercent = .2m;
                        else if (subtotal >= 250 & subtotal < 500)
                            discountPercent = .15m;
                        else if (subtotal >= 100 & subtotal < 250)
                            discountPercent = .1m;
                        decimal discountAmount = subtotal * discountPercent;
			            decimal invoiceTotal = subtotal - discountAmount;

                        discountAmount = Math.Round(discountAmount, 2);
                        invoiceTotal = Math.Round(invoiceTotal, 2);

                        if (index < 5)
                        {
                            invoices[index] = invoiceTotal;
                            index++;
                        }
                        else
                        {
                            MessageBox.Show("You have reached the maximum dimension of the array.", "Too many data values");
                        }

                        invoiceList.Add(invoiceTotal);

                        txtDiscountPercent.Text = discountPercent.ToString("p1");
                        txtDiscountAmount.Text = discountAmount.ToString();
                        txtTotal.Text = invoiceTotal.ToString();

                    }
                    else
                    {
                        MessageBox.Show(
                            "Subtotal must be greater than 0 and less than 10,000.", 
                            "Entry Error");
                    }
                }
            }
            catch (FormatException)
            {
                MessageBox.Show(
                    "Please enter a valid number for the Subtotal field.", 
                    "Entry Error");
            }
            txtSubtotal.Focus();
        }

		private void btnExit_Click(object sender, EventArgs e)
		{
            // TODO: add code that displays dialog boxes here
            Array.Sort(invoices);
            string msg = "";
            foreach (decimal d in invoices)
            {
                if (d != 0m)
                {
                    msg += d.ToString("c") + "\n";
                }
            }
            MessageBox.Show(msg, "Order Totals-Array");
            msg = "";
            invoiceList.Sort();
            foreach (decimal d in invoiceList)
            {
                msg += d.ToString("c") + "\n";
            }
            MessageBox.Show(msg, "Order Totals-List");
            this.Close();
		}

	}
}