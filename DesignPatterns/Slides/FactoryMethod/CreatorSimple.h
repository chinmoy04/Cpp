#include "Creator.h"
#include "Product.h"
enum { PRODUCT_A, PRODUCT_B };


class CreatorSimple : public Creator
{
public:
	virtual Product* Create(int ProductId);
	virtual ~CreatorSimple() {}
};
