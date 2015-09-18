<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
    <style type="text/css">
        .auto-style1 {
            width: 297px;
            height: 170px;
        }
        .auto-style2 {
            width: 798px;
            height: 163px;
        }
    </style>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <h1>What is trackr?</h1><hr />
    <p>Trackr is a simple way of tracking and managing project tasks. A nice "roadmap", as it were, to help you complete your project goals more effectively.</p>
    <h1>Why trackr?</h1><hr />
    <p>Honestly, this is just a project that I've been trying to implement on my own for a while.
         I am going to continue and refine this site past the end of this semester.
         I've been looking for a simple method of keeping track of my various development goals in various things that I'm working on, and this
        seems to be a pretty good fit.
    </p>
    <p>
        What better way is there to show that I've learned the material (even though I've had to miss several classes) than by creating
        a website that <i>I will actually use on a daily basis</i> using the processes that I've learned this semester?
    </p>
    <p>
        By using trackr, I will be able to more effectively track my "tickets", as it were, in all of the "projects" that I'm currently working on.
    </p>
    <h1>It's Simple:</h1>
    <hr />
    <p>
        Ordinarily, there would be some method of authentication where one could log in and access their own projects. However, given the scope of the final,
        there is no need for that here.
    </p>
    <h3>Select Your Project:</h3>
    <p>
        <img class="auto-style1" src="project.jpg" /></p>
    <h3>View Your Tickets!</h3>
    <p>
        <img class="auto-style2" src="tasks.jpg" /></p>
</asp:Content>


