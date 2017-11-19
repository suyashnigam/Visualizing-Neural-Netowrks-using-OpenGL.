%% Load Data

digitDatasetPath = fullfile(matlabroot,'toolbox','nnet','nndemos',...
    'nndatasets','DigitDataset');
digitData = imageDatastore(digitDatasetPath,...
    'IncludeSubfolders',true,'LabelSource','foldernames');

%% Count labels
labelCount = countEachLabel(digitData)

%% Declare training size

trainNumFiles = 750;
[trainDigitData,valDigitData] = splitEachLabel(digitData,trainNumFiles,'randomize');

%% Define Architecture

layers = [
    imageInputLayer([28 28 1])

    convolution2dLayer(3,16,'Padding',1)
    batchNormalizationLayer
    reluLayer

    maxPooling2dLayer(2,'Stride',2)

    convolution2dLayer(3,32,'Padding',1)
    batchNormalizationLayer
    reluLayer

    maxPooling2dLayer(2,'Stride',2)

    convolution2dLayer(3,64,'Padding',1)
    batchNormalizationLayer
    reluLayer

    fullyConnectedLayer(10)
    softmaxLayer
    classificationLayer];

%% Define Optimization parameters

options = trainingOptions('sgdm',...
    'MaxEpochs',3, ...
    'ValidationData',valDigitData,...
    'ValidationFrequency',30,...
    'Verbose',false,...
    'Plots','training-progress');

%% Train

net = trainNetwork(trainDigitData,layers,options);

%% Get Accuracy

predictedLabels = classify(net,valDigitData);
valLabels = valDigitData.Labels;

accuracy = sum(predictedLabels == valLabels)/numel(valLabels)



