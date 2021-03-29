from tensorflow import keras
import numpy as np
import subprocess
import tensorflow as tf
import os

model: keras.Sequential = keras.models.load_model("joint_acceleration_to_muscle_activation_network")
array = np.zeros(shape=(1, 5))
array[0][0] = 3.313556909561157227e-01  # x axis (forward/ back)
array[0][1] = 6.252577900886535645e-01  # y axis (rotate shoulder)
array[0][2] = 1.800971925258636475e-01 # z axis (up/down)
array[0][3] = 2.575280368328094482e-01  # elbow
array[0][4] = 1.538788527250289917e-01
activations: tf.Tensor = model(array)
numpy_activations: np.ndarray = activations.numpy()
print(numpy_activations)
