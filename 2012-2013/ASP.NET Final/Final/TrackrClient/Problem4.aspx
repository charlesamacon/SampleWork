<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Problem4.aspx.cs" Inherits="Default2" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:MultiView ID="MultiView1" runat="server" ActiveViewIndex="0">
        <asp:View ID="View1" runat="server">
            <h1>Select A Project:</h1>
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AutoGenerateColumns="False" BackColor="White" BorderColor="#DEDFDE" BorderStyle="None" BorderWidth="1px" CellPadding="4" ForeColor="Black" GridLines="Vertical" >
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="ProjectID" HeaderText="Project ID" InsertVisible="false" ReadOnly="true" SortExpression="ProjectID" />
                    <asp:BoundField DataField="ProjectName" HeaderText="Project Name" InsertVisible="false" ReadOnly="true" SortExpression="ProjectName" />
                    <asp:CommandField ButtonType="Button" ShowSelectButton="true" />
                </Columns>
                <FooterStyle BackColor="#CCCC99" />
                <HeaderStyle BackColor="#6B696B" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#F7F7DE" ForeColor="Black" HorizontalAlign="Right" />
                <RowStyle BackColor="#F7F7DE" />
                <SelectedRowStyle BackColor="#CE5D5A" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#FBFBF2" />
                <SortedAscendingHeaderStyle BackColor="#848384" />
                <SortedDescendingCellStyle BackColor="#EAEAD3" />
                <SortedDescendingHeaderStyle BackColor="#575357" />
            </asp:GridView>
            <asp:Label ID="lblError" runat="server" ForeColor="Red"></asp:Label>
            <br />
            <asp:Button ID="btnNext" runat="server" Text="Next" OnClick="btnNext_Click" />
            <br />
        </asp:View>
        <asp:View ID="View2" runat="server">
            <h1>View Tasks:</h1>
            <asp:Label ID="lblError2" runat="server" ForeColor="Red"></asp:Label>
            <br />
            <asp:GridView ID="GridView2" runat="server" AllowPaging="true" AutoGenerateColumns="false" 
                DataKeyNames="ProjectID" BackColor="White" BorderColor="#DEDFDE" BorderStyle="None" 
                BorderWidth="1px" CellPadding="4" ForeColor="Black" GridLines="Vertical" 
                OnRowEditing="GridView2_RowEditing" OnRowUpdated="GridView2_RowUpdated">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:TemplateField HeaderText="Task ID" SortExpression="TaskID">
                        <EditItemTemplate>
                            <asp:Label ID="lblTaskID" runat="server" Text='<%# Bind("TaskID") %>'></asp:Label>
                        </EditItemTemplate>
                        <HeaderStyle HorizontalAlign="Left" />
                        <ItemStyle Width="50px" />
                        <ItemTemplate>
                            <asp:Label ID="lblTaskID2" runat="server" Text='<%# Bind("TaskID") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Task Title" SortExpression="TaskTitle">
                        <EditItemTemplate>
                            <asp:Label ID="lblTaskTitle" runat="server" Text='<%# Bind("TaskTitle") %>'></asp:Label>
                        </EditItemTemplate>
                        <HeaderStyle HorizontalAlign="Left" />
                        <ItemStyle Width="150px" />
                        <ItemTemplate>
                            <asp:Label ID="lblTaskTitle2" runat="server" Text='<%# Bind("TaskTitle") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Task Description" SortExpression="TaskDescription">
                        <EditItemTemplate>
                            <asp:Label ID="lblTaskDescription" runat="server" Text='<%# Bind("TaskDescription") %>'></asp:Label>
                        </EditItemTemplate>
                        <HeaderStyle HorizontalAlign="Left" />
                        <ItemStyle Width="400px" />
                        <ItemTemplate>
                            <asp:Label ID="lblTaskDescription2" runat="server" Text='<%# Bind("TaskDescription") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="Date Opened" SortExpression="DateOpened">
                        <EditItemTemplate>
                            <asp:Label ID="lblDateOpened" runat="server" Text='<%# Bind("DateOpened") %>'></asp:Label>
                        </EditItemTemplate>
                        <HeaderStyle HorizontalAlign="Left" />
                        <ItemStyle Width="150px" />
                        <ItemTemplate>
                            <asp:Label ID="lblDateOpened2" runat="server" Text='<%# Bind("DateOpened") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                </Columns>
                <FooterStyle BackColor="#CCCC99" />
                <HeaderStyle BackColor="#6B696B" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#F7F7DE" ForeColor="Black" HorizontalAlign="Right" />
                <RowStyle BackColor="#F7F7DE" />
                <SelectedRowStyle BackColor="#CE5D5A" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#FBFBF2" />
                <SortedAscendingHeaderStyle BackColor="#848384" />
                <SortedDescendingCellStyle BackColor="#EAEAD3" />
                <SortedDescendingHeaderStyle BackColor="#575357" />
            </asp:GridView>
            <br />
            <asp:Button ID="btnPrevious" runat="server" Text="Previous" OnClick="btnPrevious_Click" />
        </asp:View>
    </asp:MultiView>
</asp:Content>

