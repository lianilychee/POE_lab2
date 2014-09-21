% This script is for the IR Sensor calibration.
% In order to scale the raw sensor reading to volts, divide the raw
% sensor reading by 200.
% Conversion is being done in MATLAB to conserve Arduino space.s

data = load('irSensor_calibration.csv');
sensor_out = data(:,1);
[length, columns] = size(sensor_out);
time = linspace(1,length,length);

clipped_out = sensor_out(600:2500);
[clipped_length, columns] = size(clipped_out);
clipped_time = linspace(1,clipped_length,clipped_length);

scaled_clipped = clipped_out/200;

v_th = 38.957*clipped_time.^(-0.887);

% figure(1);
% clf;
% hold on;
% % plot(time, sensor_out/200, 'r');
% % plot(clipped_time, clipped_out);
% plot(clipped_time, scaled_clipped, 'r');
% % plot(clipped_time, v_th);
% title('fake time/distance vs voltage');

dist = (38.957/scaled_clipped).^(1000/887);

figure(2);
clf;
hold on;
plot (dist, scaled_clipped);