% Calibration plot showing voltage reading vs actual distance

% Error plot showing predicted distance and actual distance for distances
% not included in calibration

obj = serial(4);
A = fscanf(obj);
plot( A(:,1), A(:,2) );