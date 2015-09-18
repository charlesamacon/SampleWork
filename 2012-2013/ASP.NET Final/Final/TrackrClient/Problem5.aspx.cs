using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Net.Mail;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btnEmail_click(object sender, EventArgs e)
    {
        MailAddress toadd = new MailAddress(txtEmail.Text);
        MailAddress fromadd = new MailAddress("newsletter@trackr.org");
        MailMessage msg = new MailMessage(fromadd, toadd);

        msg.Subject = "Trackr.org Newsletter";

        msg.Body = "Thank you for subscribing to the Trackr.org Newletter. You will be recieving our first issue soon!";

        SmtpClient client = new SmtpClient("localhost");

        client.Send(msg);
    }
}