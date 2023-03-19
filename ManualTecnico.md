# ORGANIZACION DE LENGUAJES Y COMPILADORES 2 - Proyecto 1 - Manual Técnico

| Nombre                           | Carné                                      |
|:--------------------------------:|:------------------------------------------:|
| Erick Ivan Mayorga Rodríguez     | 201901758                                 	|

## INTRODUCCIÓN

Se realizo un compilador para un lenguaje de programación de alto nivel enfocado a la ciencia de datos utilizando Bison y Flex. Para la consola se utilizó Qt tomando en cuenta que se muestra tanto la ejecución del programa en consola, la tabla de errores, la tabla de símbolos y el árbol AST. 

## Ambiente del compilador

### Guardar variables, vectores, structs, y funciones
<img src="./Imagenes/SaveVariable.png" alt="drawing"/>

### Asignar variables
<img src="./Imagenes/AssignVariable.png" alt="drawing"/>

### Obtener variables, structs y funciones
<img src="./Imagenes/GetVariable.png" alt="drawing"/>

### Tabla de símbolos
<img src="./Imagenes/SymbolTable.png" alt="drawing"/>

### Tabla de errores 
<img src="./Imagenes/ErrorTable.png" alt="drawing"/>

### Crear árbol AST en formato .dot
<img src="./Imagenes/GenerateAST.png" alt="drawing"/>

### Tipo de datos
<img src="./Imagenes/TypeData.png" alt="drawing"/>

### Símbolos
<img src="./Imagenes/Symbol.png" alt="drawing"/>


## Expresiones del compilador

### Acceso a Identificadores
<img src="./Imagenes/Access.png" alt="drawing"/>

### Operaciones aritméticas, relacionales y lógicas
<img src="./Imagenes/Operation.png" alt="drawing"/>

### Acceso a vectores 
<img src="./Imagenes/VectorAccess.png" alt="drawing"/>

### Acceso a structs 
<img src="./Imagenes/StructAccess.png" alt="drawing"/>

### Acceso a matrices 
<img src="./Imagenes/MatrixAccess.png" alt="drawing"/>

### Función size 
<img src="./Imagenes/Size.png" alt="drawing"/>

### Función get 
<img src="./Imagenes/Get.png" alt="drawing"/>

### Función media 
<img src="./Imagenes/Mean.png" alt="drawing"/>

### Función mediana 
<img src="./Imagenes/Median.png" alt="drawing"/>

### Función moda 
<img src="./Imagenes/Mode.png" alt="drawing"/>

### Función iota 
<img src="./Imagenes/IOTA.png" alt="drawing"/>

### Función atof 
<img src="./Imagenes/ATOF.png" alt="drawing"/>

### Función atoi 
<img src="./Imagenes/ATOI.png" alt="drawing"/>


## Instrucciones del compilador
### Asignación de variables 
<img src="./Imagenes/Assign.png" alt="drawing"/>

### Función main  
<img src="./Imagenes/Main.png" alt="drawing"/>

### Función If
<img src="./Imagenes/func_if.png" alt="drawing"/>

### Función For
<img src="./Imagenes/func_for.png" alt="drawing"/>

### Función While
<img src="./Imagenes/func_while.png" alt="drawing"/>

### Función Printf
<img src="./Imagenes/Printf.png" alt="drawing"/>

### Declaración de funciones
<img src="./Imagenes/Function.png" alt="drawing"/>

### Función pushback
<img src="./Imagenes/func_pushback.png" alt="drawing"/>

### Función pushfront
<img src="./Imagenes/func_pushfront.png" alt="drawing"/>

### Función remove
<img src="./Imagenes/func_remove.png" alt="drawing"/>

### Función Return
<img src="./Imagenes/func_return.png" alt="drawing"/>

### Función Break
<img src="./Imagenes/func_break.png" alt="drawing"/>

### Función Continue
<img src="./Imagenes/func_continue.png" alt="drawing"/>

### Declaración de variables
<img src="./Imagenes/Declare.png" alt="drawing"/>

### Creación de structs
<img src="./Imagenes/Create_struct.png" alt="drawing"/>


## Interfaces del compilador
### Interfaz para las expresiones 
<img src="./Imagenes/Expression.png" alt="drawing"/>

### Interfaz para las intrucciones 
<img src="./Imagenes/Instruction.png" alt="drawing"/>


## Parser 
### Análisis sintáctico 
<img src="./Imagenes/Parser.png" alt="drawing"/>

### Análisis léxico
<img src="./Imagenes/Lexer.png" alt="drawing"/>


## Main en Qt 
<img src="./Imagenes/MainWindow.png" alt="drawing"/>

## ParserCtx en Qt 
<img src="./Imagenes/ParserCtx.png" alt="drawing"/>
