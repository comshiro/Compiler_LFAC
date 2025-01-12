#ifndef AST_H
#define AST_H

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual double evaluate() = 0;
    virtual bool isInteger() = 0;
};

class NumberNode : public ASTNode {
    double value;
    bool isInt;
public:
    NumberNode(double v, bool isInteger) : value(v), isInt(isInteger) {}
    double evaluate() override { return value; }
    bool isInteger() override { return isInt; }
};

class BinaryOpNode : public ASTNode {
    char op;
    ASTNode *left, *right;
public:
    BinaryOpNode(char op, ASTNode* l, ASTNode* r) : op(op), left(l), right(r) {}
    ~BinaryOpNode() { delete left; delete right; }
    
    double evaluate() override {
        switch(op) {
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
            case '%': return (int)left->evaluate() % (int)right->evaluate();
            default: return 0;
        }
    }
    bool isInteger() override {
        return left->isInteger() && right->isInteger();
    }
};

class UnaryNode : public ASTNode {
    char op;
    ASTNode* child;
public:
    UnaryNode(char op, ASTNode* c) : op(op), child(c) {}
    ~UnaryNode() { delete child; }
    
    double evaluate() override {
        return -child->evaluate();
    }
    bool isInteger() override {
        return child->isInteger();
    }
};