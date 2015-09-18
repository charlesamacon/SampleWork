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
    public partial class frmPayment : Form
    {
        public frmPayment()
        {
            InitializeComponent();
        }

        private int currentYear;
        private int currentMonth;

        private string msg = "";

        private void frmPayment_Load(object sender, EventArgs e)
        {
            // Fill the credit card type
            lstCreditCardType.Items.Add("");
            lstCreditCardType.Items.Add("American Express");
            lstCreditCardType.Items.Add("Discover Card");
            lstCreditCardType.Items.Add("Master Card");
            lstCreditCardType.Items.Add("Visa");
            lstCreditCardType.SelectedIndex = 0;
            // Fill the Expiration date month
            string[] months = { "Select a month...", "January", "February", "March" ,"April", "May", "June", 
                                  "July","August","September","October","November",
                                  "December"};
            foreach (string month in months)
            {
                cboMonth.Items.Add(month);
            }
            cboMonth.SelectedIndex = 0;
            // Full the Expiration date year
            DateTime currentDate = DateTime.Today;
            currentMonth = currentDate.Month;
            currentYear = currentDate.Year;
            cboYear.Items.Add("Select a year...");
            for (int i = currentYear; i <= currentYear + 10; i++)
            {
                cboYear.Items.Add(i);
            }
            cboYear.SelectedIndex = 0;
        }

        public string GetPayment()
        {
            // This refers to frmPayment
            this.ShowDialog();
            return msg;
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            if (IsValidData())
            {
                SaveData();
                this.Close();
            }
        }

        private void SaveData()
        {
            throw new NotImplementedException();
        }

        private bool IsValidData()
        {
            if (radCreditCard.Checked)
            {
                if (lstCreditCardType.SelectedIndex == 0)
                {
                    MessageBox.Show("You must select a credit card type.", "Entry Error");
                    lstCreditCardType.Focus();
                    return false;
                }
                if (txtCardNumber.Text == "" && txtCardNumber.Text.Length < 16)
                {
                    MessageBox.Show("You must enter a credit card number.", "Entry Error");
                    lstCreditCardType.Focus();
                    return false;
                }
                if (cboMonth.SelectedIndex == 0)
                {
                    MessageBox.Show("You must select an expiration month.", "Entry Error");
                    lstCreditCardType.Focus();
                    return false;
                }
                if (cboYear.SelectedIndex == 0)
                {
                    MessageBox.Show("You must select an expiration year.", "Entry Error");
                    lstCreditCardType.Focus();
                    return false;
                }

            }
            return true;
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
