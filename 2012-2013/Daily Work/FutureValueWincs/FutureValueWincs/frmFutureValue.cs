using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CSClassLibrary;
using Microsoft.VisualBasic;

namespace FutureValueWincs
{
    public partial class frmFutureValue : Form
    {
        public frmFutureValue()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtAPR.Clear();
            txtFutureValue.Clear();
            txtInvestment.Clear();
            txtYears.Clear();
            txtInvestment.Focus();
        }

        private void frmFutureValue_Load(object sender, EventArgs e)
        {
            txtInvestment.Focus();
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            if (IsValidData())
            {
                // Get the information from the form
                decimal investment = Convert.ToDecimal(txtInvestment.Text);
                double rate = Convert.ToDouble(txtAPR.Text);
                int years = Convert.ToInt32(txtYears.Text);
                // Find the number of months and month rate
                int months = years * 12;
                double mrate = rate / 100 / 12;
                // Find the future value
                decimal fv = General.CalculateFutureValue(investment, mrate, months);
                // Display the results
                txtInvestment.Text = investment.ToString("c");
                txtAPR.Text = (rate/100).ToString("p3");
                txtFutureValue.Text = Strings.FormatCurrency(fv, 2);
            }
        }
        private bool IsValidData()
        {
            return WindowsValidator.IsPresent(txtInvestment) &&
                WindowsValidator.IsDecimal(txtInvestment) &&
                WindowsValidator.IsDecimal(txtInvestment, 0m, 1000m) &&
                WindowsValidator.IsPresent(txtAPR) &&
                WindowsValidator.IsDouble(txtAPR) &&
                WindowsValidator.IsDouble(txtAPR, 0, 20) &&
                WindowsValidator.IsPresent(txtYears) &&
                WindowsValidator.IsInteger(txtYears) &&
                WindowsValidator.IsInteger(txtYears, 1, 40);
        }
    }
}
