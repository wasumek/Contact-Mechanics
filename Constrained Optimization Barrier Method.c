% Constrained Optimization: Barrier Method

clear all

% Unconstrained Stiffness, Load Vector
   K = [ 2 -1 0 ; -1 1 0 ; 0 0 2 ] ;
F = [ 1 ; 0 ; 0 ] ;

% Initial Contact Gap
do = 0.9 ;

% Barrier Parameter > 0
epsilon = 0.001 ;

% Initial Guess
u = [ 0 ; 0 ; 0 ] ;

% Newton-Raphson Iteration
TOL = 1e-10 ; err = 1 ; ns = 0 ;
while err > TOL

% Step
ns = ns + 1 ;
    
% Constraint (= Gap)
g = do - u(2) + u(3) ;
    
% Barrier Contribution
alpha = 2*epsilon/(g^3);
Fc = [0;epsilon/g^2; -epsilon/g^2];
Kc = [ 0 0 0 ; 0 alpha -alpha ; 0 -alpha alpha ] ;
    
% Residual
R = K*u + Fc - F ;
    
% Stiffness
dRdu = K + Kc ;
    
% Update
du = - inv(dRdu) * R ;
u  = u + du ;
    
% Error
err = norm(du) ;
    
end

% Steps, Displacement, Gap, Contact Force
  ns = ns
  u  = u
  g  = g
  Fc = Fc