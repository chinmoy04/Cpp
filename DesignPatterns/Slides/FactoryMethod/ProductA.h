#include "Product.h"
class ProductA : public Product
{
public:
	virtual const char* GetName();
	virtual ~ProductA() {}
	// virtual int GetPrice()...
};
