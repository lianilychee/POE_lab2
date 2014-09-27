% Calibration plot showing voltage reading vs actual distance

% Error plot showing predicted distance and actual distance for distances
% not included in calibration

% obj = serial(4);
% A = fscanf(obj);
% plot( A(:,1), A(:,2) );

data = load ('motor_motion.csv');
pan = data(:,2);
tilt = data(:,1);
ir = data(:,3);

% Validating servo motion
figure(1);
clf;
hold on;
plot (pan, tilt);