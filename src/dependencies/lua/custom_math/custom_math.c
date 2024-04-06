double private_lua_embed_fmod(double x, double y) {
    // Enquanto o divisor não for zero
    while (y != 0.0) {
        // Reduzimos o dividendo até que ele se torne menor que o divisor
        while (x >= y) {
            x -= y;
        }
        // Se x já é menor que y, então x é o resto da divisão
        if (x < y) {
            return x;
        }
    }
    // Se o divisor é zero, retorna NaN (Not a Number)
    return 0.0 / 0.0;
}