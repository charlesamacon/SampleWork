<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Problem5.aspx.cs" Inherits="Default2" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <h1>Want to hear about the latest in Trackr Development Services?</h1>
    <h3>Join our newsletter!</h3>
    <label for="txtEmail">Email Address:</label>
    <asp:TextBox ID ="txtEmail" runat="server"></asp:TextBox><br />
    <asp:Button ID ="btnEmail" runat="server" Text="Subscribe!" OnClick="btnEmail_click" />
</asp:Content>

