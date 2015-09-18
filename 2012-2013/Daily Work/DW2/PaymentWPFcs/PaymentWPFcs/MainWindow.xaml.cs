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

namespace PaymentWPFcs
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

        bool isDataSaved = true;

        private void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            cboNames.Items.Add("Mike Smith");
            cboNames.Items.Add("Nancy Jones");
        }

        private void btnExit_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void btnSave_Click(object sender, RoutedEventArgs e)
        {
            if (IsValidData())
            {
                SaveData();
            }
        }

        private void btnSelectPayment_Click(object sender, RoutedEventArgs e)
        {
            frmPayment paymentForm = new frmPayment();
            bool? selectedResult = paymentForm.ShowDialog();
        }

        private bool IsValidData()
        {
            if (cboNames.SelectedIndex == -1)
            {
                MessageBox.Show("You must select a customer.", "Entry Error");
                cboNames.Focus();
                return false;
            }
            if (lblPayment.Content == "")
            {
                MessageBox.Show("You must enter a payment.", "Entry Error");
                return false;
            }
            return true;
        }

        private void SaveData()
        {
            cboNames.SelectedIndex = -1;
            lblPayment.Content = "";
            isDataSaved = true;
            cboNames.Focus();
        }
    }
}
