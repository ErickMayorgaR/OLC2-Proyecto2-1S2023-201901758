QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Environment/ast.cpp \
    Environment/environment.cpp \
    Environment/func_symbol.cpp \
    Environment/symbol.cpp \
    Expression/access.cpp \
    Expression/array_access.cpp \
    Expression/call_exp.cpp \
    Expression/expression_array.cpp \
    Expression/func_atof.cpp \
    Expression/func_atoi.cpp \
    Expression/func_iota.cpp \
    Expression/list_expression.cpp \
    Expression/map_struct_dec.cpp \
    Expression/operation.cpp \
    Expression/primitive.cpp \
    Expression/struct_access.cpp \
    Instruction/assign.cpp \
    Instruction/call_inst.cpp \
    Instruction/create_struct.cpp \
    Instruction/declare.cpp \
    Instruction/declare_struct.cpp \
    Instruction/func_break.cpp \
    Instruction/func_continue.cpp \
    Instruction/func_expression.cpp \
    Instruction/func_for.cpp \
    Instruction/func_if.cpp \
    Instruction/func_main.cpp \
    Instruction/func_return.cpp \
    Instruction/func_while.cpp \
    Instruction/function.cpp \
    Instruction/list_instruction.cpp \
    Instruction/print.cpp \
    Interfaces/expression.cpp \
    Interfaces/instruction.cpp \
    Parser/lex.yy.c \
    Parser/parser.cpp \
    main.cpp \
    mainwindow.cpp \
    parserctx.cpp

HEADERS += \
    Environment/ast.hpp \
    Environment/environment.hpp \
    Environment/func_symbol.hpp \
    Environment/symbol.hpp \
    Environment/type.h \
    Expression/access.hpp \
    Expression/array_access.hpp \
    Expression/call_exp.hpp \
    Expression/expression_array.hpp \
    Expression/func_atof.hpp \
    Expression/func_atoi.hpp \
    Expression/func_iota.hpp \
    Expression/list_expression.hpp \
    Expression/map_struct_dec.hpp \
    Expression/operation.hpp \
    Expression/primitive.hpp \
    Expression/struct_access.hpp \
    Instruction/assign.hpp \
    Instruction/call_inst.hpp \
    Instruction/create_struct.hpp \
    Instruction/declare.hpp \
    Instruction/declare_struct.hpp \
    Instruction/func_break.hpp \
    Instruction/func_continue.hpp \
    Instruction/func_expression.hpp \
    Instruction/func_for.hpp \
    Instruction/func_if.hpp \
    Instruction/func_main.hpp \
    Instruction/func_return.hpp \
    Instruction/func_while.hpp \
    Instruction/function.hpp \
    Instruction/list_instruction.hpp \
    Instruction/print.hpp \
    Interfaces/expression.hpp \
    Interfaces/instruction.hpp \
    Parser/lexer.l \
    Parser/location.hh \
    Parser/parser.hpp \
    Parser/parser.y \
    Parser/position.hh \
    Parser/stack.hh \
    mainwindow.hpp \
    parserctx.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Parser/parser.output
