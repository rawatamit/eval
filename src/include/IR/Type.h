#ifndef TYPE_H
#define TYPE_H

class Type {
public:
    enum TypeID {
        IntegerTy = 0,
    };

private:
    TypeID typeid_;

protected:
    Type(TypeID tid);
    
public:
    virtual ~Type();
    TypeID getTypeID() const;
    bool isIntegerTy() const;
};

#endif
