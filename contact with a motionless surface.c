% Projection onto horizontal plane
% Horizontal plane
gN = ygpi ;
ap = [0;0];

% Plane
gN = np(1)*(xgpi-x0(1)) +np(2)*(ygpi-x0(2));
ap=[0;0];

% Circle rigid
gN = ((xgpi - x0(1))^2 + (ygpi - x0(2))^2)^(0.5) - r;
np = [xgpi - x0(1);ygpi-x0(2)];
np = np/norm(np);
ap = [-np(2);np(1)];

% Contact Detection
if ns == 1 || eN < actsetTOL
  if gN < 0 && actset(i,ii) == false
  actset(i,ii) = true;
if jinfo ~= 0 ; fprintf('New Contact detected at %5i %5i \n',i,ii) ; end
elseif gN > 0 && actset(i,ii) == true
  actset(i,ii) = false ;
if jinfo ~= 0 ; fprintf('Prev. Contact lost at %5i %5i \n',i,ii) ; end
end
end

% Penalty Force and Stiffness
Fo = 0 ; dFo = 0 ;
if actset(i,ii) == 1
  Fo = -eps_N * gN ;
dFo = -eps_N ;
end

% Contact traction and associated gradient
Tc = Fo*np ;
dTc = dFo *(np*np') + Fo/(r+gN) *(ap*ap');

% FE Force Vector and Stiffness Matrix
rACi = rACi - Ni' * Tc * li5 * wi ;
kACii = kACii - wi*li5*(Ni'* dTc * Ni);

%Rigid body configuration in feinp1.m
% Define the rigid body properties

% Horizontal plane
np = [0;1];

% Plane
np = [-1;1];
x0 = [0;0];
np = np/norm(np);
x = [-1.5;1.5];
y = ( np(1)*x0(1) + np(2)*x0(2) - np(1)*x )./np(2);
plot(x,y,'k');

% Circle rigid
r = 0.5;
x0 = [0.3;-0.3];
x = linspace(x0(1)-r,x0(1)+r,100);
y = x0(2) + (r^(2) - (x - x0(1)).^(2)).^(.5);
plot(x,y,'k');
