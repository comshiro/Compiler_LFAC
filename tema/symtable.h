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
    std::string className;
};

struct FunctionInfo {
    std::string name;
    std::string returnType;
    std::vector<std::string> paramTypes;
    std::string className;
};

struct ClassInfo {
    std::string name;
    std::unordered_map<std::string, VariableInfo> memberVariables;
    std::unordered_map<std::string, FunctionInfo> memberFunctions;
};

class SymTable {
public:
    std::string name;
    std::unordered_map<std::string, VariableInfo> variables;
    std::unordered_map<std::string, FunctionInfo> functions;
    std::unordered_map<std::string, ClassInfo> classes;
    SymTable* parent;
    std::vector<SymTable*> children;

    SymTable(std::string name, SymTable* parent = nullptr)
        : name(name), parent(parent) {}

    void insertVariable(std::string type, std::string name, std::string value = "", std::string className = "") {
        variables[name] = {type, name, value, className};
    }

    void insertFunction(std::string name, std::string returnType, std::vector<std::string> paramTypes, std::string className = "") {
        functions[name] = {name, returnType, paramTypes, className};
    }

    void insertClass(std::string name) {
        classes[name] = {name, {}, {}};
    }

   VariableInfo* lookupVariable(const std::string& name) {
        if (variables.find(name) != variables.end()) {
            return &variables[name];
        } else {
            return nullptr;
        }
    }

    FunctionInfo* lookupFunction(const std::string& name) {
        if (functions.find(name) != functions.end()) {
            return &functions[name];
        } else {
            return nullptr;
        }
    }

    ClassInfo* lookupClass(const std::string& name) {
        if (classes.find(name) != classes.end()) {
            return &classes[name];
        } else {
            return nullptr;
        }
    }

    bool isVariableInCurrentScope(const std::string& name) {
        return variables.find(name) != variables.end();
    }

    bool areVariablesInSameScope(const std::string& name1, const std::string& name2) {
        return variables.find(name1) != variables.end() && variables.find(name2) != variables.end();
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
};
#endif // SYMTABLE_H