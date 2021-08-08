#include "Product.h"


class Creator {
public:
	virtual Product* Create(int ProductId)=0;
	virtual ~Creator() {}
};
