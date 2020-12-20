#include <cstdio>

/**
 * Al hacer un enum class, lo envuelve como si fuera espacio de nombre, al usarse se debera
 * que utilzar el operador ::, Operation::Add .
 */
enum class Operation{
    Add,
    Subtract,
    Multiply,
    Divide
};


/**
 * Por defecto, al ser una estructura todos los metodos y miembros
 * seran publicos, a diferencia de con la keyword class todos metodos
 * y miembros seran private by default.
 */
struct Calculator {
    
    Calculator(Operation operation) {
        this->operation = operation;
    }

    int calculate(int operator1, int operator2) {
        int result{}; // Inicializador by braces, inicializa a cero 
        switch(getOperation()) {
            
        case Operation::Add:
            result = operator1 + operator2;
            break;
        case Operation::Subtract:
            result = operator2 - operator1;
            break;
        
        case Operation::Multiply: {
            result = operator1 * operator2;
            break;
        }
       case Operation::Divide: {
           result = operator1 / operator2;
       }
           break;
        }
        
        return result;
    }

    /**
     * La keyword const garantiza que el valor no sera
     * modificado adentro del metodo.
     */
    Operation getOperation() const {
        return this->operation;
    }

private:
    const char* name = {"Calculator"};    
    Operation operation;    
};

int main() {
    Calculator calculatorAdd { Operation::Add };
    Calculator calculatorMultiply = {Operation::Multiply};
    Calculator calculatorSustract (Operation::Subtract);
    Calculator calculatorDivide{Operation::Divide};
   
    printf("3 + 5 = %d\n", calculatorAdd.calculate(3, 5));
    printf("3 + 5 = %d\n", calculatorSustract.calculate(3, 5));
    printf("3 + 5 = %d\n", calculatorMultiply.calculate(3, 5));
    printf("15 + 5 = %d\n", calculatorDivide.calculate(15, 5));
    
    return 0;
}    
