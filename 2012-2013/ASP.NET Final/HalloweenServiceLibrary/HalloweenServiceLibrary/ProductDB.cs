using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HalloweenServiceLibrary
{
    [DataObject(true)]
    public class ProductDB
    {
        [DataObjectMethod(DataObjectMethodType.Select)]
        public static List<Product> GetProducts(string categoryid)
        {
            List<Product> productlist = new List<Product>();
            SqlConnection con = HalloweenDB.GetConnection();
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = "select ProductID,Name,UnitPrice,OnHand from Products where CategoryID = @CategoryID order by ProductID";
            cmd.CommandType = CommandType.Text;
            cmd.Connection = con;
            cmd.Parameters.AddWithValue("@CategoryID", categoryid);
            try
            {
                con.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Product prod = new Product();
                    prod.ProductID = reader[0].ToString();
                    prod.Name = reader[1].ToString();
                    prod.UnitPrice = Convert.ToDecimal(reader[2]);
                    prod.OnHand = Convert.ToInt32(reader[3]);
                    productlist.Add(prod);
                }
                reader.Close();
            }
            catch (SqlException ex)
            {
                throw ex;
            }
            finally
            {
                con.Close();
            }
            return productlist;
        }
    }
}
