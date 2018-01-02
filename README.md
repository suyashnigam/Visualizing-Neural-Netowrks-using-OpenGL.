# Number-Predictor-using-OpenGL

This repository contains the code for the Number Predictor Application. 
The user draws a number using the mouse in the space provided as shown below and clicks on 'GO'. The network then forward propogates the image into a 6-layered CNN (Conv-Max-ReLU - Conv-Max-ReLU - Conv-ReLU - FC - Classification) and predicts the number. 

The activation maps of some of the Convolutional Layers are also visualized. The intensity of the black color in the final classification layer is directly proportional to the probability of that particular number.

![Screenshot](https://user-images.githubusercontent.com/32497274/34503345-c304327e-efe5-11e7-87bc-0346c0df6b6d.PNG)

The network was trained in MATLAB, the weights extracted and then used for classifying the user-drawn number.

To run the code, please download all the files and extract the zipped folder "Weights.rar" and run the application file "Predict_number.exe".
