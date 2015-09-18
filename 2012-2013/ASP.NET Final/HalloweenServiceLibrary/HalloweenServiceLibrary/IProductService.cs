using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace HalloweenServiceLibrary
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IProductService
    {
        [OperationContract]
        List<Category> GetCategories();

        [OperationContract]
        List<Product> GetProducts(string categoryid);

        // TODO: Add your service operations here
    }

    // Use a data contract as illustrated in the sample below to add composite types to service operations.
    // You can add XSD files into the project. After building the project, you can directly use the data types defined there, with the namespace "HalloweenServiceLibrary.ContractType".
    [DataContract]
    public class Product
    {
        string productID = "";
        string name = "";
        decimal unitPrice = 0m;
        int onHand = 0;

        [DataMember]
        public string ProductID
        {
            get { return productID; }
            set { productID = value; }
        }

        [DataMember]
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        [DataMember]
        public decimal UnitPrice
        {
            get { return unitPrice; }
            set { unitPrice = value; }
        }
        [DataMember]
        public int OnHand
        {
            get { return onHand; }
            set { onHand = value; }
        }
    }
    [DataContract]
    public class Category
    {
        string categoryID = "";
        string longName = "";

        [DataMember]
        public string CategoryID
        {
            get { return categoryID; }
            set { categoryID = value; }
        }
        [DataMember]
        public string LongName
        {
            get { return longName; }
            set { longName = value; }
        }
    }
}
