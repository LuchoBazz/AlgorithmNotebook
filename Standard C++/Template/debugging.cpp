#include <bits/stdc++.h>
using namespace std;
//------------------------------------

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// To String

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(const pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(const tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <size_t N>
string to_string(const bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template<typename K, typename V>
//string to_string(const map<K, V> mp) {
string to_string(const unordered_map<K, V> mp) {
    bool first = true;
    string res = "{";
    for (const auto &[k, v] : mp) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((K)k) + ": " + to_string((V)v);
    }
    res += "}";
    return res;
}

template<typename K>
//string to_string(const set<K> st) {
string to_string(const unordered_set<K> st) {
    bool first = true;
    string res = "{";
    for (const auto &k : st) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((K)k);
    }
    res += "}";
    return res;
}

template<typename T, size_t N>
string to_string(const array<T, N> arr) {
    bool first = true;
    string res = "{";
    for (const T &x :arr) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}

// add template here

template <typename T>
string to_string(const vector<T> &v) {
    bool first = true;
    string res = "{";
    for (const T &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}

// Print Line

template<class T>
void println(const T &data) {
#ifndef ONLINE_JUDGE
    cout << to_string((T)data) << endl;
#endif
}
