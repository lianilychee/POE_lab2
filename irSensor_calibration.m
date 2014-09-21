data = load('irSensor_calibration.csv');
sensor_out = data(:,1);
[length, columns] = size(sensor_out);
time = linspace(1,length,length);

clipped_out = sensor_out(600:2500);
[clipped_length, columns] = size(clipped_out);
clipped_time = linspace(1,clipped_length,clipped_length);

figure(1);
clf;
hold on;
% plot(time, sensor_out, 'r');
plot(clipped_time, clipped_out);
axis([0 2000 0 700]);