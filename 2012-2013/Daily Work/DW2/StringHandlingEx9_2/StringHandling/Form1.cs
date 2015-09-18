using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace StringHandling
{
    // This is the starting point for exercise 9-2 from
    // "Murach's C# 2010" by Joel Murach
    // (c) 2010 by Mike Murach & Associates, Inc. 
    // www.murach.com

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnParseName_Click(object sender, System.EventArgs e)
        {
            string fullname = txtFullName.Text;
            string[] columns = fullname.Split(' ');
            string firstname = "";
            string middlename = "";
            string lastname = "";
            string msg = "";
            switch (columns.Length)
            {
                case 2:
                    firstname = ToInitialCap(columns[0]);
                    lastname = columns[1];
                    lastname = HypenApos(lastname);
                    msg = "First name:\t" + firstname + "\n"
                        + "Last name:\t" + lastname;
                    break;
                case 3:
                    firstname = ToInitialCap(columns[0]);
                    middlename = ToInitialCap(columns[1]);
                    lastname = columns[2];
                    lastname = HypenApos(lastname);
                    msg = "First name:\t" + firstname + "\n"
                        + "Middle name:\t" + middlename + "\n"
                        + "Last name:\t" + lastname;
                    break;
                case 4:
                    firstname = ToInitialCap(columns[0]);
                    middlename = ToInitialCap(columns[1]);
                    lastname = HypenApos(columns[2]) + " " + HypenApos(columns[3]);
                    msg = "First name:\t" + firstname + "\n"
                        + "Middle name:\t" + middlename + "\n"
                        + "Last name:\t" + lastname;
                    break;
                default:
                    MessageBox.Show("There is no name as typed.", "Entry Error");
                    break;
            }
            if (columns.Length >= 2 && columns.Length <= 4)
            {
                MessageBox.Show(msg, "Parse Name");
            }
        }

        private void btnEditPhoneNumber_Click(object sender, System.EventArgs e)
        {
            string enteredPhone = txtPhoneNumber.Text;
            StringBuilder phoneNumber = new StringBuilder(enteredPhone, 14);

            // Phone number currently looks like this: (xxx) xxx-xxxx

            // Covered on page 271 in book.
            phoneNumber.Remove(0, 1);   // xxx) xxx-xxxx
            phoneNumber.Remove(3, 2);   // xxxxxx-xxxx
            phoneNumber.Remove(6, 1);   // xxxxxxxxxx

            string onlyNumbersPhone = phoneNumber.ToString();

            phoneNumber.Insert(3, "-"); // xxx-xxxxxxx
            phoneNumber.Insert(7, "-"); // xxx-xxx-xxxx

            string standardPhone = phoneNumber.ToString();

            string msg = "Entered:\t\t" + enteredPhone + "\n"
                + "Digits Only:\t" + onlyNumbersPhone + "\n"
                + "Standard Format:\t" + standardPhone;

            MessageBox.Show(msg, "Edit Phone Number");
        }

        // TODO: Add ToInitialCap method here
        private string ToInitialCap(string s)
        {
            string s1 = s.Substring(0, 1).ToUpper();
            string s2 = s.Substring(1).ToLower();
            s = s1 + s2;
            return s;
        }

        private string HypenApos(string s)
        {
            int hypen = s.IndexOf('-');
            int apos = s.IndexOf(Convert.ToChar("'"));
            string s1 = "";
            string s2 = "";
            string s3 = "";
            if (hypen > -1 && apos == -1)
            {
                s1 = s.Substring(0, hypen);
                s2 = s.Substring(hypen + 1);
                s = ToInitialCap(s1) + "-" + ToInitialCap(s2);
            }
            else if (hypen == -1 && apos > -1)
            {
                s1 = s.Substring(0, apos);
                s2 = s.Substring(apos + 1);
                s = ToInitialCap(s1) + "'" + ToInitialCap(s2);
            }
            else if (hypen > -1 && apos > -1)
            {
                if (hypen < apos)
                {
                    s1 = s.Substring(0, hypen);
                    s2 = s.Substring(hypen + 1, 1);
                    s3 = s.Substring(apos + 1);
                    s = ToInitialCap(s1) + "-" + ToInitialCap(s2) + "'" + ToInitialCap(s3);
                }
                else
                {
                    s1 = s.Substring(0, apos);
                    s2 = s.Substring(apos + 1, hypen - (apos + 1));
                    s3 = s.Substring(hypen + 1);
                    s = ToInitialCap(s1) + "'" + ToInitialCap(s2) + "-" + ToInitialCap(s3);
                }
            }
            else
            {
                s = ToInitialCap(s);
            }
            return s;
        }

        private void btnExit_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }

    }
}