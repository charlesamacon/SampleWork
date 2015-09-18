<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Cart.aspx.cs" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:Label ID="Label1" runat="server" Text="Product List"></asp:Label>
     <table>
        <tr>
            <td>
                
                <asp:ListBox ID ="lstCart" runat="server" Height="135px" Width="600px"></asp:ListBox>
            </td>
            <td>
                <asp:Button ID="btnRemove" runat="server" Text="Remove Item" Width="100px" OnClick="btnRemove_Click" />
                <br />
                <br />
                <asp:Button ID="btnEmpty" runat="server" Text="Empty List" Width="100px" OnClick="btnEmpty_Click" />
            <br />
            </td>
        </tr>
    </table>
    <br />
    <asp:Button ID="btnContinue" runat="server" Text="Select Additional Product" PostBackUrl="~/ProductList.aspx" />
&nbsp;&nbsp;&nbsp; 
</asp:Content>

