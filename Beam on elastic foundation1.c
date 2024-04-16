clear all;
clc;
% Grid 
dx = 1/20 ; xend = 4 ;
dz = 1/20 ; zend = 4 ;

% assign value
a = 1;
x = 0;
h = 0.4;
g = h/2;
xbar = x + a/2;
xhat = x - a/2;
nu = 0.2;
epsilon = 1E-8;

% case a
p0 = 1; t0 = 0;
% case b
%p0 = 0; t0 = 1;

% Loop over x
k=0;
for x=0:dx:xend
	k = k+1;
% Loop over z
l = 0; 
for z=0:dz:zend
        l = l+1;
if z == 0
            
  if abs(x)< a
  pressure = p0*((exp(-1*x.^2/h.^2))-(exp(-1*xbar.^2/g.^2))-(exp(-1*xhat.^2/g.^2)));
  else
    pressure = 0;
end
            
            
if abs(x) < a
t = t0.*pressure/p0;
 else
   t = 0;
end
t_int = integral(@(s) -2/pi.*t./(x-s),-a,x-epsilon)...
  +integral(@(s) -2/pi.*t./(x-s),x+epsilon,a);
            
sig_x(k,1) = -pressure + t_int;
sig_y(k,1) = -2*nu*pressure - 2*nu./pi.*t_int;
sig_z(k,1) = -pressure;
t_xz(k,1)  = -t;
 else
   p_under=@(s) p0.*((exp(-1*s.^2/h.^2))-(exp(-1*xbar.^2/g.^2))-(exp(-1*xhat.^2/g.^2)));
t_after=@(s) t0 *((exp(-1*s.^2/h.^2))-(exp(-1*xbar.^2/g.^2))-(exp(-1*xhat.^2/g.^2)));
                
sigxint=@(s) (-2*z/pi).* p_under(s).*((x-s).^2./((x-s).^2+z.^2).^2)...
  -2/pi*t_after(s).*((x-s).^3./((x-s).^2+z.^2).^2);
		  sig_x(k,l)=integral(sigxint,-a,a);
sig_z_int=@(s) (-2*z.^3/pi).* p_under(s).*(1./((x-s).^2+z.^2).^2)...
  -2.*z.^2./pi*t_after(s).*((x-s)./((x-s).^2+z.^2).^2);
			 sig_z(k,l)=integral(sig_z_int,-a,a);
sig_y(k,l)=nu.*(sig_x(k,l)+sig_z(k,l));
                
t_xz_int=@(s) (-2*z.^2/pi).* p_under(s).* ((x-s)./((x-s).^2+z.^2).^2)...
  -2.*z./pi*t_after(s).*((x-s).^2./((x-s).^2+z.^2).^2);
		      t_xz(k,l)=integral(t_xz_int,-a,a);
end
sig_1(k,l)=(sig_x(k,l)+sig_z(k,l))./2+sqrt(((sig_x(k,l)-sig_z(k,l))./2).^2+t_xz(k,l).^2);      
sig_2(k,l)=(sig_x(k,l)+sig_z(k,l))./2-sqrt(((sig_x(k,l)-sig_z(k,l))./2).^2+t_xz(k,l).^2);
sig_3(k,l)=nu*(sig_1(k,l) + sig_2(k,l));
            
t_12(k,l) = abs((sig_1(k,l) - sig_2(k,l))./2);
t_23(k,l) = abs((sig_2(k,l) - sig_3(k,l))./2);
t_31(k,l) = abs((sig_3(k,l) - sig_1(k,l))./2);
end
end 


% Plotting
x = 0:dx:xend ; z = 0:dz:zend ;
axe = [-a a -a a] ; fs = 14 ;

figure(1);
pcolor(x,-z,sig_x'); hold on
pcolor(-x,-z,sig_x');
axis equal
axis(axe)

     % frame the plot
     min=min(min(sig_x));
max=max(max(sig_x));
caxis([min max])

xlabel('x/a','fontsize',fs)
ylabel('z/a','fontsize',fs)
title('Stress Field  \sigma_x/(Pa)','fontsize',fs)
set(gca,'fontsize',fs)
colorbar ; set(colorbar,'fontsize',fs)
colormap jet
shading interp
