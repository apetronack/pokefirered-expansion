%% Experience Functions
function exp = slow(n)
    exp = 15/16 * n^3;
end

function exp = fast(n)
    exp = 3/5 * n^3;
end

function exp = medium_fast(n)
    exp = 3/4 * n^3;
end

function exp = medium_slow(n)
    exp = (9 * n^3) / 10 - (45 * n^2 / 4) + (75 * n) - 105;
end

function exp = erratic(n)
    if n <= 50
        exp = 3 * (100 - n) * n^3 /  200;
    elseif n <= 68
        exp = 3 * (150 - n) * n^3 / 400;
    elseif n<= 98
        exp = (1911 - 10 * n) * n^3 / 2000;
    else
        exp = 3 * (160 - n) * n^3 / 400;
    end
end

function exp = fluctuating(n)
    if n <= 15
        exp = (n + 73) * n^3 / 200;
    elseif n <= 36
        exp = 3 * (n + 14) * n^3 / 200;
    else
        exp = 3 * ((n / 2) + 32) * n^3 / 200;
    end
end

%% Main Comparison
level = 2:1:100;
slow_exp = zeros(1, length(level));
fast_exp = zeros(1, length(level));
medium_fast_exp = zeros(1, length(level));
medium_slow_exp = zeros(1, length(level));
erratic_exp = zeros(1, length(level));
fluctuating_exp = zeros(1, length(level));
exp_gain = zeros(1, length(level));

for i = 2:1:100
    slow_exp(i-1) = slow(i);
    fast_exp(i-1) = fast(i);
    medium_fast_exp(i-1) = medium_fast(i);
    medium_slow_exp(i-1) = medium_slow(i);
    erratic_exp(i-1) = erratic(i);
    fluctuating_exp(i-1) = fluctuating(i);
    if i <= 20
        yield = 75;
    elseif i <= 40
        yield = 150;
    else
        yield = 215;
    end
    exp_gain(i-1) = 1.5 * yield * i / 7;
end

figure;
hold on;
plot(level, slow_exp, 'r');
plot(level, fast_exp, 'b');
plot(level, medium_fast_exp, 'k');
plot(level, medium_slow_exp, 'o');
plot(level, erratic_exp, 'm');
plot(level, fluctuating_exp, 'g');
legend('Slow', 'Fast', 'Medium Fast', 'Medium Slow', 'Erratic', 'Fluctuating');
xlabel('Level');
ylabel('Exp');

num_mons_slow = slow_exp ./ exp_gain;
num_mons_fast = fast_exp ./ exp_gain;
num_mons_medium_fast = medium_fast_exp ./ exp_gain;
num_mons_medium_slow = medium_slow_exp ./ exp_gain;
num_mons_erratic = erratic_exp ./ exp_gain;
num_mons_fluctuating = fluctuating_exp ./ exp_gain;

figure;
hold on;
plot(level, num_mons_slow, 'r');
plot(level, num_mons_fast, 'b');
plot(level, num_mons_medium_fast, 'k');
plot(level, num_mons_medium_slow, 'o');
plot(level, num_mons_erratic, 'm');
plot(level, num_mons_fluctuating, 'g');
legend('Slow', 'Fast', 'Medium Fast', 'Medium Slow', 'Erratic', 'Fluctuating');
xlabel('Level');
ylabel('Est. Num Mons');

figure;
hold on;
plot(level, slow_exp./level.^3, 'r');
plot(level, fast_exp./level.^3, 'b');
plot(level, medium_fast_exp./level.^3, 'k');
plot(level, medium_slow_exp./level.^3, 'o');
plot(level, erratic_exp./level.^3, 'm');
plot(level, fluctuating_exp./level.^3, 'g');
legend('Slow', 'Fast', 'Medium Fast', 'Medium Slow', 'Erratic', 'Fluctuating');
xlabel('Level');
ylabel('Exp');