using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrackrServiceLibrary
{
    class TrackrDB
    {
        public static SqlConnection GetConnection()
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=PEPPER_POTTS\SQLEXPRESS;Initial Catalog=Final_Trackr;Integrated Security=True";
            return con;
        }
    }
}
