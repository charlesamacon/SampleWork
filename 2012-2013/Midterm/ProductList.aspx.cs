using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

public partial class _Default : System.Web.UI.Page
{

    protected Product selectedProduct;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            ddlProduct.DataBind();
        }

        selectedProduct = this.GetProduct();
        this.FillTextBoxes(selectedProduct);
    }

    private Product GetProduct()
    {
        // Get selected Product
        DataView productTable = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
        productTable.RowFilter = "ProductCode = '" + ddlProduct.SelectedValue +"'";
        DataRowView row = (DataRowView)productTable[0];

        // Create an instance of the Product class
        Product product = new Product();
        product.productCode = row["ProductCode"].ToString();
        product.OnHand = Convert.ToInt32(row["OnHandQuantity"]);
        product.description = row["Description"].ToString();
        product.UnitPrice = Convert.ToInt32(row["UnitPrice"]);

        return product;
    }

    protected void FillTextBoxes(Product p)
    {
        txtDescription.Text = p.description;
        txtOnHand.Text = p.OnHand.ToString();
        txtUnitPrice.Text = p.UnitPrice.ToString();
    }
    protected void btnAdd_Click(object sender, EventArgs e)
    {
        if (Page.IsValid && txtQuantityOrdered.Text != null)
        {
            int quantity = Convert.ToInt32(txtQuantityOrdered.Text);

            CartItemList cart = CartItemList.GetCart();
            CartItem cartItem = cart[selectedProduct.productCode];
            if (cartItem == null)
            {
                cart.AddItem(selectedProduct, quantity);
            }
            else
            {
                cartItem.AddQuantity(quantity);
            }
            Response.Redirect("Cart.aspx");
        }
    }
}