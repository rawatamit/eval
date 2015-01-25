#include "IR/Types.h"

IntegerType::IntegerType() {
    itype_ = new Type(TypeID::IntegerTy);
}
