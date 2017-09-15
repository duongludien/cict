giaithua(0,1).
giaithua(X,GT) :- K is X-1, giaithua(K,GT1), GT is X*GT1.
tong(0,0).
tong(X,S) :- K is X-1, tong(K,S1), S is S1 + X. 
