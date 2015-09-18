using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CSClassLibrary;

namespace TestconsoleValidatorConcs
{
    class Program
    {
        static void Main(string[] args)
        {
            // Display welcome message
            Console.WriteLine("Welcome to the test program for consoleValidator");
            // Setup the choice while loop
            string choice = "y";
            while (choice.Equals("y"))
            {
                Console.WriteLine();
                // Ask user for information
                string name = consoleValidator.getString("Enter the name of investor: ");
                decimal investment = consoleValidator.getDecimal("Enter monthly investment: ", 0m, 1000m);
                double rate = consoleValidator.getDouble("Enter annual interest rate: ", .01, .2);
                int year = consoleValidator.getInteger("Enter the number of years: ", 0, 20);
                int age = consoleValidator.getInteger("Enter the age of investor: ", 0);
                decimal salary = consoleValidator.getDecimal("Enter the monthly salary: ", 0m);
                // Find the monthly interest rate and number of month
                int months = year * 12;
                double mrate = rate / 12;
                // Find the future value
                decimal fv = CalculateFutureValue(investment, months, mrate);
                // Display the results
                Console.WriteLine("Name of investor: {0}", name);
                Console.WriteLine("Age of investor:  {0}", age);
                Console.WriteLine("Monthly salary:   {0}", salary);
                Console.WriteLine("Future value:     {0}", fv.ToString("c"));
                Console.WriteLine();
                // Ask the user for continuation
                choice = consoleValidator.getContinue("Continue? (y/n): ", "y", "n");
            }
        }
        static decimal CalculateFutureValue(decimal investment, int months, double mrate)
        {
            decimal futureValue = 0m;
            for (int i = 0; i < months; i++)
            {

                futureValue = (futureValue + investment) * (1m + (decimal)mrate);
            }
            return futureValue;
        }
    }
}
