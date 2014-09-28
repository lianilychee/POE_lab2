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

% % Validating servo motion
% figure(1);
% clf;
% hold on;
% plot (pan, tilt);

% % Validating ir distance reading
% figure(2);
% clf;
% hold on;
% plot (1:length(dist), dist);

% IR conversion
conversion1 = 515*ones(length(ir),1);
dist = -((ir-conversion1)/9); % Convert IR mV reading to cm

% Tilt conversion
y = zeros(length(tilt),1);
for i = 1:length(tilt);
    if tilt(i) == 90;
        y(i) = 12.207;
    end
    if tilt(i) < 90;
        y(i) = 12.207 - (12.207*sin(tilt(i)));
    end
    if tilt(i) > 90;
        y(i) = 12.207 + (12.207*sin(tilt(i)));
    end
end

% Pan conversion
x = zeros(length(pan),1);
for i = 1:5;
    pan(i)
    if pan(i) == 90;
        x(i) = 0;
        x(i)
    end
    if pan(i) > 90;
        x(i) = sin(pan(i)) * cos(tilt(i)) * dist(i);
        x(i)
    end
    if pan < 90;
        x(i) = -sin(pan(i)) * cos(tilt(i)) * dist(i);
        x(i)
    end
end

% Plot the damn thing
% plot3(x,y,dist);
% xlabel('xlabel');
% ylabel('ylabel');
% zlabel('zlabel');