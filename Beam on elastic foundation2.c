clear all;
clc;
syms c1 c2 c3 c4 x L l w0 

% Calculate all the differentiations
w(x,c1,c2,c3,c4,L) = (c1*cos(x/L)+c2*sin(x/L))*exp(-x/L) + ...
  (c3*cos(x/L)+c4*sin(x/L))*exp(x/L);
a(x,c1,c2,c3,c4,L) = diff(w,x); 
b(x,c1,c2,c3,c4,L) = diff(a,x); 
c(x,c1,c2,c3,c4,L) = diff(b,x); 

% evaluate the B.C.
% simplify(w(0,c1,c2,c3,c4,L))
  % simplify(a(0,c1,c2,c3,c4,L))
  % simplify(b(l,c1,c2,c3,c4,L))
  % simplify(c(l,c1,c2,c3,c4,L))
 
  E1 = w(0,c1,c2,c3,c4,L) == w0;
E2 = a(0,c1,c2,c3,c4,L) == 0;
E3 = b(l,c1,c2,c3,c4,L) == 0;
E4 = c(l,c1,c2,c3,c4,L) == 0;
 
[Mat,V] = equationsToMatrix([E1,E2,E3,E4],[c1,c2,c3,c4]);
% Find all constants
C=linsolve(Mat,V);
 
% Plot
x = linspace(-1,1,50);
plot(x,subs(w(x,C(1),C(2),C(3),C(4),L),[L,l,w0],[0.7,1,1]))
%  plot(x,subs(w(x,C(1),C(2),C(3),C(4),L),[L,l,w0],[0.3,1,1]))
%  plot(x,subs(w(x,C(1),C(2),C(3),C(4),L),[L,l,w0],[0.1,1,1]))

