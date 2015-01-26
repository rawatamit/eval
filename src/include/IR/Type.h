#ifndef TYPE_H
#define TYPE_H

class IntegerType;
class PointerType;

class Type {
public:
    enum TypeID {
        VoidTy = 0,
        IntegerTy,
        LabelTy,
        PointerTy,
    };

private:
    TypeID typeid_;
    static Type* voidtype_;
    static Type* labeltype_;

protected:
    Type(TypeID tid);
    
public:
    virtual ~Type();
    TypeID getTypeID() const;
    bool isIntegerTy() const;
    bool isLabelTy() const;
    bool isPointerTy() const;
    
    // builtin types
    static Type* getVoidTy();
    static IntegerType* getInt64Ty();
    static Type* getLabelTy();
    static PointerType* getInt64PtrTy();
};

// IntegerType
class IntegerType : public Type {
private:
    static IntegerType* i64type_;
    IntegerType();
    IntegerType(IntegerType const&) = delete;
    void operator=(IntegerType const&) = delete;

public:
    virtual ~IntegerType();
    static IntegerType* get(unsigned bits);
    unsigned getBitWidth() const;
};

// PointerType
class PointerType : public Type {
private:
    static PointerType* i64ptype_;
    PointerType();
    PointerType(PointerType const&) = delete;
    void operator=(PointerType const&) = delete;
public:
    virtual ~PointerType();
    static PointerType* getInt64PtrTy();
};

#endif
