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
           
        }

        private void btnEditPhoneNumber_Click(object sender, System.EventArgs e)
        {
            // TODO: Add code to edit the phone number
        }

        private string ToInitialCap(string s)
        {
            if (s.Length > 0)
            {
                string InitialCharacter = s.Substring(0, 1).ToUpper();
                string RemainCharacters = s.Substring(1).ToLower();

                s = InitialCharacter + RemainCharacters;
            }
            return s;
        }

        // TODO: Add ToInitialCap method here

        private void btnExit_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }

    }
}