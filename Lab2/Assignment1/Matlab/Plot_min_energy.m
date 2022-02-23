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

%% 
clc; clear variables; close all;
DATA =  readmatrix("Sweep_Cache_Sizes.txt");
E = DATA(2:4:end, 2)./1e6; %from PicoJoule to MicroJoule
M = reshape(E, [7,7])';


DS = 8:14;
plot(   DS, M(1,:), ... 
        DS, M(2,:), ... 
        DS, M(3,:), ... 
        DS, M(4,:), ... 
        DS, M(5,:), ... 
        DS, M(6,:), ... 
        DS, M(7,:), ... 
             'Linewidth', 2)
grid on, xlabel("DS = log2(Data Cache Size)")
ylabel("Energy [microJoule]")
legend(["IS = 8" "IS = 9" "IS = 10" "IS = 11" "IS = 12" "IS = 13" "IS = 14" ])
        
%%
clc; clear variables; close all;
DATA =  readmatrix("Sweep_Associativy.txt");
E = DATA(2:4:end, 2)./1e6; %from PicoJoule to MicroJoule
M = reshape(E, [4,4])'; %rows are increasing IT

DTIT = 2.^(0:3);
plot(DTIT, M(1, :), '-x',...
    DTIT, M(2, :),'-x', ...
    DTIT, M(3, :), '-x',...
    DTIT, M(4, :),'-x', 'LineWidth', 2)
grid on, xlabel("Data Cache Associativity (DT)")
ylabel("Energy [microJoule]")
legend(["IT = 1" "IT = 2" "IT = 4" "IT = 8"])
title("Data and Instruction Associativity (DT and IT)")