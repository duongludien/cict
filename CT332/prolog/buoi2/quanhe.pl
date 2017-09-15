anh(an, binh).
nam(an).
vo(yen, an).
nu(yen).
chong(binh, hoa).
nam(binh).
nu(hoa).
me(hoa, khang).
emgai(khang, thinh).
nu(khang).
emtrai(thinh, cuong).
nam(thinh).
contrai(cuong, binh).
nam(cuong).
congai(lanh, an).
nu(lanh).
chi(lanh, dung).
nu(lanh).
emgai(hanh, dung).
nu(hanh).
emgai(hanh, lanh).
congai(dung, yen).
nu(dung).

/* ========== Cac quan he them vao ============= */

/* Quan he duoc suy ra tu anh */
emtrai(X, Y) :- anh(Y, X), nam(X).
emgai(X, Y) :- anh(Y, X), nu(X).

/* Quan he duoc suy ra tu vo */
chong(X, Y) :- vo(Y, X).

/* Quan he duoc suy ra tu chi */
emgai(X, Y) :- chi(Y, X), nu(X).
emtrai(X, Y) :- chi(Y, X), nam(X).

/* Quan he duoc suy ra tu cha */
contrai(X, Y) :- cha(Y, X), nam(X).
congai(X, Y) :- cha(Y, X), nu(X).

/* Quan he duoc suy ra tu me */
contrai(X, Y) :- me(Y, X), nam(X).
congai(X, Y) :- me(Y, X), nu(X).

/* Quan he duoc suy ra tu emgai */
anh(X, Y) :- emgai(Y, X), nam(X).
chi(X, Y) :- emgai(Y, X), nu(X).

/* Quan he duoc suy ra tu emtrai */
anh(X, Y) :- emtrai(Y, X), nam(X).
chi(X, Y) :- emtrai(Y, X), nu(X).

/* Quan he duoc suy ra tu contrai */
me(X, Y) :- contrai(Y, X), nu(X).
cha(X, Y) :- contrai(Y, X), nam(X).

/* Quan he duoc suy ra tu congai */
me(X, Y) :- congai(Y, X), nu(X).
cha(X, Y) :- congai(Y, X), nam(X).

/* Quan he duoc suy ra tu chi */
emtrai(X, Y) :- chi(Y, X), nam(X).
emgai(X, Y) :- chi(Y, X), nu(X).

/* Quan he duoc suy ra tu cha & me */
contrai(X, Y) :- contrai(X, Z), vo(Z, Y).
congai(X, Y) :- congai(X, Z), vo(Z, Y).

/* ============================================= */

bactrai(X, Y) :- anh(X, Z), cha(Z, Y).
chu(X, Y) :- emtrai(X, Z), cha(Z, Y).
co(X, Y) :- emgai(X, Z), cha(Z, Y).
anhchiemruot(X, Y) :- cha(Z, X), cha(Z, Y), me(T, X), me(T, Y).
anhho(X, Y) :- bac(Z, Y), cha(Z, X).
chiho(X, Y) :- bac(Z, Y), cha(Z, X).