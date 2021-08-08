#include "Product.h"
class ProductB : public Product
{
public:
	virtual const char* GetName();
	virtual ~ProductB() {}
	// virtual int GetPrice()...
};
