% Calibration plot showing voltage reading vs actual distance

% Error plot showing predicted distance and actual distance for distances
% not included in calibration

% obj = serial(4);
% A = fscanf(obj);
% plot( A(:,1), A(:,2) );

data = load ('ir_distance.csv');
pan = data(:,2);
tilt = data(:,1);
ir = data(:,3);

% Creating fake time
time = zeros(5,1);


% Validating servo motion
% figure(1);
% clf;
% hold on;
% plot (pan, tilt);

% Validating ir distance reading
figure(2);
clf;
hold on;
plot (1:length(ir), ir);


conversion1 = 515*ones(1,length(ir));
d = -((ir-conversion1)/9);