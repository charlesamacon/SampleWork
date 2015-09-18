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
    public class CategoryDB
    {
        [DataObjectMethod(DataObjectMethodType.Select)]
        public static List<Category> GetCategories()
        {
            List<Category> categoryList = new List<Category>();
            SqlConnection con = HalloweenDB.GetConnection();
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = "select CategoryID,LongName from Categories order by LongName";
            cmd.CommandType = CommandType.Text;
            cmd.Connection = con;
            try
            {
                con.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Category cat = new Category();
                    cat.CategoryID = reader[0].ToString();
                    cat.LongName = reader[1].ToString();
                    categoryList.Add(cat);
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
            return categoryList;
        }
    }
}
