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
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class TrackrService : ITrackrService
    {
        public List<Project> GetProjects()
        {
            return ProjectDB.GetProjects();
        }

        public List<Task> GetProjectTasks(int projectID)
        {
            return TaskDB.GetProjectTasks(projectID);
        }

        public int UpdateTask(string taskTitle, string taskDescription, DateTime DateClosed, int original_projectID)
        {
            return TaskDB.UpdateTask(taskTitle, taskDescription, DateClosed, original_projectID);
        }

        public void InsertTask(int ProjectID, string TaskTitle, string TaskDescription, DateTime DateOpened)
        {
            TaskDB.InsertTask(ProjectID, TaskTitle, TaskDescription, DateOpened);
        }
    }
}
