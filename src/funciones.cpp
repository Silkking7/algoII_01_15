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
    std::vector<int> v(s.begin(), s.end());
    return v;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    return true;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return true;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    return map<int, int>();
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    return vector<int>();
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    return set<int>();
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
