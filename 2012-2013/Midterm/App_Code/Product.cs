using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Summary description for Product
/// </summary>
public class Product
{
    private string pDescription;
    private double pUnitPrice;
    private int pOnHandQuantity;
    private int pQuantityOrdered;
    private string pProductCode;

	public Product()
	{
        description = "";
        UnitPrice = 0;
        OnHand = 0;
        QuantityOrdered = 0;
        productCode = "";
	}

    public Product(string vDescription, double vUnitPrice, int vOnHandQuantity, int vQuantityOrdered, string vProductCode)
    {
        description = vDescription;
        UnitPrice = vUnitPrice;
        OnHand = vOnHandQuantity;
        QuantityOrdered = vQuantityOrdered;
        productCode = vProductCode;
    }

    public string description
    {
        get
        {
            return pDescription;
        }
        set
        {
            pDescription = value;
        }
    }

    public double UnitPrice
    {
        get
        {
            return pUnitPrice;
        }
        set
        {
            pUnitPrice = value;
        }
    }

    public int OnHand
    {
        get
        {
            return pOnHandQuantity;
        }
        set
        {
            pOnHandQuantity = value;
        }
    }

    public int QuantityOrdered
    {
        get
        {
            return pQuantityOrdered;
        }
        set
        {
            pQuantityOrdered = value;
        }
    }

    public string productCode
    {
        get
        {
            return pProductCode;
        }
        set
        {
            pProductCode = value;
        }
    }
}