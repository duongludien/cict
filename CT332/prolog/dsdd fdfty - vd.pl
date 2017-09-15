/* Tính toán
Prolog sử dụng biến để trả về kết quả
a)	Ví dụ 1 tìm số lớn của đối số 1 với đối số 2, kết quả trả về đối số 3
Tri thức
solon(A,B, A):-A>B.
solon(A,B,B):-A=<B.
Truy vấn
solon(6,4,X).
b)	Ví dụ 2 tính tổng N số nguyên
Tri thức
tong(0,0).
tong(N,X):-N1 is N-1,tong(N1,K),X is K+N.
Truy vấn
tong (10,X).
Ví dụ 3 Xen phần tử vào danh sách
%[] là danh sách rỗng

Tri thức
1.	insert(A,B,[A|B]).
2.	hoặc 
3.	insert(A,B,[B|A]).
Truy vấn
4.	insert(3,[5,2,46],X).
%[] là danh sách rỗng
c)	Xóa phần tử  
Tri thức
5.	delete([A|B],B).
6.	hoặc 
7.	delete([A|B],A).
Truy vấn
8.	insert(3,[5,2,46],
d)	Kiểm tra xem có tồn tại phần tử X trong danh sách hay không ?
Tri thức
9.	timthay(X,[A|_]):-X=A.
10.	timthay((X,[_|B]):-timthay(X,B).
Truy vấn
11.	timthay(1,[3,5,2]).
*/
%tong cua N so dau tin.
tong(0,0).
tong(N,X):-N1 is N-1,tong(N1,K),X is K+N.
hanoi(1,A,B,C) :-  
        write(' Chuyen Tu '), 
        write(A), 
        write(' Sang '), 
        write(B), nl. 
    hanoi(N,A,B,C) :- N>1, M is N-1, hanoi(M,A,C,B), hanoi(1,A,B,C), hanoi(M,C,B,A).
