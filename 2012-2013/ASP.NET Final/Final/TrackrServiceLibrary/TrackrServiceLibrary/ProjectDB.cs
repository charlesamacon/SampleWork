using System;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrackrServiceLibrary
{
    [DataObject(true)]
    public class ProjectDB
    {
        [DataObjectMethod(DataObjectMethodType.Select)]
        public static List<Project> GetProjects()
        {
            List<Project> projectlist = new List<Project>();
            SqlConnection con = TrackrDB.GetConnection();
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = "SELECT * FROM Projects ORDER BY ProjectID";
            cmd.CommandType = CommandType.Text;
            cmd.Connection = con;

            try
            {
                con.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Project proj = new Project();
                    proj.ProjectID = Convert.ToInt16(reader[0].ToString());
                    proj.ProjectName = reader[1].ToString();
                    projectlist.Add(proj);
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

                return projectlist;

        }
    }
}
