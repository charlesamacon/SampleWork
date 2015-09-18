using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace TrackrServiceLibrary
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface ITrackrService
    {
        [OperationContract]
        List<Project> GetProjects();

        [OperationContract]
        List<Task> GetProjectTasks(int projectID);

        [OperationContract]
        int UpdateTask(string taskTitle, string taskDescription, DateTime DateClosed, int original_projectID);

        [OperationContract]
        void InsertTask(int ProjectID, string TaskTitle, string TaskDescription, DateTime DateOpened);
        // TODO: Add your service operations here
    }

    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    // You can add XSD files into the project. After building the project, you can directly use the data types defined there, with the namespace "TrackrServiceLibrary.ContractType".
    [DataContract]
    public class Project
    {
        int projectID = 0;
        string projectName = "";

        [DataMember]
        public int ProjectID
        {
            get
            {
                return projectID;
            }
            set
            {
                projectID = value;
            }
        }

        [DataMember]
        public string ProjectName
        {
            get
            {
                return projectName;
            }
            set
            {
                projectName = value;
            }
        }
    }

    [DataContract]
    public class Task
    {
        int taskID = 0;
        int projectID = 0;
        string taskTitle = "";
        string taskDescription = "";
        DateTime dateOpened;
        DateTime? dateClosed = null;

        [DataMember]
        public int TaskID
        {
            get
            {
                return taskID;
            }
            set
            {
                taskID = value;
            }
        }

        [DataMember]
        public int ProjectID
        {
            get
            {
                return projectID;
            }
            set
            {
                projectID = value;
            }
        }

        [DataMember]
        public string TaskTitle
        {
            get
            {
                return taskTitle;
            }
            set
            {
                taskTitle = value;
            }
        }

        [DataMember]
        public string TaskDescription
        {
            get
            {
                return taskDescription;
            }
            set
            {
                taskDescription = value;
            }
        }

        [DataMember]
        public DateTime DateOpened
        {
            get
            {
                return dateOpened;
            }
            set
            {
                dateOpened = value;
            }
        }

        [DataMember]
        public DateTime? DateClosed
        {
            get
            {
                if (dateClosed.HasValue)
                {
                    return dateClosed.Value;
                }
                else
                {
                    return null;
                }
            }
            set
            {
                dateClosed = value;
            }
        }
    }
}
