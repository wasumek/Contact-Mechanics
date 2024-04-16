% Constrained Optimization: Augmented Lagrange Multiplier Method

clear all, clc

   % Unconstrained Stiffness, Load Vector
   K = [ 2 -1 0 ; -1 1 0 ; 0 0 2 ] ;
F = [ 1 ; 0 ; 0 ] ;

% Initial Contact Gap
do = 0.90 ;

% Penalty Parameter
epsilon = 0.001 ;

% Penalty Stiffness
Kc = [ 0 0 0 ; 0 1 -1 ; 0 -1 1 ] ;

% Initial Guess
lam = 0 ;

% Uszawa Algorithm
TOL = 1e-6 ; err = 1 ; ns = 0 ;
while err > TOL

% Step
ns = ns + 1 ;
    
% Force Contribution
Fo = [0; (-lam+epsilon*do); (lam-epsilon*do)] ;
    
% Solve
u = (K+Kc) \ (F+Fo) ;
    
% Constraint (= Penetration)
c = u(2) - u(3) - do ;
    
% Update (Usuzawa applied)
lam = lam + epsilon*c ;
    
% Error
err = norm(c) ;
    
end

% Steps, Displacement, Gap, Contact Force
  ns  = ns
  u   = u
  g   = -c
  lam = lam