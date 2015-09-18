using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace HalloweenServiceLibrary
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class ProductService : IProductService
    {
        public List<Category> GetCategories()
        {
            return CategoryDB.GetCategories();
        }

        public List<Product> GetProducts(string categoryid)
        {
            return ProductDB.GetProducts(categoryid);
        }
    }
}
