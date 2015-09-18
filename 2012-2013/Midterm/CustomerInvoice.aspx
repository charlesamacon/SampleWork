<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="CustomerInvoice.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:DropDownList ID="ddlCustomer" runat="server" AppendDataBoundItems="True" AutoPostBack="True" DataSourceID="SqlDataSource1" DataTextField="Name" DataValueField="CustomerID">
    </asp:DropDownList>
    <br />
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="InvoiceID" DataSourceID="SqlDataSource2">
        <Columns>
            <asp:BoundField DataField="InvoiceID" HeaderText="InvoiceID" InsertVisible="False" ReadOnly="True" SortExpression="InvoiceID" />
            <asp:BoundField DataField="CustomerID" HeaderText="CustomerID" SortExpression="CustomerID" />
            <asp:BoundField DataField="InvoiceDate" HeaderText="InvoiceDate" SortExpression="InvoiceDate" />
            <asp:BoundField DataField="ProductTotal" HeaderText="ProductTotal" SortExpression="ProductTotal" />
            <asp:BoundField DataField="SalesTax" HeaderText="SalesTax" SortExpression="SalesTax" />
            <asp:BoundField DataField="Shipping" HeaderText="Shipping" SortExpression="Shipping" />
            <asp:BoundField DataField="InvoiceTotal" HeaderText="InvoiceTotal" SortExpression="InvoiceTotal" />
        </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:MMABooksConnectionString %>" SelectCommand="SELECT InvoiceID, CustomerID, InvoiceDate, ProductTotal, SalesTax, Shipping, InvoiceTotal FROM Invoices WHERE (CustomerID = @CustomerID)">
        <SelectParameters>
            <asp:ControlParameter ControlID="ddlCustomer" Name="CustomerID" PropertyName="SelectedValue" />
        </SelectParameters>
    </asp:SqlDataSource>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:MMABooksConnectionString %>" SelectCommand="SELECT * FROM [Customers]"></asp:SqlDataSource>
</asp:Content>

