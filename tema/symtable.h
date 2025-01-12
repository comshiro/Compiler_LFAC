#ifndef SYMTABLE_H
#define SYMTABLE_H
#include <unistd.h>
#include <string>
#include <unordered_map>
#include <vector>

struct VariableInfo {
    std::string type;
    std::string name;
    std::string value;
};

struct FunctionInfo {
    std::string name;
    std::string returnType;
    std::vector<std::string> paramTypes;
    std::string className;
};

struct ClassInfo {
    std::string name;
};

class SymTable {
public:
    std::string name;
    std::unordered_map<std::string, VariableInfo> variables;
    std::unordered_map<std::string, FunctionInfo> functions;
    std::unordered_map<std::string, ClassInfo> classes;
    SymTable* parent;

    SymTable(std::string name, SymTable* parent = nullptr)
        : name(name), parent(parent) {}

    void insertVariable(std::string type, std::string name, std::string value = "") {
        variables[name] = {type, name, value};
    }

    void insertFunction(std::string name, std::string returnType, std::vector<std::string> paramTypes, std::string className = "") {
        functions[name] = {name, returnType, paramTypes, className};
    }

    void insertClass(std::string name) {
        classes[name] = {name};
    }

    SymTable* findScope(std::string name) {
        if (this->name == name) return this;
        if (parent) return parent->findScope(name);
        return nullptr;
    }

    void print(std::ostream& out) {
    std::string output;

    output += "Scope: " + name + "\n";

    output += "Variables:\n";
    for (const auto& var : variables) {
        output += "  " + var.second.type + " " + var.second.name + " = " + var.second.value + "\n";
    }

    output += "Functions:\n";
    for (const auto& func : functions) {
        output += "  " + func.second.returnType + " " + func.second.name + "(";
        for (const auto& param : func.second.paramTypes) {
            output += param + " ";
        }
        output += ") in class " + func.second.className + "\n";
    }

    output += "Classes:\n";
    for (const auto& cls : classes) {
        output += "  " + cls.second.name + "\n";
    }

    write(STDOUT_FILENO, output.c_str(), output.size());
}

#endif // SYMTABLE_H