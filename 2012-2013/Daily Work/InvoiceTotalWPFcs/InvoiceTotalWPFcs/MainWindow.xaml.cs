using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using CSClassLibrary;

namespace InvoiceTotalWPFcs
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnExit_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void btnClear_Click(object sender, RoutedEventArgs e)
        {
            // Clear the text boxes
            txtSubtotal.Text = "";
            txtDiscountPercent.Text = "";
            txtDiscountAmount.Clear();
            txtInvoiceTotal.Clear();
            // Set the focus to txtSubtotal
            txtSubtotal.Focus();
        }

        private void btnCalculate_Click(object sender, RoutedEventArgs e)
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
                txtInvoiceTotal.Text = total.ToString("c");
            }
        }
        private bool IsValidData()
        {
            return WPFValidator.IsPresent(txtSubtotal) &&
                WPFValidator.IsDouble(txtSubtotal) &&
                WPFValidator.IsDouble(txtSubtotal, 0);
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            txtSubtotal.Focus();
        }
    }
}
