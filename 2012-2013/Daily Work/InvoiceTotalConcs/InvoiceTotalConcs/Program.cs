using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CSClassLibrary;

namespace InvoiceTotalConcs
{
    class Program
    {
        static void Main(string[] args)
        {
            // Display a message
            Console.WriteLine("Welcome to the Invoice Total Calculator");
            // Setup the loop
            string choice = "y";
            while (choice.Equals("y"))
            {
                // Blank line
                Console.WriteLine();
                // Ask user for the subtotal
                double subtotal = consoleValidator.getDouble("Enter subtotal: ", 0);
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
                // Display the results
                Console.WriteLine();
                Console.WriteLine("Subtotal:         {0}", subtotal.ToString("c"));
                Console.WriteLine("Discount percent: {0}", discountPercent.ToString("p"));
                Console.WriteLine("Discount amount:  {0}", discountAmount.ToString("c"));
                Console.WriteLine("Total:            {0}",total.ToString("c"));
                Console.WriteLine();
                // Ask user whether they want to continue
                choice = consoleValidator.getContinue("Continue? (y/n): ", "y", "n");
            }
        }
    }
}
