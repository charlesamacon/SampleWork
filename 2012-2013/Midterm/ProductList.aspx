<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="ProductList.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:DropDownList ID="ddlProduct" runat="server" DataSourceID="SqlDataSource1" DataTextField="Description" DataValueField="ProductCode" AutoPostBack="True">
</asp:DropDownList>
<asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:MMABooksConnectionString %>" SelectCommand="SELECT [ProductCode], [Description], [UnitPrice], [OnHandQuantity] FROM [Products]"></asp:SqlDataSource>
    <br />
    <asp:Label ID="Label1" runat="server" Text="Description:"></asp:Label>
&nbsp;<asp:TextBox ID="txtDescription" runat="server" Width="386px"></asp:TextBox>
    <br />
    <asp:Label ID="Label2" runat="server" Text="Unit Price:"></asp:Label>
&nbsp;
&nbsp;<asp:TextBox ID="txtUnitPrice" runat="server" Width="386px"></asp:TextBox>
    <br />
    On Hand:&nbsp;&nbsp;&nbsp;
    <asp:TextBox ID="txtOnHand" runat="server" Width="386px"></asp:TextBox>
    <br />
    Quantity:&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:TextBox ID="txtQuantityOrdered" runat="server" Width="386px"></asp:TextBox>
    <br />
    <br />
    <asp:Button ID="btnAdd" runat="server" OnClick="btnAdd_Click" Text="Add to Product List" />
&nbsp;&nbsp;&nbsp;&nbsp;
    <asp:Button ID="btnDisplay" runat="server" PostBackUrl="~/Cart.aspx" Text="Display Product List" />
</asp:Content>

