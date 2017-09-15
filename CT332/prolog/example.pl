father(peter, marry).
mother(sue, john).
mother(sue, marry).
parent(X,Y) :- father(X,Y).
parent(X,Y) :- mother(X,Y).
sibling(X,Y) :- parent(Z,X),parent(Z,Y).