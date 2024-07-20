
// Função que calcula o fatorial de um número
double private_lua_cembed_factorial(int n) {
    if (n <= 1) {
        return 1.0;
    }
    double resultado = 1.0;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

// Função que calcula o seno de um ângulo (em radianos)
double private_lua_cembed_sin(double x) {
    double resultado = 0.0;
    int n = 0;
    double termo = x;
    double termo_atual = termo;
    double termo_quadrado = termo * termo;

    while (termo_atual > 1.0e-15) {
        resultado += termo_atual;
        n += 2;
        termo *= -termo_quadrado / ((n + 1) * (n + 2));
        termo_atual = termo / private_lua_cembed_factorial(n);
    }

    return resultado;
}

// Função que calcula o cosseno de um ângulo (em radianos)
double private_lua_cembed_cos(double x) {
    double resultado = 0.0;
    int n = 0;
    double termo = 1.0;
    double termo_atual = termo;
    double termo_quadrado = termo * termo;

    while (termo_atual > 1.0e-15) {
        resultado += termo_atual;
        n += 2;
        termo *= -termo_quadrado / (n * (n + 1));
        termo_atual = termo / private_lua_cembed_factorial(n);
    }

    return resultado;
}

// Função que calcula a tangente de um ângulo (em radianos)
double private_lua_cembed_tan(double x) {
    return private_lua_cembed_sin(x) / private_lua_cembed_cos(x);
}


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