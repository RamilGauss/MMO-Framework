

- Доработать VariableDeclarationLexema для случая:
Type x0, ..., xn;
Type x0 = 0, ..., xn = 0;
Копить внутри VariableDeclarationLexema массив из структур и в конвертере создавать несколько member.