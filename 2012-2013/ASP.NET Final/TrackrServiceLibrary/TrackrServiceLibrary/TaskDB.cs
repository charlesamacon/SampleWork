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
    public class TaskDB
    {

        [DataObjectMethod(DataObjectMethodType.Select)]
        public static List<Task> GetProjectTasks(int projectID)
        {
            List<Task> tasks = new List<Task>();
            SqlConnection con = TrackrDB.GetConnection();
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = "SELECT * FROM Tasks WHERE ProjectID = @projectID AND DateClosed IS NULL";
            cmd.CommandType = CommandType.Text;
            cmd.Connection = con;
            cmd.Parameters.AddWithValue("@projectID", projectID);

            try
            {
                con.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Task t = new Task();
                    t.TaskID = Convert.ToInt32(reader[0]);
                    t.ProjectID = Convert.ToInt32(reader[1]);
                    t.TaskTitle = reader[2].ToString();
                    t.TaskDescription = reader[3].ToString();
                    t.DateOpened = Convert.ToDateTime(reader[4]);
                    
                    tasks.Add(t);
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
            return tasks;
        }

        [DataObjectMethod(DataObjectMethodType.Update)]
        public static int UpdateTask(string taskTitle, string taskDescription, DateTime DateClosed, int original_projectID)
        {
            SqlConnection con = TrackrDB.GetConnection();
            string upd = "UPDATE Tasks SET TaskTitle = @taskTitle, TaskDescription = @taskDescription, DateClosed = @DateClosed WHERE ProjectID = @projectID";
            SqlCommand cmd = new SqlCommand(upd, con);
            if (DateClosed == Convert.ToDateTime("01/01/0001 12:00:00 AM"))
                cmd.Parameters.AddWithValue("@DateClosed", DBNull.Value);
            else
                cmd.Parameters.AddWithValue("@DateClosed", DateClosed);
            cmd.Parameters.AddWithValue("@taskTitle", taskTitle);
            cmd.Parameters.AddWithValue("@taskDescription", taskDescription);
            cmd.Parameters.AddWithValue("@projectID", original_projectID);

            con.Open();
            int i = cmd.ExecuteNonQuery();
            con.Close();
            return i;
        }

        [DataObjectMethod(DataObjectMethodType.Insert)]
        public static void InsertTask(int ProjectID, string TaskTitle, string TaskDescription, DateTime DateOpened)
        {
            SqlConnection con = TrackrDB.GetConnection();
            string ins = "INSERT INTO Trackr(ProjectID, TaskTitle, TaskDescription, DateOpened) VALUES (@ProjectsID, @TaskTitle, @TaskDescription, @DateOpened)";
            SqlCommand cmd = new SqlCommand(ins, con);
            cmd.Parameters.AddWithValue("@ProjectID", ProjectID);
            cmd.Parameters.AddWithValue("@TaskTitle", TaskTitle);
            cmd.Parameters.AddWithValue("@TaskDescription", TaskDescription);
            cmd.Parameters.AddWithValue("@DateOpened", DateTime.Now);

            try
            {
                con.Open();
                cmd.ExecuteNonQuery();
            }
            catch (SqlException ex)
            {
                throw ex;
            }
            finally
            {
                con.Close();
            }

        }
    }
}
