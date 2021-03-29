from tensorflow import keras
import numpy as np
import subprocess
import tensorflow as tf
import os

model: keras.Sequential = keras.models.load_model("joint_acceleration_to_muscle_activation_network")
array = np.zeros(shape=(1, 4))
array[0][0] = 0  # x axis (forward/ back)
array[0][1] = 0  # y axis (rotate shoulder)
array[0][2] = 0  # z axis (up/down)
array[0][3] = 10   # elbow
#activations: tf.Tensor = model(array)
#numpy_activations: np.ndarray = activations.numpy()
#activation_list = str(numpy_activations[0])[1:-1]
#print(activation_list)

FNULL = open(os.devnull, 'w')  # use this if you want to suppress output to stdout from the subprocess
args = "../cmake-build-debug/playground/playground "
os.system(args)
