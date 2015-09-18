using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DateHandling
{
    // This is the starting point for exercise 9-1 from
    // "Murach's C# 2010" by Joel Murach
    // (c) 2010 by Mike Murach & Associates, Inc. 
    // www.murach.com

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalculateDueDays_Click(object sender, System.EventArgs e)
        {
            // Get the future date from the form
            DateTime futureDate = Convert.ToDateTime(txtFutureDate.Text);

            // Get current date
            DateTime currentDate = DateTime.Today;

            // Find the number of days (page 261)
            TimeSpan daysUntil = futureDate.Subtract(currentDate);
            int days = daysUntil.Days;

            // Display the results
            string msg = "Current Date:     " + currentDate.ToShortDateString() + "\n"
                       + "Future date:      " + futureDate.ToShortDateString() + "\n\n"
                       + "Days until due:   " + days.ToString();

            MessageBox.Show(msg, "Due days Calculation");
        }

        private void btnCalculateAge_Click(object sender, System.EventArgs e)
        {
            // Get the birthdate from the form
            DateTime birthdate = Convert.ToDateTime(txtBirthDate.Text);

            // Get Current Date
            DateTime currentDate = DateTime.Today;

            // Find the birthdate parts
            int birthyear = birthdate.Year;
            int birthday = birthdate.Day;
            int birthmonth = birthdate.Month;

            // Find the current date parts;
            int currentyear = currentDate.Year;
            int currentday = currentDate.Day;
            int currentmonth = currentDate.Month;

            // Find age
            int age = currentyear - birthyear;

            if (birthmonth > currentmonth)
            {
                age--;
            }
            if (birthmonth == currentmonth && birthday > currentday)
            {
                age--;
            }

            string msg = "Current Date:      " + currentDate.ToLongDateString() + "\n"
                       + "Birth Date:        " + birthdate.ToLongDateString() + "\n\n"
                       + "Age:               " + age.ToString();

            MessageBox.Show(msg, "Age Calculation");

        }

        private void btnExit_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }
    }
}