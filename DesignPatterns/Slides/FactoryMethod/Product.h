#ifndef PRODUCT_H
#define PRODUCT_H
class Product
{
public:
	virtual const char* GetName() = 0;
	virtual  ~Product() {}
};
#endif
