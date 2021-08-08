#include "CreatorSimple.h"
#include "ProductA.h"
#include "ProductB.h"


Product* CreatorSimple::Create(int id)
{
	if (id == PRODUCT_A) return new ProductA();
	if (id == PRODUCT_B) return new ProductB();
	// repeat for other products...
	return 0;
}
