#include <vector>
#include "algobot.h"

#include <set>

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> sin_repetidos;
    for(int elem : s) {
        if(!std::count(sin_repetidos.begin(), sin_repetidos.end(), elem)) {
            sin_repetidos.push_back(elem);
        }
    }
    return sin_repetidos;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> sin_repetidos;
    for(int elem: s) {
        sin_repetidos.insert(elem);
    }
    std::vector<int> v(sin_repetidos.begin(), sin_repetidos.end());
    return v;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    for(int elem: a) {
        if(!std::count(b.begin(), b.end(), elem)) {
            return false;
        }
    }
    for(int elem: b) {
        if(!std::count(a.begin(), a.end(), elem)) {
            return false;
        }
    }
    return true;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    a = quitar_repetidos_v2(a);
    b = quitar_repetidos_v2(b);
    return a == b;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> mapa;
    for(int elem: s) {
        if(mapa.count(elem) != 1) {
            mapa[elem] = 0;
        }
        mapa[elem] += 1;
    }
    return mapa;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int, int> apariciones = contar_apariciones(s);
    vector<int> output;
    for(auto keyValue: apariciones) {
        if(keyValue.second == 1) {
            output.push_back(keyValue.first);
        }
    }
    return output;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> output;
    for(int elem: a) {
        if(std::count(b.begin(), b.end(), elem)) {
            output.insert(elem);
        }
    }
    return output;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> output;
    for(int elem: s) {
        int lastDigit = elem % 10;
        if(output.count(lastDigit) != 1) {
            output[lastDigit] = set<int>();
        }
        output[lastDigit].insert(elem);
    }
    return output;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> output;
    for(char elem: str) {
        bool modified = false;
        for(pair<char, char> equivalences: tr) {
            if(!modified && equivalences.first == elem) {
                output.push_back(equivalences.second);
                modified = true;
            }
        }
        if(!modified) {
            output.push_back(elem);
        }

    }
    return output;
}

bool esInterseccionLUVacia(set<LU> a, set<LU> b) {
    for(LU elem: a) {
        if(std::count(b.begin(), b.end(), elem)) {
            return false;
        }
    }
    return true;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    for(Mail mail: s) {
        set<LU> integrantesMail1 = mail.libretas();
        for(Mail mail2: s) {
            if(!mail.operator==(mail2)) {
                set<LU> integrantesMail2 = mail2.libretas();
                if(!esInterseccionLUVacia(integrantesMail1, integrantesMail2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> output;
    for(Mail mail: s) {
        set<LU> libretas = mail.libretas();
        if(output.count(libretas) != 1) {
            output[libretas] = mail;
        }
        if(mail.adjunto()) {
            output[libretas] = mail;
        }
    }
  return output;
}
