using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HalloweenServiceLibrary
{
    public class HalloweenDB
    {
        public static SqlConnection GetConnection()
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=localhost;Initial Catalog=Halloween;Integrated Security= true";
            return con;
        }
    }
}
