using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CSClassLibrary;

namespace BaseConvsions
{
    public partial class frmConvert : Form
    {
        public frmConvert()
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
            cboBase.SelectedIndex = -1;
            radBase10ToBase.Checked = false;
            radBaseToTen.Checked = true;
            txtNumber.Text = "";
            txtResult.Text = "";
        }

        private void btnConvert_Click(object sender, EventArgs e)
        {
            if (cboBase.SelectedIndex == -1)
            {
                MessageBox.Show("A base must be selected.", "Entry Error");
                return;
            }
            int basevalue = Convert.ToInt32(cboBase.SelectedItem);
            if (WindowsValidator.IsPresent(txtNumber))
            {
                if (radBaseToTen.Checked)
                {
                    if (IsInteger(txtNumber,"Number to convert",basevalue))
                    {
                        string s = txtNumber.Text;
                        int sum = 0;
                        int power = s.Length - 1;
                        string c;
                        for (int i = 0; i < s.Length; i++) 
                        {
                            c = s.Substring(i, 1);
                            sum += (int)Math.Pow(basevalue, power) * ConvertLetter(c);
                            power--;
                        }
                        txtResult.Text = sum.ToString();
                    }
                }
                else if (radBase10ToBase.Checked)
                {
                    if (IsInteger(txtNumber, "number to convert", 10))
                    {
                        List<int> remainder = new List<int>();
                        int number = Convert.ToInt32(txtNumber.Text);
                        do
                        {
                            remainder.Add(number % basevalue);
                            number /= basevalue;
                        } while (number >= basevalue);
                        remainder.Add(number);
                        string numberstring = "";
                        for (int i = remainder.Count - 1; i >= 0; i--)
                        {
                            int nvalue = remainder[i];
                            numberstring += ConvertNumber(nvalue);
                        }
                        txtResult.Text = numberstring;
                    }
                }
                else
                {
                    MessageBox.Show("A conversion base was not selected.", "Entry Error");
                }
            }
        }

        public bool IsInteger(TextBox textbox, string name, int vbase)
        {
            string s = textbox.Text;
            bool IsValid = true;
            switch (vbase)  
            {
                case 2:
                    foreach (char c in s)
                    {
                        if (!(c == '0' || c == '1'))
                        {
                            MessageBox.Show(name + " must be a 0 or 1.", "Entry Error");
                            IsValid = false;
                        }
                    }
                    break;
                case 8:
                    foreach (char c in s)
                    {
                        if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'))
                        {
                            MessageBox.Show(name + " must be a 0, 1, 2, 3, 4, 5, 6, 7.", "Entry Error");
                            IsValid = false;
                        }
                    }
                    break;
                case 16:
                    foreach (char c in s)
                    {
                        if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || 
                            c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F'))
                        {
                            MessageBox.Show(name + " must be a 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F.", "Entry Error");
                            IsValid = false;
                        }
                    }
                    break;
                case 10:
                    foreach (char c in s)
                    {
                        if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'))
                        {
                            MessageBox.Show(name + " must be a 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.", "Entry Error");
                            IsValid = false;
                        }
                    }
                    break;
            }
            return IsValid;
        }
        private int ConvertLetter(string c)
        {
            int number = 0;
            switch (c)
            {
                case "A":
                    number = 10;
                    break;
                case "B":
                    number = 11;
                    break;
                case "C":
                    number = 12;
                    break;
                case "D":
                    number = 13;
                    break;
                case "E":
                    number = 14;
                    break;
                case "F":
                    number = 15;
                    break;
                default:
                    number = Convert.ToInt32(c);
                    break;
            }
            return number;
        }
        private string ConvertNumber(int value)
        {
            string valuestring = "";
            switch (value)
            {
                case 10:
                    valuestring = "A";
                    break;
                case 11:
                    valuestring = "B";
                    break;
                case 12:
                    valuestring = "C";
                    break;
                case 13:
                    valuestring = "D";
                    break;
                case 14:
                    valuestring = "E";
                    break;
                case 15:
                    valuestring = "F";
                    break;
                default:
                    valuestring = value.ToString();
                    break;
            }
            return valuestring;
        }

        private void frmConvert_Load(object sender, EventArgs e)
        {
            // Set combo box index to -1
            cboBase.SelectedIndex = -1;
            // Set focus to combo box cboBase
            cboBase.Focus();
        }
    }
}
