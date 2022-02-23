clc; clear variables; close all;

DATA = readmatrix("Sweep_Freq.txt");
F = DATA(1:3:end, 4);
T = DATA(2:3:end, 3);
E = DATA(3:3:end, 2);
Limit = 20*ones(1,length(F));

plot(F,T/1e6, F,Limit, 'Linewidth',2)
xlabel("Frequency Divider") 
grid on
ylabel("Time [ms]")

yyaxis right
plot(F, E/1e6, 'Linewidth', 2)
ylabel("Energy [microJoule]")

legend(["Total time of execution" "Application time limit" "Total Energy of the system"])
% rough estimation of reasonable value of IS AND DS divider
%% 
clc; clear variables; close all;
DATA =  readmatrix("Sweep_Data_Cache_Size.txt");
E = [];
start = 2; stop = 20;
for k = 0:3
    E(k+1, :) = DATA(start:3:stop, 2);
    start = start + 22;
    stop = stop + 22;
    
end

DS = 8:14;

plot(   DS, E(1,:)/1e6, ... 
        DS, E(2,:)/1e6, ... 
        DS, E(3,:)/1e6, ... 
        DS, E(4,:)/1e6, 'Linewidth', 2)
grid on, xlabel("log2(Data Cache Size)")
ylabel("Energy [microJoule]")
legend(["IS = 8" "IS = 10" "IS = 12" "IS = 14"])
         