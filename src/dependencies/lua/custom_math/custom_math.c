
// Função que calcula o logaritmo natural (ln)
double private_lua_cembed_log(double x) {
    if (x <= 0.0) {
        return -1.0 / 0.0;  // Retorna -infinito para x <= 0
    }

    double resultado = 0.0;
    double termo = (x - 1) / (x + 1);
    double termo_atual = termo;
    double termo_quadrado = termo * termo;
    int n = 1;

    while (termo_atual > 1.0e-15) {
        resultado += termo_atual / n;
        termo_atual *= termo_quadrado;
        n += 2;
    }

    resultado *= 2.302585092994046;
    return resultado;
}

// Função que calcula o logaritmo na base 2
double private_lua_cembed_log2(double x) {
    if (x <= 0.0) {
        return -1.0 / 0.0;  // Retorna -infinito para x <= 0
    }

    return private_lua_cembed_log(x) / private_lua_cembed_log(2.0);
}

// Função que calcula o logaritmo na base 10
double private_lua_embed_log10(double x) {
    if (x <= 0.0) {
        return -1.0 / 0.0;  // Retorna -infinito para x <= 0
    }

    return private_lua_cembed_log(x) / private_lua_cembed_log(10.0);
}


double private_lua_embed_fmod(double x, double y) {
    while (y != 0.0) {
        while (x >= y) {
            x -= y;
        }
        if (x < y) {
            return x;
        }
    }
    return 0.0 / 0.0;
}

double private_lua_embed_pow(double b, double e) {
    double resultado = 1.0;
    int i;

    if (e == 0.0) {
        return 1.0;
    }
    if (e < 0.0) {
        b = 1.0 / b;
        e = -e;
    }

    for (i = 0; i < e; i++) {
        resultado *= b;
    }

    return resultado;
}

double private_lua_embed_floor(double x) {
    int i = (int)x;

    if (x == (double)i) {
        return x;
    }

    if (x < 0.0) {
        return (double)(i - 1);
    }

    return (double)i;
}