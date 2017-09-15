man(marcus).
pompeian(marcus).
ruler(ceasar).
tryAssassinate(marcus, ceasar).
roman(X) :- pompeian(X).
loyalTo(X, ceasar) :- roman(X),not(tryAssassinate(X,ceasar)).
hate(X, ceasar) :- roman(X),not(loyalTo(X,ceasar)).
person(X) :- man(X).
loyalTo(X,_) :- person(X).
tryAssassinate(X,Y) :- not(loyalTo(X, Y)),person(X),ruler(Y).