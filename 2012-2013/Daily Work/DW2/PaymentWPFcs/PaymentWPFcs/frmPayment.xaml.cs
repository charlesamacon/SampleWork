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
using System.Windows.Shapes;

namespace PaymentWPFcs
{
    /// <summary>
    /// Interaction logic for frmPayment.xaml
    /// </summary>
    public partial class frmPayment : Window
    {
        public frmPayment()
        {
            InitializeComponent();
        }

        private void frmPayment_Loaded(object sender, RoutedEventArgs e)
        {
            lstCreditCardType.Items.Add("Visa");
            lstCreditCardType.Items.Add("Mastercard");
            lstCreditCardType.Items.Add("American Express");
            lstCreditCardType.SelectedIndex = 0;

        }
    }
}
