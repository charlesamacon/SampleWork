using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using TrackrServices;

public partial class Default2 : System.Web.UI.Page
{
    TrackrServiceClient client = new TrackrServiceClient();

    protected void Page_Load(object sender, EventArgs e)
    {
        GridView1.DataSource = client.GetProjects();
        GridView1.DataBind();

    }
    protected void btnNext_Click(object sender, EventArgs e)
    {
        if (GridView1.SelectedIndex == -1)
        {
            lblError.Text = "You must select a project before you may proceed.";
        }
        else
        {
            GridViewRow row = GridView1.SelectedRow;
            Session.Add("ProjectID", row.Cells[0].Text);
            int projectID = Convert.ToInt32(row.Cells[0].Text);
            lblError.Text = "";

            btnNext.CommandArgument = "View2";
            btnNext.CommandName = "SwitchViewByID";

            if (client.GetProjectTasks(Convert.ToInt32(Session["ProjectID"].ToString())) == null)
            {
                lblError2.Text = "No Tasks For This Project";
            }
            else
            {
                GridView2.DataSource = client.GetProjectTasks(Convert.ToInt32(Session["ProjectID"].ToString()));
                GridView2.DataBind();
            }

            client.Close();
        }
    }

    protected void GridView2_RowUpdated(object sender, GridViewUpdatedEventArgs e)
    {

    }
    protected void GridView2_RowEditing(object sender, GridViewEditEventArgs e)
    {

    }
    protected void btnPrevious_Click(object sender, EventArgs e)
    {
        btnPrevious.CommandArgument = "View1";
        btnPrevious.CommandName = "SwitchViewByID";
    }
}